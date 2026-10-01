// Keep the original camera offsets – they still work on 1.29 / 1.30
// Only re-declared so the override mod is self-contained if the original camera mod is missing

modded class DayZPlayerCamera3rdPersonVehicle
{
	void DayZPlayerCamera3rdPersonVehicle(DayZPlayer pPlayer, HumanInputController pInput)
	{
		string type = "";
		if (pPlayer && pPlayer.GetCommand_Vehicle() && pPlayer.GetCommand_Vehicle().GetTransport())
		{
			type = pPlayer.GetCommand_Vehicle().GetTransport().GetType();
		}

		if (type == "vg7_scorpion"
			|| type == "vg7_scorpion_easyrider"
			|| type == "vg7_scorpion_scorcher"
			|| type == "vg7_scorpion_mermaid"
			|| type == "vg7_scorpion_butterfly"
			|| type == "vg7_scorpion_ace"
			|| type == "vg7_scorpion_ace_rust")
		{
			m_fDistance      = 4.7;
			m_CameraOffsetMS = "0.0 1.2 0.0";
		}
	}
};
