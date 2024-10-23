// Fill out your copyright notice in the Description page of Project Settings.


#include "BLEActor.h"

static ABLEActor* singleton = NULL;

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEConnected(JNIEnv * env, jobject classObj, jboolean connected)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		singleton->connectionStatus = false;
		singleton->BLE_OnConnection_TriggerEvent(connected);
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
		FString ble_address = FString::Printf(TEXT("BLE Device Address: %s"), *deviceAddressStr);
		singleton->BLE_DeviceAddress_TriggerEvent(ble_address);
	}
#endif
}

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEReturnIntensity(JNIEnv * env, jobject classObj, jint intensity)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		singleton->BLE_Intensity_TriggerEvent(intensity);
	}
#endif
}

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEReturnEndurance(JNIEnv * env, jobject classObj, jint endurance)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		singleton->BLE_Endurance_TriggerEvent(endurance);

	}
#endif
}

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEReturnLeftBalance(JNIEnv * env, jobject classObj, jint leftBalance)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		singleton->BLE_LeftBalance_TriggerEvent(leftBalance);

	}
#endif
}

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEReturnRightBalance(JNIEnv * env, jobject classObj, jint rightBalance)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		singleton->BLE_RightBalance_TriggerEvent(rightBalance);
	}
#endif
}

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEReturnMaxLeft(JNIEnv * env, jobject classObj, jint maxLeft)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		singleton->BLE_LeftMax_TriggerEvent(maxLeft);
	}
#endif
}

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEReturnMaxRight(JNIEnv * env, jobject classObj, jint maxRight)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		singleton->BLE_RightMax_TriggerEvent(maxRight);
	}
#endif
}

#endif

// Sets default values
ABLEActor::ABLEActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	singleton = this;
	singleton->connectionStatus = false;
}


ABLEActor::~ABLEActor() {
	singleton = NULL;
}


// Called when the game starts or when spawned
void ABLEActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABLEActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



bool ABLEActor::ExploreBLE_ConnectBLE() {
#if PLATFORM_ANDROID
	if (!singleton->connectionStatus) {
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
		{
			static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Java_ConnectToBLEService", "()Z", false);
			jboolean bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);

			if (bResult == true) {
				singleton->connectionStatus = true;
				return true;
			}
			else {
				singleton->connectionStatus = false;
				return false;
			}
		}
}
#endif
	return false;
}


void ABLEActor::ExploreBLE_ShowToast(const FString& Content)
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

<<<<<<< HEAD

void ABLEActor::ExploreBLE_SendRecentreFeetPosition()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "sendRecentreCharacteristic", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}



=======
>>>>>>> 18dbbb0cfcc05306ec6cf515d74aaaf331afb389
void ABLEActor::BLE_OnConnection_TriggerEvent(bool ConnectionValue) {
	OnConnected.Broadcast(ConnectionValue);
}


void ABLEActor::BLE_DeviceAddress_TriggerEvent(FString DeviceAddressValue) {
	OnDeviceAddress.Broadcast(DeviceAddressValue);
}

void ABLEActor::BLE_Intensity_TriggerEvent(int32 Intensity) {
	OnIntensity.Broadcast(Intensity);
}


void ABLEActor::BLE_Endurance_TriggerEvent(int32 Endurance) {
	OnEndurance.Broadcast(Endurance);
}

void ABLEActor::BLE_RightBalance_TriggerEvent(int32 RightBalanceValue) {
	OnRightBalance.Broadcast(RightBalanceValue);
}

void ABLEActor::BLE_LeftBalance_TriggerEvent(int32 LeftBalanceValue) {
	OnLeftBalance.Broadcast(LeftBalanceValue);
}

void ABLEActor::BLE_LeftRightBalance_TriggerEvent(const TArray<int32>& LeftRightBalanceValue) {
	OnLeftRightBalance.Broadcast(LeftRightBalanceValue);
}

void ABLEActor::BLE_RightMax_TriggerEvent(int32 RightMaxValue) {
	OnRightMax.Broadcast(RightMaxValue);
}

void ABLEActor::BLE_LeftMax_TriggerEvent(int32 LeftMaxValue) {
	OnLeftMax.Broadcast(LeftMaxValue);
}