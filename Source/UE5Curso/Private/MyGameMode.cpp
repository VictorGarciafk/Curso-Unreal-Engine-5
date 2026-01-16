


#include "MyGameMode.h"
#include "GameFramework/HUD.h"

AMyGameMode::AMyGameMode()
{
	//asignamos el blueprint para que se utilice por default
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClass(TEXT("/GAME/Blueprints/BP_player01"));
	if (PlayerPawnClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnClass.Class;
	}

	static ConstructorHelpers::FClassFinder<AHUD> GameHUDClass(TEXT("/Game/Blueprints/UI/BP_GameHUD"));
	if (GameHUDClass.Class != NULL){
		HUDClass = GameHUDClass.Class;
	}
}
