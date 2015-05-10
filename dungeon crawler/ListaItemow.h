#pragma once

namespace ListaItemow
{
#pragma region Bronie
	namespace Bronie
	{
		enum ItemBronieLista
		{
			StartBronie = 0,
			DragDrewniany,
			KamienMaly,
			MieczKrotkiBraz,
			ToporekMalyBraz,
			WloczniaMalaKrzemien,
			KoniecBronie
		};
	}  

	namespace BronieDzikie
	{
		enum ItemBronieDzikieLista
		{
			StartBronieDzikie = Bronie::KoniecBronie,
			SzczurzeKly,
			KlyOgara,
			KoniecBronieDzikie
		};
	}
#pragma endregion

#pragma region Pancerze
	namespace Pancerze
	{
		enum ItemPancerzeList
		{
			StartPancerze = BronieDzikie::KoniecBronieDzikie,
			NaramiennikiSkora,
			RekawiceSkora,
			NagolennikiSkora,
			ButySkora,
			HelmSkora,
			ZbrojaSkora,
			KoniecPancerze
		};
	}  

	namespace PancerzeDzikie
	{
		enum ItemPancerzeDzikieList
		{
			StartPancerzeDzikie = Pancerze::KoniecPancerze,
			SkoraSzczura,
			SkoraOgara,
			Szmaty,
			ZbrojaGoblinGwadzista,
			ZbrojaGoblinBerserker,
			ZbrojaGoblinSzaman,
			KoniecPancerzeDzikie
		};
	}
#pragma endregion

#pragma region Pojemniki
	namespace Pojemniki
	{
		enum ItemPojemnikiList
		{
			StartPojemniki = PancerzeDzikie::KoniecPancerzeDzikie,
			Zwloki,
			TorbaPodrozna,
			StarySzkielet,
			DrewnianaSkrzynia,
			KoniecPojemniki
		};
	}  
#pragma endregion

#pragma region Consumables
	namespace Consumables
	{
		enum ItemConsumablesList
		{
			StartConsumables = Pojemniki::KoniecPojemniki,
			MiksturaZrecznosciSlaba,
			KoniecConsumables
		};
	}  
#pragma endregion

#pragma region Questowe
	namespace Questowe
	{
		enum ItemQuestoweList
		{
			StartQuestowe = Consumables::KoniecConsumables,
			OkraglySzafir,
			KawalkiPotluczonegoSzkla,
			StluczoneLustro,
			Mapa,
			KoniecQuestowe
		};
	}  
#pragma endregion

#pragma region Dzwignie
	namespace Dzwignie
	{
		enum ItemDzwignieList
		{
			StartDzwignie = Questowe::KoniecQuestowe,
			ButelkaPoWinie,
			KoniecDzwignie
		};
	}  
#pragma endregion

#pragma region Klucze
	namespace Klucze
	{
		enum ItemKluczeList
		{
			StartKlucze = Dzwignie::KoniecDzwignie,
			KluczZZelazaProsty,
			KluczZBrazuLvl2,
			KluczZSrebraLvl3,
			KoniecKlucze
		};
	}  
#pragma endregion

#pragma region Magiczne
	namespace Magiczne
	{
		enum ItemMagiczneList
		{
			StartMagiczne = Klucze::KoniecKlucze,
			KoszulaLniana,
			SpodnieLniane,
			KoniecMagiczne
		};
	}  
#pragma endregion

}