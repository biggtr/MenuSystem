// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerPluginSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

UMultiplayerPluginSubsystem::UMultiplayerPluginSubsystem():
	_onCreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this,&ThisClass::onCreateSessionComplete)),
	_onFindSessionCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::onFindSessionsComplete)),
	_onJoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::onJoinSessionComplete)),
	_onDestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::onDestroySessionComplete)),
	_onStartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::onStartSessionComplete))
{
	_onlineSubsystem = IOnlineSubsystem::Get();

	if (_onlineSubsystem)
	{
		_sessionInterface = _onlineSubsystem->GetSessionInterface();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Red,
				FString::Printf(TEXT("Found subsystem %s"), *_onlineSubsystem->GetSubsystemName().ToString())
			);
		}

	}

}

void UMultiplayerPluginSubsystem::createSession(int32 numPublicConnections, FString matchType)
{
	if (!_sessionInterface.IsValid())
	{
		return;
	}
	auto existingSession = _sessionInterface->GetNamedSession(NAME_GameSession);
	if (existingSession)
	{
		_sessionInterface->DestroySession(NAME_GameSession);
	}
	_createSessionCompleteDelegateHandle = _sessionInterface->AddOnCreateSessionCompleteDelegate_Handle(_onCreateSessionCompleteDelegate);

	_sessionSettings = MakeShareable(new FOnlineSessionSettings);
	_sessionSettings->bIsLANMatch = IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true : false;
	_sessionSettings->NumPublicConnections = numPublicConnections;
	_sessionSettings->bAllowJoinInProgress = true;
	_sessionSettings->bAllowJoinViaPresence = true;
	_sessionSettings->bShouldAdvertise = true;
	_sessionSettings->bUsesPresence = true;
	_sessionSettings->Set(FName("MatchType"), matchType, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();

	if (!_sessionInterface->CreateSession(*localPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *_sessionSettings))
	{
		_sessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(_createSessionCompleteDelegateHandle);
		
		multiplayerOnCreateSessionCompleteDelegate.Broadcast(false);
	}

}

void UMultiplayerPluginSubsystem::findSession(int32 maxSearchResults)
{
	if (!_sessionInterface.IsValid())
	{
		return;
	}

	_findSessionCompleteDelegateHandle = _sessionInterface->AddOnFindSessionsCompleteDelegate_Handle(_onFindSessionCompleteDelegate);
	_searchSettings = MakeShareable(new FOnlineSessionSearch());
	_searchSettings->bIsLanQuery = IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true : false;
	_searchSettings->MaxSearchResults = maxSearchResults;
	_searchSettings->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
	UWorld* world = GetWorld();
	if (world)
	{
		const ULocalPlayer* localPlayer = world->GetFirstLocalPlayerFromController();

		if (!_sessionInterface->FindSessions(*localPlayer->GetPreferredUniqueNetId(), _searchSettings.ToSharedRef()))
		{

			multi
		}
	}

	
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
	if (_sessionInterface)
	{
		_sessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(_createSessionCompleteDelegateHandle);
	}
	multiplayerOnCreateSessionCompleteDelegate.Broadcast(bWasSuccessful);

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
