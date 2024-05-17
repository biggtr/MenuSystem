// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerPluginSubsystem.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
UMultiplayerPluginSubsystem::UMultiplayerPluginSubsystem():

{
	onlineSubsystem = IOnlineSubsystem::Get();

	if (onlineSubsystem)
	{
		onlineSession = onlineSubsystem->GetSessionInterface();
	}

}

void UMultiplayerPluginSubsystem::createSession(int32 numPublicConnections, FString matchType)
{

}

void UMultiplayerPluginSubsystem::findSession(int32 maxSearchResults)
{
}

void UMultiplayerPluginSubsystem::joinSession(const FOnlineSessionSearchResult& searchResult)
{

}

void UMultiplayerPluginSubsystem::destroySession()
{

}

void UMultiplayerPluginSubsystem::startSession()
{

}

void UMultiplayerPluginSubsystem::onCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{

}

void UMultiplayerPluginSubsystem::onFindSessionsComplete(bool bWasSuccessful)
{

}

void UMultiplayerPluginSubsystem::onJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{

}

void UMultiplayerPluginSubsystem::onDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{

}

void UMultiplayerPluginSubsystem::onStartSessionComplete(FName SessionName, bool bWasSuccessful)
{

}
