class CfgPatches
{
	class Rebs_Scorpion_1_3_Fix
	{
		units[] =
		{
			"vg7_scorpion_Rebs_BloodAce",
			"vg7_scorpion_Rebs_HellsAngels",
			"vg7_scorpion_Rebs_EasyRider",
			"vg7_scorpion_Rebs_Sons",
			"vg7_scorpion_Rebs_OutlawBlack",
			"vg7_scorpion_Rebs_DrifterFlame",
			"vg7_scorpion_Rebs_AceOfSpades",
			"vg7_scorpion_Rebs_RustRat",
			"vg7_scorpion_Rebs_PinkLadies",
			"vg7_scorpion_Rebs_GoldenChopper",
			"vg7_scorpion_Rebs_WhiteLightning",
			"vg7_scorpion_Rebs_BloodAndChrome",
			"vg7_scorpion_Rebs_Route66",
			"vg7_scorpion_Rebs_NightRider",
			"vg7_scorpion_Rebs_Bandidos",
			"vg7_scorpion_Rebs_MongolOrange",
			"vg7_scorpion_Rebs_ButterflyNight",
			"vg7_scorpion_Rebs_MermaidChopper",
			"vg7_scorpion_Rebs_Patriot",
			"vg7_scorpion_Rebs_Princess",
			"vg7_scorpion_Rebs_ChromeDreams",
			"vg7_scorpion_Rebs_ScarletWidow",
			"vg7_scorpion_Rebs_DesertRat",
			"vg7_scorpion_Rebs_BlueBlood",
			"vg7_scorpion_Rebs_CyberBlue",
			"vg7_scorpion_Rebs_ArmyGreen",
			"vg7_scorpion_Rebs_AshGrunge",
			"vg7_scorpion_Rebs_RustGrunge"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Vehicles_Wheeled","DZ_Vehicles_Parts","vg7_scorpion"};
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
		credits = "Original: VectorG7 / DrBlackouts / DeanosBeano | Compatibility + paints: Rebs";
		author = "Rebs";
		authorID = "0";
		version = "1.3.5";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule { value = ""; files[] = {"Rebs_Scorpion_1_3_Fix/Scripts/3_Game"}; };
			class worldScriptModule { value = ""; files[] = {"Rebs_Scorpion_1_3_Fix/Scripts/4_World"}; };
			class missionScriptModule { value = ""; files[] = {"Rebs_Scorpion_1_3_Fix/Scripts/5_Mission"}; };
		};
	};
};

class CfgVehicles
{
	// Forward-declare so we can inherit (same pattern as Truck_01_Improvements / MBM_RamRebel_128Fix)
	class CarScript;
	class SimulationModule;
	class Throttle;
	class Brake;
	class Aerodynamics;
	class Engine;
	class Clutch;
	class Gearbox;
	class Axles;
	class Front;
	class Rear;
	class Suspension;

