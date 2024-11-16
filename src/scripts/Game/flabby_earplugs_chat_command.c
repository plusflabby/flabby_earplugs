//! !!!!!!!!!!!! !!
//! Chat command !!
//! !!!!!!!!!!!! !!
class flabby_earplugs_chat_command : ScrServerCommand
{
	protected ScrServerCmdResult HandleCommand(array<string> argv, int playerId = 0)
	{
		if (argv.Count() > 1)
		{
			flabby_Earplugs.earplug_suppressed = 0;
			flabby_Earplugs.suppressAll(string.Format("%1", argv[1]).ToInt());
			return ScrServerCmdResult(string.Empty, EServerCmdResultType.OK);
		}
		return ScrServerCmdResult("ex = /ep 50", EServerCmdResultType.OK);
	}
	
	// Specify keyword of command
	//-----------------------------------------------------------------------------
	override string GetKeyword()
	{
		return "ep";
	}
	
	// Run command server-side
	//-----------------------------------------------------------------------------
	override bool IsServerSide()
	{
		return false;
	}
	
	// Set requirement to admin permission via RCON
	//-----------------------------------------------------------------------------
	override int RequiredRCONPermission()
	{
		return ERCONPermissions.PERMISSIONS_NONE;
	}
	
	// Set requirement to be logged in administrator for chat command
	//-----------------------------------------------------------------------------
	override int RequiredChatPermission()
	{
		return EPlayerRole.NONE;
	}
	
	// Handle Chat command on server
	//-----------------------------------------------------------------------------
	override ref ScrServerCmdResult OnChatServerExecution(array<string> argv, int playerId)
	{
		return ScrServerCmdResult(string.Empty, EServerCmdResultType.OK);
	}
	
	// Handle Chat command on client
	//-----------------------------------------------------------------------------
	override ref ScrServerCmdResult OnChatClientExecution(array<string> argv, int playerId)
	{
		return HandleCommand(argv, playerId);
		
	}
	
	// Handle RCON command on server
	//-----------------------------------------------------------------------------
	override ref ScrServerCmdResult OnRCONExecution(array<string> argv)
	{
		return ScrServerCmdResult(string.Empty, EServerCmdResultType.OK);
	}
	
	// Handle successful result in OnUpdate()
	//-----------------------------------------------------------------------------
	protected ScrServerCmdResult HandleSuccessfulResult()
	{
		return ScrServerCmdResult(string.Empty, EServerCmdResultType.OK);
	}
	
	// Handle Pending command
	//-----------------------------------------------------------------------------
	override ref ScrServerCmdResult OnUpdate()
	{
		return ScrServerCmdResult(string.Empty, EServerCmdResultType.OK);
	}
}