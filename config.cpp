class CfgPatches
{
	class Rebs_Scorpion_1_3_Fix
	{
		units[] =
		{
			"vg7_scorpion_Rebs_Princess",
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
			"vg7_scorpion_Rebs_BlueBlood",
			"vg7_scorpion_Rebs_CyberBlue",
			"vg7_scorpion_Rebs_ArmyGreen",
			"vg7_scorpion_Rebs_AshGrunge",
			"vg7_scorpion_Rebs_RustGrunge",
			"vg7_scorpion_Rebs_ChromeDreams",
			"vg7_scorpion_Rebs_ScarletWidow",
			"vg7_scorpion_Rebs_DesertRat"
		};
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
		credits = "Original: VectorG7 / DrBlackouts / DeanosBeano | Compatibility + paints: Rebs";
		author = "Rebs";
		authorID = "0";
		version = "1.3.3";
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

/*
	Selection order (all variants):
	0-8  lights / dash (leave empty textures)
	9    tankpaint
	10   rearfender
	11   forks_front_rot
	12   FrameAssembly.001
	13   FrameAssembly.002
	14   Seat
	15   ForkAssemblyGrips

	OG tanks available:
	  GasTank_USA_CA | GasTank_Ace_CA | GasTank_Drifter_CA
	  GasTank_Mermaid_CA | GasTank_Butterfly_CA | GasTank_Ace_Rust_CA
	OG body:
	  Mainbody_CA | Mainbody_Pink_CA | Mainbody_Ace_CA | Mainbody_Ace_Rust_CA
*/

class CfgVehicles
{
	class CarScript;
	class vg7_scorpion: CarScript
	{
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 36;
				increaseSpeed[] = {0,45,60,25,100,10};
				decreaseSpeed[] = {0,80,60,40,100,15};
				centeringSpeed[] = {0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime = 0.85;
				defaultThrust = 0.75;
				gentleThrust = 0.6;
				turboCoef = 3.6;
				gentleCoef = 0.75;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.9,10,0.75,20,0.6,40,0.5,60,0.38,80,0.32,100,0.28,120,0.24,140,0.2};
				reactionTime = 0.15;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.15;
				dragCoefficient = 0.40;
				downforceCoefficient = 0.6;
				downforceOffset[] = {0,0.35,-1.8};
			};
			drive = "DRIVE_AWD";
			class Engine
			{
				torqueCurve[] = {650,0,750,230,1400,260,3400,280,5400,260,8000,0};
				inertia = 0.45;
				frictionTorque = 100;
				rollingFriction = 1.9;
				viscousFriction = 1.1;
				rpmIdle = 850;
				rpmMin = 900;
				rpmClutch = 1500;
				rpmRedline = 6500;
			};
			class Clutch
			{
				maxTorqueTransfer = 280;
				uncoupleTime = 0.25;
				coupleTime = 0.25;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 0.75;
				ratios[] = {3.6,2.35,1.55,1.05};
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 3600;
					maxHandbrakeTorque = 4800;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 2200;
						stiffness = 27000;
						compression = 3200;
						damping = 6200;
						travelMaxUp = 0.16;
						travelMaxDown = 0.15;
					};
				};
				class Rear
				{
					maxBrakeTorque = 2900;
					maxHandbrakeTorque = 5000;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Suspension
					{
						swayBar = 2000;
						stiffness = 24000;
						compression = 3000;
						damping = 6000;
						travelMaxUp = 0.15;
						travelMaxDown = 0.14;
					};
				};
			};
		};
	};

	// ========== 80s RETRO / BIKER GANG MIXES ==========

	// HELLS ANGELS style – blood red tank, black OG body
	class vg7_scorpion_Rebs_HellsAngels: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS HELLS ANGELS";
		descriptionShort = "Blood-red tank on black iron. 80s one-percenter energy.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\dash_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\seat.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\seat.rvmat"
		};
	};

	// EASY RIDER – OG USA tank + black body (Captain America vibes)
	class vg7_scorpion_Rebs_EasyRider: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS EASY RIDER";
		descriptionShort = "Stars and stripes tank on black iron. Ride free.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_USA_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"
		};
	};

	// SONS – Ace tank + blood red frame
	class vg7_scorpion_Rebs_Sons: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS SONS";
		descriptionShort = "Ace of Spades tank on blood-red frame. Clubhouse special.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_Ace_CA.paa",
			"#(argb,8,8,3)color(0.45,0.02,0.02,1,CO)",
			"#(argb,8,8,3)color(0.45,0.02,0.02,1,CO)",
			"#(argb,8,8,3)color(0.45,0.02,0.02,1,CO)",
			"#(argb,8,8,3)color(0.45,0.02,0.02,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"#(argb,8,8,3)color(0.08,0.08,0.08,1,CO)"
		};
	};

	// OUTLAW BLACK – full black iron
	class vg7_scorpion_Rebs_OutlawBlack: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS OUTLAW BLACK";
		descriptionShort = "All black everything. Night runs only.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.04,0.04,0.04,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"#(argb,8,8,3)color(0.08,0.08,0.08,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"
		};
	};

	// DRIFTER FLAME – OG drifter tank + orange/black
	class vg7_scorpion_Rebs_DrifterFlame: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS DRIFTER FLAME";
		descriptionShort = "Drifter art tank, flame-orange frame. Built to slide.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_Drifter_CA.paa",
			"#(argb,8,8,3)color(0.85,0.28,0.04,1,CO)",
			"#(argb,8,8,3)color(0.85,0.28,0.04,1,CO)",
			"#(argb,8,8,3)color(0.85,0.28,0.04,1,CO)",
			"#(argb,8,8,3)color(0.85,0.28,0.04,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"#(argb,8,8,3)color(0.06,0.06,0.06,1,CO)"
		};
	};

	// ACE OF SPADES – full OG Ace look amplified
	class vg7_scorpion_Rebs_AceOfSpades: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS ACE OF SPADES";
		descriptionShort = "Lucky lady. Ace tank, Ace seat, black iron.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_Ace_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"
		};
	};

	// RUST RAT – full OG Ace Rust
	class vg7_scorpion_Rebs_RustRat: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS RUST RAT";
		descriptionShort = "Been through the desert and the desert won.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\dash_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankrustace.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\seat.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\seat.rvmat"
		};
	};

	// PINK LADIES – full OG pink
	class vg7_scorpion_Rebs_PinkLadies: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS PINK LADIES";
		descriptionShort = "Hot pink iron. The girls ride too.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.90,0.25,0.55,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\dash_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\seat.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\seat_pink.rvmat"
		};
	};

	// GOLDEN CHOPPER – 80s gold / show bike
	class vg7_scorpion_Rebs_GoldenChopper: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS GOLDEN CHOPPER";
		descriptionShort = "Show-bike gold. Parking lot king.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)",
			"#(argb,8,8,3)color(0.10,0.08,0.05,1,CO)",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)"
		};
	};

	// WHITE LIGHTNING
	class vg7_scorpion_Rebs_WhiteLightning: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS WHITE LIGHTNING";
		descriptionShort = "Clean white chopper. Looks innocent. Isn't.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)",
			"#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)",
			"#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)",
			"#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)",
			"#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)",
			"#(argb,8,8,3)color(0.08,0.08,0.08,1,CO)",
			"#(argb,8,8,3)color(0.92,0.90,0.85,1,CO)"
		};
	};

	// BLOOD AND CHROME – red tank + silver frame
	class vg7_scorpion_Rebs_BloodAndChrome: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS BLOOD AND CHROME";
		descriptionShort = "Red tank, chrome-silver frame. Classic 80s custom.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)",
			"#(argb,8,8,3)color(0.62,0.64,0.68,1,CO)",
			"#(argb,8,8,3)color(0.62,0.64,0.68,1,CO)",
			"#(argb,8,8,3)color(0.62,0.64,0.68,1,CO)",
			"#(argb,8,8,3)color(0.62,0.64,0.68,1,CO)",
			"#(argb,8,8,3)color(0.08,0.08,0.08,1,CO)",
			"#(argb,8,8,3)color(0.62,0.64,0.68,1,CO)"
		};
	};

	// ROUTE 66 – USA tank + rust-brown frame
	class vg7_scorpion_Rebs_Route66: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS ROUTE 66";
		descriptionShort = "USA tank on desert-rust iron. Cross-country special.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_USA_CA.paa",
			"#(argb,8,8,3)color(0.36,0.18,0.08,1,CO)",
			"#(argb,8,8,3)color(0.36,0.18,0.08,1,CO)",
			"#(argb,8,8,3)color(0.36,0.18,0.08,1,CO)",
			"#(argb,8,8,3)color(0.36,0.18,0.08,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"#(argb,8,8,3)color(0.20,0.12,0.06,1,CO)"
		};
	};

	// NIGHT RIDER – pure black procedural
	class vg7_scorpion_Rebs_NightRider: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS NIGHT RIDER";
		descriptionShort = "Matte black. No chrome, no mercy.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)",
			"#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)",
			"#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)",
			"#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)",
			"#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)",
			"#(argb,8,8,3)color(0.06,0.06,0.06,1,CO)",
			"#(argb,8,8,3)color(0.03,0.03,0.03,1,CO)"
		};
	};

	// BANDIDOS – red + gold
	class vg7_scorpion_Rebs_Bandidos: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS BANDIDOS";
		descriptionShort = "Red tank, gold frame. South-of-the-border heat.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.60,0.02,0.02,1,CO)",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)",
			"#(argb,8,8,3)color(0.10,0.08,0.05,1,CO)",
			"#(argb,8,8,3)color(0.72,0.55,0.10,1,CO)"
		};
	};

	// MONGOL ORANGE – orange tank + black body
	class vg7_scorpion_Rebs_MongolOrange: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS MONGOL ORANGE";
		descriptionShort = "Loud orange tank on black iron.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.90,0.40,0.02,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"
		};
	};

	// BUTTERFLY NIGHT – OG butterfly tank + black
	class vg7_scorpion_Rebs_ButterflyNight: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS BUTTERFLY NIGHT";
		descriptionShort = "Butterfly tank on black iron. Pretty and dangerous.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_Butterfly_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"
		};
	};

	// MERMAID CHOPPER – OG mermaid tank + black
	class vg7_scorpion_Rebs_MermaidChopper: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS MERMAID CHOPPER";
		descriptionShort = "Ocean tank on black iron. Beach club meets biker bar.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_Mermaid_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_CA.paa"
		};
	};

	// PATRIOT – USA tank + red frame
	class vg7_scorpion_Rebs_Patriot: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS PATRIOT";
		descriptionShort = "USA tank, red frame. Fourth of July forever.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_USA_CA.paa",
			"#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)",
			"#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)",
			"#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)",
			"#(argb,8,8,3)color(0.55,0.02,0.02,1,CO)",
			"#(argb,8,8,3)color(0.90,0.90,0.88,1,CO)",
			"#(argb,8,8,3)color(0.05,0.10,0.35,1,CO)"
		};
	};

	// PRINCESS – purple tank + pink frame (kept)
	class vg7_scorpion_Rebs_Princess: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS PRINCESS";
		descriptionShort = "Royal Crown Purple tank on pink frame.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.32,0.05,0.48,1,CO)",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Pink_CA.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat","vg7_scorpion\\vg7_scorpion\\data\\dash_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\seat.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\seat_pink.rvmat"
		};
	};

	// CHROME DREAMS – full silver
	class vg7_scorpion_Rebs_ChromeDreams: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS CHROME DREAMS";
		descriptionShort = "All silver / chrome look. Garage queen.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)",
			"#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)",
			"#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)",
			"#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)",
			"#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)",
			"#(argb,8,8,3)color(0.10,0.10,0.12,1,CO)",
			"#(argb,8,8,3)color(0.70,0.72,0.75,1,CO)"
		};
	};

	// SCARLET WIDOW – deep red full body
	class vg7_scorpion_Rebs_ScarletWidow: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS SCARLET WIDOW";
		descriptionShort = "Deep scarlet all over. Don't get bit.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)",
			"#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)",
			"#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)",
			"#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)",
			"#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)",
			"#(argb,8,8,3)color(0.08,0.05,0.05,1,CO)",
			"#(argb,8,8,3)color(0.40,0.01,0.05,1,CO)"
		};
	};

	// DESERT RAT – USA tank + full Ace rust body
	class vg7_scorpion_Rebs_DesertRat: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS DESERT RAT";
		descriptionShort = "USA tank on full rust body. Survived the wasteland.";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","tankpaint","rearfender","forks_front_rot","FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"vg7_scorpion\\vg7_scorpion\\data\\GasTank_USA_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa",
			"vg7_scorpion\\vg7_scorpion\\data\\Mainbody_Ace_Rust_CA.paa"
		};
	};

	// Keep the solid procedural palette from before
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
		descriptionShort = "Bright cyber blue procedural.";
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
