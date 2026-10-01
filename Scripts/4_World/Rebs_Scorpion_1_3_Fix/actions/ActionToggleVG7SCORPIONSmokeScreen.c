class ActionToggleVG7SCORPIONSmokeScreen : ActionInteractBase
{
	void ActionToggleVG7SCORPIONSmokeScreen()
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
		return ActionInputVG7SCORPIONSmokeScreen;
	}

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

		// Driver only + engine must be running for smoke
		if (scorpion.CrewMemberIndex(player) != DayZPlayerConstants.VEHICLESEAT_DRIVER)
			return false;

		return scorpion.EngineIsOn();
	}

	override void OnExecuteServer(ActionData action_data)
	{
		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
		if (!vehCommand)
			return;

		Transport trans = vehCommand.GetTransport();
		if (!trans)
			return;

		vg7_scorpion scorpion;
		if (Class.CastTo(scorpion, trans))
		{
			scorpion.ToggleVG7SCORPIONSmokeScreen();
		}
	}
};
