// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MultiPlayerMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERPLUGIN_API UMultiPlayerMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void menuSetup(int32 numPublicConnections = 4, FString matchType = FString(TEXT("FreeForAll")));

protected:
	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void onCreateSession(bool bWasSuccessful);

	void onFindSession(const TArray<FOnlineSessionSearchResult>& sessionResult, bool bWasSuccessful);

	void onJoinSession(EOnJoinSessionCompleteResult::Type sessionResult);

	UFUNCTION()
	void onDestroySession(bool bWasSuccessful);

	UFUNCTION()
	void onStartSession(bool bWasSuccessful);
private: 

	UPROPERTY(meta = (BindWidget))
	class UButton* _hostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* _joinButton;

	UFUNCTION()
	void onHostButtonClicked();

	UFUNCTION()
	void onJoinButtonClicked();

	UFUNCTION()
	void menuTearDown();

	class UMultiplayerPluginSubsystem* _multiplayerSubsystem;

	int32 _numPublicConnections{4};
	FString _matchType{TEXT("FreeForAll")};
};
