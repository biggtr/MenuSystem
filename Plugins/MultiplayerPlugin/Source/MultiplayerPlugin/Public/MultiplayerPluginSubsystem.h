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
DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiplayerOnJoinSessionCompleteDelegate, EOnJoinSessionCompleteResult::Type sessionResult, FString ipAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnStartSessionCompleteDelegate, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnDestroySessionCompleteDelegate, bool, bWasSuccessful);


class IOnlineSubsystem;
class FOnlineSessionSearch;
class FOnlineSessionSettings;
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
	FMultiplayerOnFindSessionCompleteDelegate multiplayerOnFindSessionCompleteDelegate;
	FMultiplayerOnJoinSessionCompleteDelegate multiplayerOnJoinSessionCompleteDelegate;
	FMultiplayerOnStartSessionCompleteDelegate multiplayerOnStartSessionCompleteDelegate;
	FMultiplayerOnDestroySessionCompleteDelegate multiplayerOnDestroySessionCompleteDelegate;

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
	
	IOnlineSubsystem* _onlineSubsystem;
	IOnlineSessionPtr _sessionInterface;
	TSharedPtr<FOnlineSessionSettings> _sessionSettings;
	TSharedPtr<FOnlineSessionSearch> _searchSettings;
////////////////////////////////////////////////////////////
//Delegates that handles creating,joining,finding,destroying sessions
////////////////////////////////////////////////////////////
	FOnCreateSessionCompleteDelegate _onCreateSessionCompleteDelegate;
	FDelegateHandle _createSessionCompleteDelegateHandle;
	FOnFindSessionsCompleteDelegate _onFindSessionCompleteDelegate;
	FDelegateHandle _findSessionCompleteDelegateHandle;
	FOnJoinSessionCompleteDelegate _onJoinSessionCompleteDelegate;
	FDelegateHandle _joinSessionCompleteDelegateHandle;
	FOnDestroySessionCompleteDelegate _onDestroySessionCompleteDelegate;
	FDelegateHandle _onDestroySessionCompleteDelegateHandle;
	FOnStartSessionCompleteDelegate _onStartSessionCompleteDelegate;
	FDelegateHandle _onStartSessionCompleteDelegateHandle;
	
	
};
