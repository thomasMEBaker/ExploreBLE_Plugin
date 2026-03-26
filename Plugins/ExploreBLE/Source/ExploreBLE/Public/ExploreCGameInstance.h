// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ExploreCGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class EXPLOREBLE_API UExploreCGameInstance : public UGameInstance
{
	GENERATED_BODY()

	public:
		virtual void Shutdown() override;
	
};
