//Scene Registration Broker
//Daniel Goodrum, Jan 2018

#ifndef SCENEREGISTRATIONBROKER_H
#define SCENEREGISTRATIONBROKER_H

#include "AzulCore.h"
#include <list>

class CommandBase;

class SceneRegistrationBroker
{
public:
	SceneRegistrationBroker() = default;
	~SceneRegistrationBroker();
	SceneRegistrationBroker(const SceneRegistrationBroker&) = delete;
	SceneRegistrationBroker& operator = (const SceneRegistrationBroker&) = delete;

	void addCommands(CommandBase* cmd);
	void executeCommands();

private:
	using listCommands = std::list<CommandBase*>;
	listCommands CommandList;


protected:

};


#endif // !SCENEREGISTRATIONBROKER_H
