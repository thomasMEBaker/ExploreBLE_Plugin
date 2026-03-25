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

extern "C" JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_nativeBLEReturnFeetData(JNIEnv * env, jobject classObj, jstring intensity,jstring endurance,jstring extension_left_value, jstring flexion_left_value,jstring extension_right_value, jstring flexion_right_value, jstring balance_value, jstring split_time,jstring distance)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		TArray<FString> Char_Array;
		jboolean isCopy;
		const char* convertedIntensity = (env)->GetStringUTFChars(intensity, &isCopy);
		const char* convertedEndurance = (env)->GetStringUTFChars(endurance, &isCopy);
		const char* convertedExtension_left = (env)->GetStringUTFChars(extension_left_value, &isCopy);
		const char* convertedFlexion_left = (env)->GetStringUTFChars(flexion_left_value, &isCopy);
		const char* convertedExtension_right = (env)->GetStringUTFChars(extension_right_value, &isCopy);
		const char* convertedFlexion_right = (env)->GetStringUTFChars(flexion_right_value, &isCopy);
		const char* convertedBalance = (env)->GetStringUTFChars(balance_value, &isCopy);
		const char* convertedSplitTime = (env)->GetStringUTFChars(split_time, &isCopy);
		const char* convertedDistance = (env)->GetStringUTFChars(distance, &isCopy);


		std::string intensity_stdStr = convertedIntensity;
		std::string endurance_stdStr = convertedEndurance;
		std::string extension_left_stdStr = convertedExtension_left;
		std::string flexion_left_stdStr = convertedFlexion_left;
		std::string extension_right_stdStr = convertedExtension_right;
		std::string flexion_right_stdStr = convertedFlexion_right;
		std::string left_right_balance_stdStr = convertedBalance;
		std::string split_time_stdStr = convertedSplitTime;
		std::string distance_stdStr = convertedDistance;


		env->ReleaseStringUTFChars(intensity, convertedIntensity);
		env->ReleaseStringUTFChars(endurance, convertedEndurance);
		env->ReleaseStringUTFChars(extension_left_value, convertedExtension_left);
		env->ReleaseStringUTFChars(flexion_left_value, convertedFlexion_left);
		env->ReleaseStringUTFChars(extension_right_value, convertedExtension_right);
		env->ReleaseStringUTFChars(flexion_right_value, convertedFlexion_right);
		env->ReleaseStringUTFChars(balance_value, convertedBalance);
		env->ReleaseStringUTFChars(split_time, convertedSplitTime);
		env->ReleaseStringUTFChars(distance, convertedDistance);
		

		FString intensityStr = UTF8_TO_TCHAR(intensity_stdStr.c_str());
		FString enduranceStr = UTF8_TO_TCHAR(endurance_stdStr.c_str());
		FString extensionLeftStr = UTF8_TO_TCHAR(extension_left_stdStr.c_str());
		FString flexionLeftStr = UTF8_TO_TCHAR(flexion_left_stdStr.c_str());
		FString extensionRightStr = UTF8_TO_TCHAR(extension_right_stdStr.c_str());
		FString flexionRightStr = UTF8_TO_TCHAR(flexion_right_stdStr.c_str());
		FString leftRightBalanceStr = UTF8_TO_TCHAR(left_right_balance_stdStr.c_str());
		FString splitTimeStr = UTF8_TO_TCHAR(split_time_stdStr.c_str());
		FString distanceStr = UTF8_TO_TCHAR(distance_stdStr.c_str());


				if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, intensityStr);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, enduranceStr);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, extensionLeftStr);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, flexionLeftStr);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, extensionRightStr);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, flexionRightStr);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, leftRightBalanceStr);
		}
		

		Char_Array.Add(intensityStr);
		Char_Array.Add(enduranceStr);
		Char_Array.Add(extensionLeftStr);
		Char_Array.Add(flexionLeftStr);
		Char_Array.Add(extensionRightStr);
		Char_Array.Add(flexionRightStr);
		Char_Array.Add(leftRightBalanceStr);
		Char_Array.Add(splitTimeStr);
		Char_Array.Add(distanceStr);

		singleton->BLE_Characteristics_TriggerEvent(Char_Array);

		Char_Array.Empty();
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

void ABLEActor::ExploreBLE_SendRecentreFeetPosition()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Java_SendCentre", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}



void ABLEActor::ExploreBLE_SendResetBoard()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Java_SendReset", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}


void ABLEActor::BLE_OnConnection_TriggerEvent(bool ConnectionValue) {
	OnConnected.Broadcast(ConnectionValue);
}


void ABLEActor::BLE_DeviceAddress_TriggerEvent(FString DeviceAddressValue) {
	OnDeviceAddress.Broadcast(DeviceAddressValue);
}

void ABLEActor::BLE_Characteristics_TriggerEvent(const TArray<FString>& Characteristics) {
	OnCharacteristicsReceived.Broadcast(Characteristics);
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "BLE_Characteristics_TriggerEvent");
		for (const FString& Characteristic : Characteristics)
		{
			GEngine->AddOnScreenDebugMessage(
				-1, 
				5.0f, 
				FColor::Green,
				Characteristic
			);
		}
	}
	
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