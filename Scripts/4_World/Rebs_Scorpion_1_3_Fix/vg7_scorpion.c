// Rebs Scorpion 1.3 Fix – proper override only
// Original mod by VectorG7 / DrBlackouts / DeanosBeano
// DayZ 1.29 physics-sleep safe, 1.30 safe
//
// IMPORTANT:
// - Only modded class vg7_scorpion (the real script class from the original).
// - Colour variants in config (mermaid, ace, etc.) that extend vg7_scorpion in
//   script automatically inherit these overrides. Do NOT modded-class names that
//   may not exist as script types in the original mod.
// - Lights use NEW class names (RebsScorpion*) so we never double-declare the
//   original vg7ScorpionFrontLight.

modded class vg7_scorpion
{
	// 1.29+: inactive bodies no longer receive EOnPostSimulate.
	// Keep the body simulated while engine is on OR smoke is requested so
	// exhaust / smoke particles keep updating.
	override void EOnPostSimulate(IEntity other, float timeSlice)
	{
		super.EOnPostSimulate(other, timeSlice);

		#ifndef SERVER
		if (EngineIsOn() || m_VG7SCORPIONSmokeScreenStatus)
		{
			SetRequiredSimulation(true);
		}
		#endif
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		// Original methods – still valid
		VG7SCORPIONSmokeScreen();
		VG7SCORPIONStandUpChopper();

		#ifndef SERVER
		if (m_VG7SCORPIONSmokeScreenStatus && EngineIsOn())
		{
			SetRequiredSimulation(true);
		}
		#endif
	}

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

	// Point the vehicle at our unique yellow light classes (no name clash)
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast(ScriptedLightBase.CreateLight(RebsScorpionFrontLight));
	}

	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast(ScriptedLightBase.CreateLight(RebsScorpionRearLight));
	}
};
