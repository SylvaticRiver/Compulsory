#include "MainController.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include <UObject/ConstructorHelpers.h>
#include "Containers/Array.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMainController::AMainController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Spheres.Init(NULL, 9);
	Spheres[0] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh1"));
	Spheres[1] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh2"));
	Spheres[2] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh3"));
	Spheres[3] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh4"));
	Spheres[4] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh5"));
	Spheres[5] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh6"));
	Spheres[6] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh7"));
	Spheres[7] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh8"));
	Spheres[8] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh9"));

	RootComponent = Spheres[4];
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshComponentAsset(TEXT("StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere'"));
	Spheres[0]->SetupAttachment(GetRootComponent());
	Spheres[1]->SetupAttachment(GetRootComponent());
	Spheres[2]->SetupAttachment(GetRootComponent());
	Spheres[3]->SetupAttachment(GetRootComponent());
	Spheres[5]->SetupAttachment(GetRootComponent());
	Spheres[6]->SetupAttachment(GetRootComponent());
	Spheres[7]->SetupAttachment(GetRootComponent());
	Spheres[8]->SetupAttachment(GetRootComponent());
	Spheres[0]->SetStaticMesh(MeshComponentAsset.Object);
	Spheres[1]->SetStaticMesh(MeshComponentAsset.Object);
	Spheres[2]->SetStaticMesh(MeshComponentAsset.Object);
	Spheres[3]->SetStaticMesh(MeshComponentAsset.Object);
	Spheres[4]->SetStaticMesh(MeshComponentAsset.Object);
	Spheres[5]->SetStaticMesh(MeshComponentAsset.Object);
	Spheres[6]->SetStaticMesh(MeshComponentAsset.Object);
	Spheres[7]->SetStaticMesh(MeshComponentAsset.Object);
	Spheres[8]->SetStaticMesh(MeshComponentAsset.Object);



	Red = CreateDefaultSubobject<UMaterial>(TEXT("RedMaterial"));
	Blue = CreateDefaultSubobject<UMaterial>(TEXT("BlueMaterial"));
	White = CreateDefaultSubobject<UMaterial>(TEXT("WhiteMaterial"));


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeRotation(FRotator(-65.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 500.f;

	// Attach the Camera to SpringArm
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	Spheres[0]->SetRelativeLocation(FVector(150.f, -150.f, 0.f));
	Spheres[1]->SetRelativeLocation(FVector(150.f, 0.f, 0.f));
	Spheres[2]->SetRelativeLocation(FVector(150.f, 150.f, 0.f));
	Spheres[3]->SetRelativeLocation(FVector(0.f, -150.f, 0.f));
	Spheres[4]->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	Spheres[5]->SetRelativeLocation(FVector(0.f, 150.f, 0.f));
	Spheres[6]->SetRelativeLocation(FVector(-150.f, -150.f, 0.f));
	Spheres[7]->SetRelativeLocation(FVector(-150.f, 0.f, 0.f));
	Spheres[8]->SetRelativeLocation(FVector(-150.f, 150.f, 0.f));

	isRed = false;
	Color.Init(NULL, 9);

}

// Called when the game starts or when spawned
void AMainController::BeginPlay()
{
	Super::BeginPlay();

	Spheres[0]->SetMaterial(0, White);
	Spheres[1]->SetMaterial(0, White);
	Spheres[2]->SetMaterial(0, White);
	Spheres[3]->SetMaterial(0, White);
	Spheres[4]->SetMaterial(0, White);
	Spheres[5]->SetMaterial(0, White);
	Spheres[6]->SetMaterial(0, White);
	Spheres[7]->SetMaterial(0, White);
	Spheres[8]->SetMaterial(0, White);
}

// Called every frame
void AMainController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("1", IE_Pressed, this, &AMainController::OnePressed);
	PlayerInputComponent->BindAction("2", IE_Pressed, this, &AMainController::TwoPressed);
	PlayerInputComponent->BindAction("3", IE_Pressed, this, &AMainController::ThreePressed);
	PlayerInputComponent->BindAction("4", IE_Pressed, this, &AMainController::FourPressed);
	PlayerInputComponent->BindAction("5", IE_Pressed, this, &AMainController::FivePressed);
	PlayerInputComponent->BindAction("6", IE_Pressed, this, &AMainController::SixPressed);
	PlayerInputComponent->BindAction("7", IE_Pressed, this, &AMainController::SevenPressed);
	PlayerInputComponent->BindAction("8", IE_Pressed, this, &AMainController::EightPressed);
	PlayerInputComponent->BindAction("9", IE_Pressed, this, &AMainController::NinePressed);

}

