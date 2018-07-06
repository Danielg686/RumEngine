//Change Scene Command
//Daniel Goodrum April 2018

#ifndef _ChangeSceneCommand
#define _ChangeSceneCommand

#include "CommandBase.h"
class Scene;

class ChangeSceneCommand : public CommandBase
{
public:
	ChangeSceneCommand() = delete;
	ChangeSceneCommand(Scene* S);

	virtual void updateScene(Scene* S);
	virtual void execute() override;


private:
	Scene* newScene;
};

#endif // !_ChangeSceneCommand
