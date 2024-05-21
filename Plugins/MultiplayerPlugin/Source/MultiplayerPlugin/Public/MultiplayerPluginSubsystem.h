// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "MultiplayerPluginSubsystem.generated.h"

////////////////////////////////////////////////////////////
// Declaring Custom Delegates for Other services(Menu Widgets,..,..) to use .
////////////////////////////////////////////////////////////
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnCreateSessionCompleteDelegate, bool, bWasSuccessful);
DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiplayerOnFindSessionCompleteDelegate, const TArray<FOnlineSessionSearchResult>& sessionResult, bool bWasSuccessful);
DECLARE_MULTICAST_DELEGATE_OneParam(FMultiplayerOnJoinSessionCompleteDelegate, EOnJoinSessionCompleteResult::Type sessionResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnStartSessionCompleteDelegate, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnStartSessionCompleteDelegate, bool, bWasSuccessful);


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

//////////////////////////////////////////////////////////////////////////
/// Our Own Custom Delegates for Other Services(Menu Widgets,..,..)
//////////////////////////////////////////////////////////////////////////
	FMultiplayerOnCreateSessionCompleteDelegate multiplayerOnCreateSessionCompleteDelegate;
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
	IOnlineSessionPtr sessionInterface;
	TSharedPtr<FOnlineSessionSettings> sessionSettings;
////////////////////////////////////////////////////////////
//Delegates that handles creating,joining,finding,destroying sessions
////////////////////////////////////////////////////////////
	FOnCreateSessionCompleteDelegate onCreateSessionCompleteDelegate;
	FDelegateHandle createSessionCompleteDelegateHandle;
	FOnFindSessionsCompleteDelegate onFindSessionCompleteDelegate;
	FDelegateHandle findSessionCompleteDelegateHandle;
	FOnJoinSessionCompleteDelegate onJoinSessionCompleteDelegate;
	FDelegateHandle joinSessionCompleteDelegateHandle;
	FOnDestroySessionCompleteDelegate onDestroySessionCompleteDelegate;
	FDelegateHandle destroySessionCompleteDelegateHandle;
	FOnStartSessionCompleteDelegate onStartSessionCompleteDelegate;
	FDelegateHandle startSessionCompleteDelegateHandle;
	
	
};
