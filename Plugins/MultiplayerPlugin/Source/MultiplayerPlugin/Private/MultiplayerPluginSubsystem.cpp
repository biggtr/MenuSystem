// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerPluginSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

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
		sessionInterface = onlineSubsystem->GetSessionInterface();
	}

}

void UMultiplayerPluginSubsystem::createSession(int32 numPublicConnections, FString matchType)
{
	if (!sessionInterface.IsValid())
	{
		return;
	}
	auto existingSession = sessionInterface->GetNamedSession(NAME_GameSession);
	if (existingSession)
	{
		sessionInterface->DestroySession(NAME_GameSession);
	}
	createSessionCompleteDelegateHandle = sessionInterface->AddOnCreateSessionCompleteDelegate_Handle(onCreateSessionCompleteDelegate);

	sessionSettings = MakeShareable(new FOnlineSessionSettings);
	sessionSettings->bIsLANMatch = IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true : false;
	sessionSettings->NumPublicConnections = 4;
	sessionSettings->bAllowJoinInProgress = true;
	sessionSettings->bAllowJoinViaPresence = true;
	sessionSettings->bShouldAdvertise = true;
	sessionSettings->bUsesPresence = true;
	sessionSettings->Set(FName("MatchType"), matchType, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();

	if (!sessionInterface->CreateSession(*localPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *sessionSettings))
	{
		sessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(createSessionCompleteDelegateHandle);
	}

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
