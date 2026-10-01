// Rebs Scorpion 1.3 Fix
// Compatibility override for DayZ 1.29 (stable) and safe for 1.30 Experimental / Badlands
// Original mod by VectorG7 / DrBlackouts / DeanosBeano – this is an override only

modded class vg7_scorpion
{
	// Keep original members – we only touch what is needed for 1.29+ physics sleep & lights

	override void EEInit()
	{
		super.EEInit();
		// Ensure lights use our retro yellow class if the original still creates the old one
	}

	// 1.29+ : inactive bodies no longer receive EOnPostSimulate.
	// Force the body awake while engine is running OR smoke screen is active
	// so exhaust / smoke particles keep updating.
	override void EOnPostSimulate(IEntity other, float timeSlice)
	{
		super.EOnPostSimulate(other, timeSlice);

		#ifndef SERVER
		if (EngineIsOn() || m_VG7SCORPIONSmokeScreenStatus)
		{
			// Keep simulation alive for particle FX (1.29 physics sleep)
			SetRequiredSimulation(true);
		}
		#endif
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		VG7SCORPIONSmokeScreen();
		VG7SCORPIONStandUpChopper();

		#ifndef SERVER
		if (m_VG7SCORPIONSmokeScreenStatus && EngineIsOn())
		{
			SetRequiredSimulation(true);
		}
		#endif
	}

	// Safer smoke toggle – still works when the original FX code runs
	override void ToggleVG7SCORPIONSmokeScreen()
	{
		m_VG7SCORPIONSmokeScreenStatus = !m_VG7SCORPIONSmokeScreenStatus;
		SetSynchDirty();
		VG7SCORPIONSmokeScreen();

		#ifndef SERVER
		if (m_VG7SCORPIONSmokeScreenStatus)
			SetRequiredSimulation(true);
		#endif
	}

	// Retro yellow front light
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionFrontLight));
	}

	// Matching rear light
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionRearLight));
	}

	// Keep original door / crew / attachment logic – it is still valid on 1.29/1.30
	// (locking-cap door, sissy-bar cargo gating, etc.)

	// Optional: slightly safer OnDebugSpawn handguard names for rust variant
	override void OnDebugSpawn()
	{
		super.OnDebugSpawn();

		// The original rust path used non-existent class names in some builds.
		// If the player is spawning the rust variant we try the correct ones.
		if (GetType() == "vg7_scorpion_ace_rust")
		{
			EntityAI entity;
			if (Class.CastTo(entity, this))
			{
				// These match the config classes that actually exist
				entity.GetInventory().CreateInInventory("vg7_scorpion_handguard_rust_left");
				entity.GetInventory().CreateInInventory("vg7_scorpion_handguard_rust_right");
			}
		}
	}
};

// Apply the same light + sleep fix to the colour variants
// (they inherit config from vg7_scorpion but are separate script classes in some builds)

modded class vg7_scorpion_mermaid
{
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionFrontLight));
	}
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionRearLight));
	}
};

modded class vg7_scorpion_butterfly
{
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionFrontLight));
	}
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionRearLight));
	}
};

modded class vg7_scorpion_easyrider
{
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionFrontLight));
	}
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionRearLight));
	}
};

modded class vg7_scorpion_scorcher
{
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionFrontLight));
	}
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionRearLight));
	}
};

modded class vg7_scorpion_ace
{
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionFrontLight));
	}
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionRearLight));
	}
};

modded class vg7_scorpion_ace_rust
{
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionFrontLight));
	}
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast(ScriptedLightBase.CreateLight(vg7ScorpionRearLight));
	}
};
