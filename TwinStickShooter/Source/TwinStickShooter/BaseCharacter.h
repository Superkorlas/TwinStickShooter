// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()
    
public:
    //Make a health property.
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
    float Health = 100;
    
    //Make an isDead property.
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
    bool isDead = false;
    
    //Calculate death function (helper).
    virtual void CalculateDead();
    
    //Calculate health function.
    UFUNCTION(BlueprintCallable, Category = "Base Character")
    virtual void CalculateHealth(float delta);
    
#if WITH_EDITOR
    //Editor-centric code for changing properties.
    virtual void PostEditChangeProperty(FPropertyChangedEvent& FPropertyChangedEvent) override;
#endif
    
public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
