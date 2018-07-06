#include "SceneRegistrationBroker.h"
#include "CommandBase.h"

SceneRegistrationBroker::~SceneRegistrationBroker()
{
	CommandList.clear();
	DebugMsg::out("Scene Registration Broker class destructor called\n"); 
}

void SceneRegistrationBroker::addCommands(CommandBase * cmd)
{
	CommandList.push_back(cmd);
}

void SceneRegistrationBroker::executeCommands()
{
	for (listCommands::const_iterator it = CommandList.begin(); it != CommandList.end(); it++)
	{
		(*it)->execute();
	}

	CommandList.clear();
}
