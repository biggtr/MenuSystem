// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerPluginSubsystem.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
UMultiplayerPluginSubsystem::UMultiplayerPluginSubsystem()
{
	onlineSubsystem = IOnlineSubsystem::Get();

	if (onlineSubsystem)
	{
		onlineSession = onlineSubsystem->GetSessionInterface();
	}

}
