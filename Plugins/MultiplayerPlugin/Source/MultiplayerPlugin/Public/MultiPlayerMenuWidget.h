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
	void menuSetup();

protected:
	virtual bool Initialize() override;
private: 

	UPROPERTY(meta = (BindWidget))
	class UButton* hostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* joinButton;

	UFUNCTION()
	void onHostButtonClicked();

	UFUNCTION()
	void onJoinButtonClicked();

};