void AMainController::OnePressed()
{
	TurnController(0);

}

void AMainController::TwoPressed()
{
	TurnController(1);
}

void AMainController::ThreePressed()
{
	TurnController(2);
}

void AMainController::FourPressed()
{
	TurnController(3);
}

void AMainController::FivePressed()
{
	TurnController(4);
}

void AMainController::SixPressed()
{
	TurnController(5);
}

void AMainController::SevenPressed()
{
	TurnController(6);
}

void AMainController::EightPressed()
{
	TurnController(7);
}

void AMainController::NinePressed()
{
	TurnController(8);
}



void AMainController::TurnController(int indexNumber)
{
	if (Color[indexNumber] == NULL)
	{
		if (!isRed)
		{
			Spheres[indexNumber]->SetMaterial(0, Blue);
			Color[indexNumber] = Blue;

		}
		else if (isRed)
		{
			Spheres[indexNumber]->SetMaterial(0, Red);
			Color[indexNumber] = Red;
		}
		isRed = !isRed;
		isMatching(indexNumber);
	}
}

void AMainController::isMatching(int index) {
	int rowNumber;
	int columnNumber;
	if (index <= 2) {
		rowNumber = 0;
	}
	if (index <= 5 && index >= 3) {
		rowNumber = 1;
	}
	if (index <= 8 && index >= 6) {
		rowNumber = 2;
	}
	for (int i = 0; i < 3; i++) {
		if (index == 0 + (i * 3)) {
			columnNumber = 0;
		}
		if (index == 1 + (i * 3)) {
			columnNumber = 1;
		}
		if (index == 2 + (i * 3)) {
			columnNumber = 3;
		}
	}

	int startRow = rowNumber * 3;
	bool isblue = (Color[startRow] == Blue && Color[startRow + 1] == Blue && Color[startRow + 2] == Blue) || (Color[columnNumber] == Blue && Color[columnNumber + 3] == Blue && Color[columnNumber + 6] == Blue) || ((Color[0] == Blue && Color[4] == Blue && Color[8] == Blue) || (Color[2] == Blue && Color[4] == Blue && Color[6] == Blue));
	bool isred = (Color[startRow] == Red && Color[startRow + 1] == Red && Color[startRow + 2] == Red) || (Color[columnNumber] == Red && Color[columnNumber + 3] == Red && Color[columnNumber + 6] == Red) || ((Color[0] == Red && Color[4] == Red && Color[8] == Red) || (Color[2] == Red && Color[4] == Red && Color[6] == Red));
	if (isblue) {
		GEngine->AddOnScreenDebugMessage(-1, 2.5, FColor::Blue, "BlueWon", true, FVector2D(7.5, 7.5));
		for (int g = 0; g < 9; g++) {
			Color[g] = NULL;
			Spheres[g]->SetMaterial(0, White);
			isRed = false;
		}
	}
	else if (isred) {
		GEngine->AddOnScreenDebugMessage(-1, 2.5, FColor::Red, "RedWon", true, FVector2D(7.5, 7.5));
		for (int g = 0; g < 9; g++) {
			Color[g] = NULL;
			Spheres[g]->SetMaterial(0, White);
			isRed = false;
		}
	}
}