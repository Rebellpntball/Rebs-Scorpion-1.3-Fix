// Original mod already defines this class – we ONLY mod it if needed.
// Left minimal: original OnStartServer / ActionCondition stay intact.
// Uncomment overrides below only if you need to change behaviour.
modded class ActionToggleVG7SCORPIONStandUpChopper
{
	// Example: force driver-only (usually already true in original)
	/*
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

		return (scorpion.CrewMemberIndex(player) == DayZPlayerConstants.VEHICLESEAT_DRIVER);
	}
	*/
};
