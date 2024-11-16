modded class SCR_BaseGameMode
{
	protected void flabby_ACTION0(float value, EActionTrigger reason)
	{
		// Suppress sound
		flabby_Earplugs.suppressAll(25);
	}
	
	override void EOnInit(IEntity owner)
	{
		super.EOnInit(owner);
		
		GetGame().GetInputManager().AddActionListener("FLABBY_EARPLUGS_ACTION0", EActionTrigger.DOWN, flabby_ACTION0);
	}
}