	// HANDLING ONLY – inherit original SimulationModule / Axles / Wheels
	// Do NOT redefine Wheels or full Axles (would wipe wheel slots).
	class vg7_scorpion: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Throttle: Throttle
			{
				reactionTime = 0.85;
				defaultThrust = 0.75;
				gentleThrust = 0.6;
				turboCoef = 3.6;
				gentleCoef = 0.75;
			};
			class Aerodynamics: Aerodynamics
			{
				frontalArea = 2.15;
				dragCoefficient = 0.40;
				downforceCoefficient = 0.6;
				downforceOffset[] = {0,0.35,-1.8};
			};
			// Only tweak response – keep original torqueCurve / rpm from base mod
			class Engine: Engine
			{
				inertia = 0.45;
				rollingFriction = 1.9;
				viscousFriction = 1.1;
				frictionTorque = 100;
			};
			class Clutch: Clutch
			{
				maxTorqueTransfer = 280;
				uncoupleTime = 0.25;
				coupleTime = 0.25;
			};
			// Inherit Axles so Wheels / differentials / inventory slots stay intact
			class Axles: Axles
			{
				class Front: Front
				{
					class Suspension: Suspension
					{
						stiffness = 27000;
						compression = 3200;
						damping = 6200;
					};
				};
				class Rear: Rear
				{
					class Suspension: Suspension
					{
						stiffness = 24000;
						compression = 3000;
						damping = 6000;
					};
				};
			};
		};
	};

	// REBS SIGNATURE – Blood Ace (Ace tank/seat/forks, blood-red frame, black grips)
	class vg7_scorpion_Rebs_BloodAce: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS BLOOD ACE";
		descriptionShort = "REBS signature. Ace tank, Ace seat, Ace forks. Blood-red frame, black grips.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_Ace_CA.paa",
			"#(argb,8,8,3)color(0.50,0.02,0.02,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"#(argb,8,8,3)color(0.50,0.02,0.02,1,CO)",
			"#(argb,8,8,3)color(0.50,0.02,0.02,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"#(argb,8,8,3)color(0.04,0.04,0.04,1,CO)"
		};
	};

	class vg7_scorpion_Rebs_HellsAngels: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS HELLS ANGELS";
		descriptionShort = "Blood-red tank on black iron.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"};
	};

	class vg7_scorpion_Rebs_EasyRider: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS EASY RIDER";
		descriptionShort = "USA tank on black iron.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","vg7_scorpion\\vg7_scorpion\\data\\GasTank_USA_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"};
	};

	class vg7_scorpion_Rebs_Sons: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS SONS";
		descriptionShort = "Ace tank on blood-red frame.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","vg7_scorpion\\vg7_scorpion\\data\\GasTank_Ace_CA.paa","#(argb,8,8,3)color(0.45,0.02,0.02,1,CO)","#(argb,8,8,3)color(0.45,0.02,0.02,1,CO)","#(argb,8,8,3)color(0.45,0.02,0.02,1,CO)","#(argb,8,8,3)color(0.45,0.02,0.02,1,CO)","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","#(argb,8,8,3)color(0.08,0.08,0.08,1,CO)"};
	};

	class vg7_scorpion_Rebs_OutlawBlack: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS OUTLAW BLACK";
		descriptionShort = "All black.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.04,0.04,0.04,1,CO)","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","#(argb,8,8,3)color(0.08,0.08,0.08,1,CO)","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"};
	};

	class vg7_scorpion_Rebs_DrifterFlame: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS DRIFTER FLAME";
		descriptionShort = "Drifter tank, flame-orange frame.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","vg7_scorpion\\vg7_scorpion\\data\\GasTank_Drifter_CA.paa","#(argb,8,8,3)color(0.85,0.28,0.04,1,CO)","#(argb,8,8,3)color(0.85,0.28,0.04,1,CO)","#(argb,8,8,3)color(0.85,0.28,0.04,1,CO)","#(argb,8,8,3)color(0.85,0.28,0.04,1,CO)","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","#(argb,8,8,3)color(0.06,0.06,0.06,1,CO)"};
	};

	class vg7_scorpion_Rebs_AceOfSpades: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS ACE OF SPADES";
		descriptionShort = "Ace tank, Ace seat, black iron.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","vg7_scorpion\\vg7_scorpion\\data\\GasTank_Ace_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"};
	};

	class vg7_scorpion_Rebs_RustRat: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS RUST RAT";
		descriptionShort = "Full Ace Rust.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","vg7_scorpion\\vg7_scorpion\\data\\GasTank_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa"};
	};

	class vg7_scorpion_Rebs_PinkLadies: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS PINK LADIES";
		descriptionShort = "Hot pink tank + pink OG body.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.90,0.25,0.55,1,CO)","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa"};
	};

	class vg7_scorpion_Rebs_GoldenChopper: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS GOLDEN CHOPPER";
		descriptionShort = "Show-bike gold.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)","#(argb,8,8,3)color(0.10,0.08,0.05,1,CO)","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)"};
	};

	class vg7_scorpion_Rebs_WhiteLightning: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS WHITE LIGHTNING";
		descriptionShort = "Full white + black seat.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)","#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)","#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)","#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)","#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)","#(argb,8,8,3)color(0.08,0.08,0.08,1,CO)","#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)"};
	};

	class vg7_scorpion_Rebs_BloodAndChrome: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS BLOOD AND CHROME";
		descriptionShort = "Red tank + silver frame.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)","#(argb,8,8,3)color(0.62,0.64,0.68,1,CO)","#(argb,8,8,3)color(0.62,0.64,0.68,1,CO)","#(argb,8,8,3)color(0.62,0.64,0.68,1,CO)","#(argb,8,8,3)color(0.62,0.64,0.68,1,CO)","#(argb,8,8,3)color(0.08,0.08,0.08,1,CO)","#(argb,8,8,3)color(0.62,0.64,0.68,1,CO)"};
	};

	class vg7_scorpion_Rebs_Route66: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS ROUTE 66";
		descriptionShort = "USA tank + desert-rust frame.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","vg7_scorpion\\vg7_scorpion\\data\\GasTank_USA_CA.paa","#(argb,8,8,3)color(0.36,0.18,0.08,1,CO)","#(argb,8,8,3)color(0.36,0.18,0.08,1,CO)","#(argb,8,8,3)color(0.36,0.18,0.08,1,CO)","#(argb,8,8,3)color(0.36,0.18,0.08,1,CO)","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","#(argb,8,8,3)color(0.20,0.12,0.06,1,CO)"};
	};

	class vg7_scorpion_Rebs_NightRider: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS NIGHT RIDER";
		descriptionShort = "Matte black.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)","#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)","#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)","#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)","#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)","#(argb,8,8,3)color(0.06,0.06,0.06,1,CO)","#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)"};
	};

	class vg7_scorpion_Rebs_Bandidos: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS BANDIDOS";
		descriptionShort = "Red tank + gold frame.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.60,0.02,0.02,1,CO)","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)","#(argb,8,8,3)color(0.10,0.08,0.05,1,CO)","#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)"};
	};

	class vg7_scorpion_Rebs_MongolOrange: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS MONGOL ORANGE";
		descriptionShort = "Orange tank + black OG body.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.90,0.40,0.02,1,CO)","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"};
	};

	class vg7_scorpion_Rebs_ButterflyNight: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS BUTTERFLY NIGHT";
		descriptionShort = "Butterfly tank + black OG.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","vg7_scorpion\\vg7_scorpion\\data\\GasTank_Butterfly_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"};
	};

	class vg7_scorpion_Rebs_MermaidChopper: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS MERMAID CHOPPER";
		descriptionShort = "Mermaid tank + black OG.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","vg7_scorpion\\vg7_scorpion\\data\\GasTank_Mermaid_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"};
	};

	class vg7_scorpion_Rebs_Patriot: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS PATRIOT";
		descriptionShort = "USA tank + red frame.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","vg7_scorpion\\vg7_scorpion\\data\\GasTank_USA_CA.paa","#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)","#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)","#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)","#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)","#(argb,8,8,3)color(0.90,0.90,0.88,1,CO)","#(argb,8,8,3)color(0.05,0.10,0.35,1,CO)"};
	};

	class vg7_scorpion_Rebs_Princess: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS PRINCESS";
		descriptionShort = "Royal purple tank + pink OG frame.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.32,0.05,0.48,1,CO)","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa"};
	};

	class vg7_scorpion_Rebs_ChromeDreams: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS CHROME DREAMS";
		descriptionShort = "Full silver.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)","#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)","#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)","#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)","#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)","#(argb,8,8,3)color(0.10,0.10,0.12,1,CO)","#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)"};
	};

	class vg7_scorpion_Rebs_ScarletWidow: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS SCARLET WIDOW";
		descriptionShort = "Full deep scarlet.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)","#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)","#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)","#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)","#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)","#(argb,8,8,3)color(0.08,0.05,0.05,1,CO)","#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)"};
	};

	class vg7_scorpion_Rebs_DesertRat: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS DESERT RAT";
		descriptionShort = "USA tank + full Ace Rust body.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","vg7_scorpion\\vg7_scorpion\\data\\GasTank_USA_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa","vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa"};
	};

	class vg7_scorpion_Rebs_BlueBlood: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS BLUE BLOOD";
		descriptionShort = "Deep blue procedural.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)","#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)","#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)","#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)","#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)","#(argb,8,8,3)color(0.08,0.08,0.10,1,CO)","#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)"};
	};

	class vg7_scorpion_Rebs_CyberBlue: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS CYBER BLUE";
		descriptionShort = "Cyber blue procedural.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)","#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)","#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)","#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)","#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)","#(argb,8,8,3)color(0.05,0.05,0.08,1,CO)","#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)"};
	};

	class vg7_scorpion_Rebs_ArmyGreen: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS ARMY GREEN";
		descriptionShort = "Army green procedural.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)","#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)","#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)","#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)","#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)","#(argb,8,8,3)color(0.12,0.12,0.10,1,CO)","#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)"};
	};

	class vg7_scorpion_Rebs_AshGrunge: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS ASH GRUNGE";
		descriptionShort = "Ash charcoal procedural.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)","#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)","#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)","#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)","#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)","#(argb,8,8,3)color(0.10,0.10,0.10,1,CO)","#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)"};
	};

	class vg7_scorpion_Rebs_RustGrunge: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS RUST GRUNGE";
		descriptionShort = "Rust brown procedural.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)","#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)","#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)","#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)","#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)","#(argb,8,8,3)color(0.12,0.10,0.08,1,CO)","#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)"};
	};
};
