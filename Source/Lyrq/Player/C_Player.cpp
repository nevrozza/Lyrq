 // Fill out your copyright notice in the Description page of Project Settings.


#include "C_Player.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
// Этот код вызывается ещё до запуска игры!! (по факту настройка в blueprints)
AC_Player::AC_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Создание компонента AC Stats 
	StatsComponent = CreateDefaultSubobject<UAC_Stats>(TEXT("AC Stats"));
	
}






// Called when the game starts or when spawned
void AC_Player::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);

			// 1 sec delay
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
			{
					StatsComponent->RegisterPlayer();
					bIsInvincible = false;
					bIsBlocking = false;
			}, 1, false);

		}
	}
	
}

// Called to bind functionality to input
void AC_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AC_Player::Move);
	}

}

void AC_Player::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr) 
	{	
		// "/" axis
		AddMovementInput(FVector::ForwardVector + FVector::RightVector, MovementVector.Y);
		// "\" axis
		AddMovementInput(FVector::RightVector + FVector::BackwardVector, MovementVector.X);
	}
}




