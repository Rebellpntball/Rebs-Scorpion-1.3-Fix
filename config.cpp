class CfgPatches
{
	class Rebs_Scorpion_1_3_Fix
	{
		units[] =
		{
			"vg7_scorpion_Rebs_Princess",
			"vg7_scorpion_Rebs_BlueBlood",
			"vg7_scorpion_Rebs_CyberBlue",
			"vg7_scorpion_Rebs_ArmyGreen",
			"vg7_scorpion_Rebs_AshGrunge",
			"vg7_scorpion_Rebs_RustGrunge"
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
		credits = "Original: VectorG7 / DrBlackouts / DeanosBeano | Compatibility: Rebs";
		author = "Rebs";
		authorID = "0";
		version = "1.3.2";
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

// -------------------------------------------------------------
// Handling + procedural colour variants
// Procedural textures use the same #(argb,8,8,3)color(...) form
// as your FDZ shemaghs – solid colour, no extra .paa needed.
// -------------------------------------------------------------
class CfgVehicles
{
	class CarScript;
	class vg7_scorpion: CarScript
	{
		// Mild Fat-Boy inspired handling pass (keeps Scorpion identity).
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

	// Shared selection list for all procedural variants
	// 0-8 lights | 9 tank | 10 rearfender | 11 forks | 12-13 frame | 14 seat | 15 grips

	// -----------------------------------------------------------------
	// PRINCESS – Royal Crown Purple tank + pink frame (original pink paa)
	// Purple RGB matches your FDZ_Shemagh_RoyalCrownPurple
	// -----------------------------------------------------------------
	class vg7_scorpion_Rebs_Princess: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS PRINCESS";
		descriptionShort = "Royal Crown Purple tank on a pink frame. Procedural + original mix.";
		hiddenSelections[] =
		{
			"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2",
			"light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard",
			"tankpaint","rearfender","forks_front_rot",
			"FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"
		};
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
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\scorpion_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\dash_lights_off.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetal.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\tankscratchmetalpink.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\seat.rvmat",
			"vg7_scorpion\\vg7_scorpion\\data\\seat_pink.rvmat"
		};
	};

	// -----------------------------------------------------------------
	// BLUE BLOOD – full procedural body (your shemagh blue)
	// -----------------------------------------------------------------
	class vg7_scorpion_Rebs_BlueBlood: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS BLUE BLOOD";
		descriptionShort = "Deep blue procedural paint. Same RGB as FDZ Blue Blood shemagh.";
		hiddenSelections[] =
		{
			"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2",
			"light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard",
			"tankpaint","rearfender","forks_front_rot",
			"FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"
		};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)",
			"#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)",
			"#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)",
			"#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)",
			"#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)",
			"#(argb,8,8,3)color(0.08,0.08,0.10,1,CO)",
			"#(argb,8,8,3)color(0.05,0.16,0.42,1,CO)"
		};
	};

	// -----------------------------------------------------------------
	// CYBER BLUE
	// -----------------------------------------------------------------
	class vg7_scorpion_Rebs_CyberBlue: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS CYBER BLUE";
		descriptionShort = "Bright cyber blue procedural paint.";
		hiddenSelections[] =
		{
			"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2",
			"light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard",
			"tankpaint","rearfender","forks_front_rot",
			"FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"
		};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)",
			"#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)",
			"#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)",
			"#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)",
			"#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)",
			"#(argb,8,8,3)color(0.05,0.05,0.08,1,CO)",
			"#(argb,8,8,3)color(0.02,0.45,0.85,1,CO)"
		};
	};

	// -----------------------------------------------------------------
	// ARMY GREEN
	// -----------------------------------------------------------------
	class vg7_scorpion_Rebs_ArmyGreen: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS ARMY GREEN";
		descriptionShort = "Army green procedural paint.";
		hiddenSelections[] =
		{
			"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2",
			"light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard",
			"tankpaint","rearfender","forks_front_rot",
			"FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"
		};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)",
			"#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)",
			"#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)",
			"#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)",
			"#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)",
			"#(argb,8,8,3)color(0.12,0.12,0.10,1,CO)",
			"#(argb,8,8,3)color(0.24,0.30,0.16,1,CO)"
		};
	};

	// -----------------------------------------------------------------
	// ASH GRUNGE
	// -----------------------------------------------------------------
	class vg7_scorpion_Rebs_AshGrunge: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS ASH GRUNGE";
		descriptionShort = "Ash / charcoal procedural paint.";
		hiddenSelections[] =
		{
			"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2",
			"light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard",
			"tankpaint","rearfender","forks_front_rot",
			"FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"
		};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)",
			"#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)",
			"#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)",
			"#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)",
			"#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)",
			"#(argb,8,8,3)color(0.10,0.10,0.10,1,CO)",
			"#(argb,8,8,3)color(0.18,0.18,0.18,1,CO)"
		};
	};

	// -----------------------------------------------------------------
	// RUST GRUNGE
	// -----------------------------------------------------------------
	class vg7_scorpion_Rebs_RustGrunge: vg7_scorpion
	{
		scope = 2;
		displayName = "BLACKOUTS SCORPION REBS RUST GRUNGE";
		descriptionShort = "Rust brown procedural paint.";
		hiddenSelections[] =
		{
			"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2",
			"light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard",
			"tankpaint","rearfender","forks_front_rot",
			"FrameAssembly.001","FrameAssembly.002","Seat","ForkAssemblyGrips"
		};
		hiddenSelectionsTextures[] =
		{
			"","","","","","","","","",
			"#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)",
			"#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)",
			"#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)",
			"#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)",
			"#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)",
			"#(argb,8,8,3)color(0.12,0.10,0.08,1,CO)",
			"#(argb,8,8,3)color(0.36,0.14,0.05,1,CO)"
		};
	};
};
