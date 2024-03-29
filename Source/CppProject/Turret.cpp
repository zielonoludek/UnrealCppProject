#include "Turret.h"
#include "Components/SphereComponent.h"

ATurret::ATurret()
{
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(Root);
	Sphere->SetSphereRadius(VisibiltyRadius);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ATurret::HandleBeginOverlap);

	YawRoot = CreateDefaultSubobject<USceneComponent>("YawRoot");
	PitchRoot = CreateDefaultSubobject<USceneComponent>("PitchRoot");

	YawRoot->SetupAttachment(Root);
	PitchRoot->SetupAttachment(YawRoot);

	PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	YawRoot->AddLocalRotation(FRotator(0, YawSpeed * DeltaTime, 0));
	
	FRotator PitchRotator;
	PitchRotator.Pitch = FMath::Cos(GetWorld()->GetTimeSeconds()) * 50.f;
	PitchRoot->SetRelativeRotation(PitchRotator);
}

void ATurret::HandleBeginOverlap(
	UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult) 
{
	UE_LOG(LogTemp, Log, TEXT("Begin Overlap: %s"), *OtherActor->GetName());
}