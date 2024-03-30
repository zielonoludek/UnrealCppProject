#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turret.generated.h"

//Reflection
// Inf about the classes, methods, props etc.
//ue provides all reflection

class USphereComponent;

UCLASS()
class CPPPROJECT_API ATurret : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION() 
	void HandleBeginOverlap(
		UPrimitiveComponent* OverlappedComp, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult);

	UFUNCTION() void HandleEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex
		);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere) USceneComponent* Root = nullptr;
	UPROPERTY(VisibleAnywhere) USphereComponent* Sphere = nullptr;
	UPROPERTY(VisibleAnywhere) USceneComponent* YawRoot = nullptr;
	UPROPERTY(VisibleAnywhere) USceneComponent* PitchRoot = nullptr;
	
	UPROPERTY(EditAnywhere) float YawSpeed = 5.f;
	UPROPERTY(EditAnywhere) float VisibiltyRadius = 1000.f;

	UPROPERTY() AActor* Target = nullptr;
};
