// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExploreBLEBPLibrary.h"
#include "ExploreBLE.h"

static UExploreBLEBPLibrary* singleton = NULL;

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEConnected(JNIEnv * env, jobject classObj, jboolean connected)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		singleton->bleConnected = connected;
		FString test = FString::Printf(TEXT("BLE Connected: %s"), connected ? TEXT("true") : TEXT("false"));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, test);
	}
#endif
}

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEReturnDeviceAddress(JNIEnv * env, jobject classObj, jstring device_address)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jboolean isCopy;
		const char* convertedValue = (env)->GetStringUTFChars(device_address, &isCopy);
		std::string stdStr = convertedValue;
		env->ReleaseStringUTFChars(device_address, convertedValue);
		FString deviceAddressStr = UTF8_TO_TCHAR(stdStr.c_str());
		singleton->bleDeviceAddress = deviceAddressStr;

		FString test = FString::Printf(TEXT("BLE Device Address: %s"), *deviceAddressStr);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, test);
	}
#endif
}

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEReturnIntensity(JNIEnv * env, jobject classObj, jint intensity)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		singleton->bleIntensity = intensity;
	}
#endif
}

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEReturnEndurance(JNIEnv * env, jobject classObj, jint endurance)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		singleton->bleEndurance = endurance;
	}
#endif
}

#endif

UExploreBLEBPLibrary::UExploreBLEBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	singleton = this;
}


UExploreBLEBPLibrary::~UExploreBLEBPLibrary()
{
	singleton = NULL;
}


bool UExploreBLEBPLibrary::ExploreBLE_getBleConnectionStatus() {
	return singleton->bleConnected;
}


FString UExploreBLEBPLibrary::ExploreBLE_getBleDeviceAddress() {
	return singleton->bleDeviceAddress;
}

int UExploreBLEBPLibrary::ExploreBLE_getBLE_intensity() {
	return singleton->bleIntensity;
}

int UExploreBLEBPLibrary::ExploreBLE_getBLE_endurance() {
	return singleton->bleEndurance;
}

int UExploreBLEBPLibrary::ExploreBLE_getBLE_LeftBalance() {
	return singleton->bleLeftBalance;
}

int UExploreBLEBPLibrary::ExploreBLE_getBLE_RightBalance() {
	return singleton->bleRightBalance;
}

int UExploreBLEBPLibrary::ExploreBLE_getBLE_MaxExtensionLeft() {
	return singleton->bleExtensionLeft;
}

int UExploreBLEBPLibrary::ExploreBLE_getBLE_MaxExtensionRight() {
	return singleton->bleExtensionRight;
}

bool UExploreBLEBPLibrary::ExploreBLE_ConnectBLE() {
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Java_ConnectToBLEService", "()Z", false);
		jboolean bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);

		if (bResult == true) {
			return true;
		}else {
			return false;
		}
	}
#endif
	return false;
}


void UExploreBLEBPLibrary::ExploreBLE_ShowToast(const FString& Content)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring JavaString = Env->NewStringUTF(TCHAR_TO_UTF8(*Content));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Java_ShowToast", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, JavaString);
	}
#endif
}

