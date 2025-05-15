//! A moderately generic class
//! Changes game's master volume
//! Any number works for a level of suppression
class flabby_Earplugs
{
	static int earplug_suppressed = 0;
	//! Constructor taking in the suppression percantage
	static void suppressAll(int suppressionPercentage)
	{
		// Identify suppression amount
		if (earplug_suppressed > 75)
		{
			earplug_suppressed = 0;
		}
		else
		{
			earplug_suppressed = earplug_suppressed + suppressionPercentage;
		}
		
		// Show message
		PlayerController pc = GetGame().GetPlayerController();
		if (!pc)
			return;
		SCR_ChatComponent cc = SCR_ChatComponent.Cast(pc.FindComponent(SCR_ChatComponent));
		if (!cc)
			return;

		cc.ShowMessage(LocalizedString.Format(WidgetManager.Translate("#flabby_DynamicMessage", earplug_suppressed)));
		
		// Suppression of all audio
		AudioSystem.SetMasterVolume(AudioSystem.SFX, AudioSystem.GetMasterVolume(AudioSystem.SFX) - earplug_suppressed);
		AudioSystem.SetMasterVolume(AudioSystem.Music, AudioSystem.GetMasterVolume(AudioSystem.Music) - earplug_suppressed);
		AudioSystem.SetMasterVolume(AudioSystem.VoiceChat, AudioSystem.GetMasterVolume(AudioSystem.VoiceChat) - earplug_suppressed);
		AudioSystem.SetMasterVolume(AudioSystem.Dialog, AudioSystem.GetMasterVolume(AudioSystem.Dialog) - earplug_suppressed);
		AudioSystem.SetMasterVolume(AudioSystem.UI, AudioSystem.GetMasterVolume(AudioSystem.UI) - earplug_suppressed);
	}
}
