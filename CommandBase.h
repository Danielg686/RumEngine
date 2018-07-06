//Command Base
//Daniel Goodrum, Jan 2018

#ifndef COMMANDBASE_H
#define COMMANDBASE_H

class CommandBase
{
public:
	// Note: the Excecute method must NOT have _any_ paramters
	virtual void execute() = 0;


	virtual ~CommandBase() {};
};



#endif // !COMMANDBASE_H
