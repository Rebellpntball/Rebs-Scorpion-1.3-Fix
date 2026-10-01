class ActionToggleVG7SCORPIONStandUpChopper : ActionInteractBase
{
	void ActionToggleVG7SCORPIONStandUpChopper()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_HEADLIGHT;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override typename GetInputType()
	{
		return ActionInputVG7SCORPIONStandUpChopper;
	}

	override string GetText()
	{
		return "Stand Up Chopper";
	}

	override bool CanBeUsedInVehicle()
	{
		return true;
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

		return (scorpion.CrewMemberIndex(player) == DayZPlayerConstants.VEHICLESEAT_DRIVER);
	}

	override void OnStartServer(ActionData action_data)
	{
		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
		if (!vehCommand)
			return;

		Transport trans = vehCommand.GetTransport();
		if (!trans)
			return;

		// Call original helper if it exists in the base mod
		// If StandUpChopper class is missing you will get a compile error –
		// either include the original helper or comment this block.
		#ifdef VG7_SCORPION_STANDUP_HELPER
		StandUpChopper.StandItUp(trans);
		#else
		// Fallback: just flip the net-synced flag on the vehicle
		vg7_scorpion scorpion;
		if (Class.CastTo(scorpion, trans))
		{
			scorpion.ToggleVG7SCORPIONStandUpChopper();
		}
		#endif
	}
};
