// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiPlayerMenuWidget.h"
#include "Components/Button.h"

void UMultiPlayerMenuWidget::menuSetup()
{
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
}

bool UMultiPlayerMenuWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	if (hostButton)
	{
		hostButton->OnClicked.AddDynamic(this, &ThisClass::onHostButtonClicked);
	}
	if (joinButton)
	{
		joinButton->OnClicked.AddDynamic(this, &ThisClass::onJoinButtonClicked);
	}
	return true;
}

void UMultiPlayerMenuWidget::onHostButtonClicked()
{

}

void UMultiPlayerMenuWidget::onJoinButtonClicked()
{

}
