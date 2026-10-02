// Original mod already defines this class – we ONLY mod it.
modded class ActionToggleVG7SCORPIONSmokeScreen
{
	override string GetText()
	{
		HumanCommandVehicle vehCommand = GetGame().GetPlayer().GetCommand_Vehicle();
		if (vehCommand)
		{
			Transport trans = vehCommand.GetTransport();
			vg7_scorpion scorpion;
			if (Class.CastTo(scorpion, trans))
			{
				if (scorpion.VG7SCORPIONSmokeScreenStatus())
					return "Disable Smoke Screen";
			}
		}
		return "Enable Smoke Screen";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
		if (!vehCommand)
			return false;

		Transport trans = vehCommand.GetTransport();
		if (!trans)
			return false;

		vg7_scorpion scorpion;
		if (!Class.CastTo(scorpion, trans))
			return false;

		if (scorpion.CrewMemberIndex(player) != DayZPlayerConstants.VEHICLESEAT_DRIVER)
			return false;

		// Smoke only while engine is running
		return scorpion.EngineIsOn();
	}
};
