// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BLEActor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConnectionEvent, bool, ConnectionValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeviceAddressEvent, FString, DeviceAddressValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIntensityEvent, int32, IntensityValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnduranceEvent, int32, EndruanceValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeftRightBalanceEvent, const TArray<int32>&, LeftRightBalanceValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRightBalanceEvent, int32, RightBalanceValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeftBalanceEvent, int32, LeftBalanceValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRightMaxEvent, int32, RightMaxValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLeftMaxEvent, int32, LeftMaxValue);


UCLASS()
class EXPLOREBLE_API ABLEActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABLEActor();
	~ABLEActor();

	bool connectionStatus;

	UPROPERTY(BlueprintAssignable, Category = "BLE Events")
	FOnConnectionEvent OnConnected;

	UPROPERTY(BlueprintAssignable, Category = "BLE Events")
	FOnDeviceAddressEvent OnDeviceAddress;

	UPROPERTY(BlueprintAssignable, Category = "BLE Events")
	FOnIntensityEvent OnIntensity;

	UPROPERTY(BlueprintAssignable, Category = "BLE Events")
	FOnEnduranceEvent OnEndurance;

	UPROPERTY(BlueprintAssignable, Category = "BLE Events")
	FOnLeftRightBalanceEvent OnLeftRightBalance;

	UPROPERTY(BlueprintAssignable, Category = "BLE Events")
	FOnRightBalanceEvent OnRightBalance;

	UPROPERTY(BlueprintAssignable, Category = "BLE Events")
	FOnLeftBalanceEvent OnLeftBalance;

	UPROPERTY(BlueprintAssignable, Category = "BLE Events")
	FOnRightMaxEvent OnRightMax;

	UPROPERTY(BlueprintAssignable, Category = "BLE Events")
	FOnLeftMaxEvent OnLeftMax;

	UFUNCTION(BlueprintCallable, Category = "BLE Events")
	void BLE_OnConnection_TriggerEvent(bool ConnectionValue);

	UFUNCTION(BlueprintCallable, Category = "BLE Events")
	void BLE_DeviceAddress_TriggerEvent(FString DeviceAddressValue);

	UFUNCTION(BlueprintCallable, Category = "BLE Events")
	void BLE_Intensity_TriggerEvent(int32 Intensity);

	UFUNCTION(BlueprintCallable, Category = "BLE Events")
	void BLE_Endurance_TriggerEvent(int32 Endurance);

	UFUNCTION(BlueprintCallable, Category = "BLE Events")
	void BLE_RightBalance_TriggerEvent(int32 RightBalanceValue);

	UFUNCTION(BlueprintCallable, Category = "BLE Events")
	void BLE_LeftBalance_TriggerEvent(int32 LeftBalanceValue);

	UFUNCTION(BlueprintCallable, Category = "BLE Events")

	void BLE_LeftRightBalance_TriggerEvent(const TArray<int32>& LeftRightBalanceValue);

	UFUNCTION(BlueprintCallable, Category = "BLE Events")
	void BLE_RightMax_TriggerEvent(int32 RightMaxValue);

	UFUNCTION(BlueprintCallable, Category = "BLE Events")
	void BLE_LeftMax_TriggerEvent(int32 LeftMaxValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ExploreBLE_ShowToast(const FString& Content);

	UFUNCTION(BlueprintCallable)
	bool ExploreBLE_ConnectBLE();

};
