// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExploreBLE.h"

#define LOCTEXT_NAMESPACE "FExploreBLEModule"

void FExploreBLEModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FExploreBLEModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

#if PLATFORM_ANDROID
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        jmethodID DisconnectMethod = FJavaWrapper::FindMethod(
            Env,
            FJavaWrapper::GameActivityClassID,
            "Java_BLEDisconnect",
            "()V",
            false
        );
        if (DisconnectMethod != nullptr)
        {
            FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, DisconnectMethod);
            UE_LOG(LogTemp, Log, TEXT("BLE: Java_BLEDisconnect called from ShutdownModule"));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("BLE: Could not find Java_BLEDisconnect method"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("BLE: Could not get JNIEnv in ShutdownModule"));
    }
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FExploreBLEModule, ExploreBLE)