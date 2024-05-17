// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MultiplayerPluginSubsystem.generated.h"

/**
 * 
 */
class IOnlineSubsystem;
UCLASS()
class MULTIPLAYERPLUGIN_API UMultiplayerPluginSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	

public:
	UMultiplayerPluginSubsystem();

//////////////////////////////////////////////////////////////////////////
//Functions that handle session functionalities
//////////////////////////////////////////////////////////////////////////
	void createSession(int32 numPublicConnections,FString matchType);

	void findSession(int32 maxSearchResults);

	void joinSession(const FOnlineSessionSearchResult& searchResult);
	
	void destroySession();
	
	void startSession();

protected:
////////////////////////////////////////////////////////////
//Callback functions to handle creating,joining,finding,destroying sessions
////////////////////////////////////////////////////////////
	void onCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void onFindSessionsComplete(bool bWasSuccessful);
	void onJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void onDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void onStartSessionComplete(FName SessionName, bool bWasSuccessful);
private:
	
	IOnlineSubsystem* onlineSubsystem;
	TSharedPtr<class IOnlineSession, ESPMode::ThreadSafe> onlineSession;

////////////////////////////////////////////////////////////
//Delegates that handles creating,joining,finding,destroying sessions
////////////////////////////////////////////////////////////
	FOnCreateSessionCompleteDelegate onCreateSessionCompleteDelegate;
	FOnFindSessionsCompleteDelegate onFindSessionCompleteDelegate;
	FOnJoinSessionCompleteDelegate onJoinSessionCompleteDelegate;
	FOnDestroySessionCompleteDelegate onDestroySessionCompleteDelegate;
	FOnStartSessionCompleteDelegate onStartSessionCompleteDelegate;

	
	
};
