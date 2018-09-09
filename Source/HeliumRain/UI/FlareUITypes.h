#pragma once

#include "../Spacecrafts/FlareSpacecraftTypes.h"

#include "SlateBasics.h"
#include "SlateGameResources.h"
#include "../UI/Style/FlareStyleSet.h"

#include "FlareUITypes.generated.h"


/** Possible menu targets */
UENUM()
namespace EFlareMenu
{
	enum Type
	{
		MENU_None,

		// Boot menus
		MENU_Main,
		MENU_NewGame,

		// Special "menus" for async transitions
		MENU_CreateGame,
		MENU_LoadGame,
		MENU_FlyShip,
		MENU_Travel,
		MENU_ReloadSector,
		MENU_FastForwardSingle,
		MENU_GameOver,

		// Main gameplay menus
		MENU_Story,
		MENU_Company,
		MENU_Fleet,
		MENU_Quest,
		MENU_Ship,
		MENU_ShipConfig,
		MENU_Station,
		MENU_Sector,
		MENU_Trade,
		MENU_TradeRoute,
		MENU_Orbit,
		MENU_Leaderboard,
		MENU_ResourcePrices,
		MENU_WorldEconomy,
		MENU_Technology,

		// Skirmish mode
		MENU_SkirmishSetup,
		MENU_SkirmishScore,

		// Support menus
		MENU_Settings,
		MENU_Credits,
		MENU_EULA,
		MENU_Quit
	};
}


/** Menu parameter structure storing commands + data for async processing */
struct FFlareMenuParameterData
{
	FFlareMenuParameterData()
		: Company(NULL)
		, Factory(NULL)
		, Fleet(NULL)
		, Quest(NULL)
		, Route(NULL)
		, Sector(NULL)
		, Spacecraft(NULL)
		, Travel(NULL)
		, Skirmish(NULL)
		, Resource(NULL)
		, CompanyDescription(NULL)
		, ScenarioIndex(0)
		, PlayerEmblemIndex(0)
		, PlayTutorial(false)
		, OrderForPlayer(false)
		, SpacecraftOrderHeavy(false)
		, ComplexConnectorName(NAME_None)
	{}

	class UFlareCompany*                        Company;
	class UFlareFactory*                        Factory;
	class UFlareFleet*                          Fleet;
	class UFlareQuest*                          Quest;
	class UFlareTradeRoute*                     Route;
	class UFlareSimulatedSector*                Sector;
	class UFlareSimulatedSpacecraft*            Spacecraft;
	class UFlareTravel*                         Travel;
	class UFlareSkirmishManager*               Skirmish;
	struct FFlareResourceDescription*           Resource;
	struct FFlareCompanyDescription*            CompanyDescription;

	int32                                       ScenarioIndex;
	int32                                       PlayerEmblemIndex;
	bool                                        PlayTutorial;
	bool                                        OrderForPlayer;
	bool                                        SpacecraftOrderHeavy;
	FName                                       ComplexConnectorName;
};


/** Possible notification types */
UENUM()
namespace EFlareNotification
{
	enum Type
	{
		NT_Info,
		NT_Economy,
		NT_Military,
		NT_MilitarySilent,
		NT_NewQuest,
		NT_Quest
	};
}


// Delegates
DECLARE_DELEGATE_OneParam(FOrderDelegate, FFlareSpacecraftDescription*)



UCLASS()
class HELIUMRAIN_API UFlareUITypes : public UObject
{
public:

	GENERATED_UCLASS_BODY()


	/** Add a header */
	static TSharedRef<SWidget> Header(FText Title);

};
