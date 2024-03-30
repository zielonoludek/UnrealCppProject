#include "Turret.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

ATurret::ATurret()
{
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(Root);
	Sphere->SetSphereRadius(VisibiltyRadius);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ATurret::HandleBeginOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ATurret::HandleEndOverlap);

	YawRoot = CreateDefaultSubobject<USceneComponent>("YawRoot");
	PitchRoot = CreateDefaultSubobject<USceneComponent>("PitchRoot");

	YawRoot->SetupAttachment(Root);
	PitchRoot->SetupAttachment(YawRoot);

	PrimaryActorTick.bCanEverTick = true;
}
void ATurret::BeginPlay()
{
	Super::BeginPlay();
}

void ATurret::Tick(float DeltaTime)
{
	if (Target)
	{
		Super::Tick(DeltaTime);

		FVector CurrentDirection = PitchRoot->GetForwardVector();
		FVector TargetDirection = Target->GetActorLocation() - PitchRoot->GetComponentLocation();
		UKismetMathLibrary::Vector_SlerpVectorToDirection(CurrentDirection, TargetDirection, YawSpeed * DeltaTime);

		FRotator TargetRotation = UKismetMathLibrary::MakeRotFromX(CurrentDirection);
		YawRoot->SetWorldRotation(FRotator(0, TargetRotation.Yaw, 0));
		PitchRoot->SetRelativeRotation(FRotator(TargetRotation.Pitch, 0, 0));
	}
}

void ATurret::HandleBeginOverlap(
	UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult) 
{
	//UE_LOG(LogTemp, Log, TEXT("Begin Overlap: %s"), *OtherActor->GetName());
	if (OtherActor->IsA<ACharacter>()) Target = OtherActor;
}
void ATurret::HandleEndOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex
)
{
	if (OtherActor == Target) Target = nullptr;
}