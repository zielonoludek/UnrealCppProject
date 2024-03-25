#include "Turret.h"
#include "Components/SphereComponent.h"

// Sets default values
ATurret::ATurret()
{
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

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

}

///https://changemakereducation.sharepoint.com/sites/FG23GP_ALL-GameprogrammingwithC/_layouts/15/stream.aspx?id=%2Fsites%2FFG23GP%5FALL%2DGameprogrammingwithC%2FDelade%20dokument%2FGeneral%2FRecordings%2FLecture%5F24%2D03%2D20%20%28Part%201%29%2Emp4&referrer=StreamWebApp%2EWeb&referrerScenario=AddressBarCopied%2Eview