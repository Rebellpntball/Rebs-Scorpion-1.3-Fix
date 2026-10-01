class CfgPatches
{
	class Rebs_Scorpion_1_3_Fix
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Vehicles_Wheeled",
			"DZ_Vehicles_Parts",
			"vg7_scorpion"
		};
	};
};

class CfgMods
{
	class Rebs_Scorpion_1_3_Fix
	{
		dir = "Rebs_Scorpion_1_3_Fix";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "Rebs Scorpion 1.3 Fix";
		credits = "Original: VectorG7 / DrBlackouts / DeanosBeano | Compatibility: Rebs";
		author = "Rebs";
		authorID = "0";
		version = "1.3.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"Rebs_Scorpion_1_3_Fix/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Rebs_Scorpion_1_3_Fix/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"Rebs_Scorpion_1_3_Fix/Scripts/5_Mission"};
			};
		};
	};
};
