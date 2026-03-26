// Fill out your copyright notice in the Description page of Project Settings.


#include "ExploreCGameInstance.h"

void UExploreCGameInstance::Shutdown()
{
    UE_LOG(LogTemp, Warning, TEXT("BLE: GameInstance Shutdown fired"));
    Super::Shutdown();
}