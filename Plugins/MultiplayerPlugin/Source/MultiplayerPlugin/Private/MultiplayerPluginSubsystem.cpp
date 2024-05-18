// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerPluginSubsystem.h"
#include "OnlineSubsystem.h"
UMultiplayerPluginSubsystem::UMultiplayerPluginSubsystem():
	onCreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this,&ThisClass::onCreateSessionComplete)),
	onFindSessionCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::onFindSessionsComplete)),
	onJoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::onJoinSessionComplete)),
	onDestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::onDestroySessionComplete)),
	onStartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::onStartSessionComplete))
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
