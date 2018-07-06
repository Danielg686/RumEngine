//Void SceneCommand
//Daniel Goodrum April 2018

#ifndef _VoidSceneCommand
#define _VoidSceneCommand

#include "CommandBase.h"
class Scene;

class VoidSceneCommand : public CommandBase
{
public:
	VoidSceneCommand();

	virtual void execute() override;

};
#endif // !_VoidSceneCommand
