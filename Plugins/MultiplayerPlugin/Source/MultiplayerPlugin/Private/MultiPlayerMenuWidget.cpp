// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiPlayerMenuWidget.h"
#include "Components/Button.h"
#include "MultiplayerPluginSubsystem.h"

void UMultiPlayerMenuWidget::menuSetup(int32 numPublicConnections , FString matchType)
{
	_numPublicConnections = numPublicConnections;
	_matchType = matchType;
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;

	UWorld* world = GetWorld();
	if (world)
	{
		APlayerController* playerController = world->GetFirstPlayerController();
		if (playerController)
		{

			FInputModeUIOnly inputModeData;
			inputModeData.SetWidgetToFocus(TakeWidget());
			inputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			playerController->SetInputMode(inputModeData);
			playerController->SetShowMouseCursor(true);

		}
	}
	UGameInstance* gameInstance = GetGameInstance();

	if (gameInstance)
	{
		_multiplayerSubsystem = gameInstance->GetSubsystem<UMultiplayerPluginSubsystem>();
	}

	if (_multiplayerSubsystem)
	{
		_multiplayerSubsystem->multiplayerOnCreateSessionCompleteDelegate.AddDynamic(this, &ThisClass::onCreateSession);
	}
}

bool UMultiPlayerMenuWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	if (_hostButton)
	{
		_hostButton->OnClicked.AddDynamic(this, &ThisClass::onHostButtonClicked);
	}
	if (_joinButton)
	{
		_joinButton->OnClicked.AddDynamic(this, &ThisClass::onJoinButtonClicked);
	}
	return true;
}


void UMultiPlayerMenuWidget::NativeDestruct()
{
	menuTearDown();

	Super::NativeDestruct();
}

void UMultiPlayerMenuWidget::onCreateSession(bool bWasSuccessful)
{

	if (bWasSuccessful)
	{
		if (GEngine)
		{

			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString(TEXT("Session is created successfully. ")));
		}

		UWorld* world = GetWorld();
		if (world)
		{
			world->ServerTravel("/Game/Maps/Lobby?listen");
		}
	}
	else
	{
		if (GEngine)
		{

			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString(TEXT("Failed to create session. ")));
		}
	}
}

void UMultiPlayerMenuWidget::onHostButtonClicked()
{
	if (GEngine)
	{
		
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString(TEXT("HostButtom is clicked")));
	}
	if (_multiplayerSubsystem)
	{
		_multiplayerSubsystem->createSession(_numPublicConnections, _matchType);
		
	}
}

void UMultiPlayerMenuWidget::onJoinButtonClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString(TEXT("JoinButtom is clicked")));
	}
}

void UMultiPlayerMenuWidget::menuTearDown()
{
	RemoveFromParent();
	UWorld* world = GetWorld();

	if (world)
	{
		APlayerController* playerController = world->GetFirstPlayerController();
		if (playerController)
		{
			FInputModeGameOnly inputModeData;
			playerController->SetInputMode(inputModeData);
			playerController->SetShowMouseCursor(false);
		}
	}
}
