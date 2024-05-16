// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MultiplayerPluginSubsystem.generated.h"

/**
 * 
 */
class IOnlineSubsystem;
class IOnlineSubsystemPtr;
UCLASS()
class MULTIPLAYERPLUGIN_API UMultiplayerPluginSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	

public:
	UMultiplayerPluginSubsystem();

protected:

private:
	IOnlineSubsystem* onlineSubsystem;
	TSharedPtr<class IOnlineSession, ESPMode::ThreadSafe> onlineSession;
};
