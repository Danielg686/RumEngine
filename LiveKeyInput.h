//Daniel Goodrum May2018
//LiveKeyInput

#ifndef _LiveKeyInput
#define _LiveKeyInput

#include "KeysBase.h"
#include <iostream>
#include <list>

class LiveKeyInput : public virtual KeysBase
{
public:
	///------------------------------------------------------------
	///\brief called when started in LiveKey Mode
	///------------------------------------------------------------
	LiveKeyInput();
	virtual ~LiveKeyInput();
	virtual void Update() override;
	///-------------------------------------------------------------------------
	/// \brief called from the KeypressLogging system to get apropriate key information
	///-------------------------------------------------------------------------
	virtual bool GetKeyState(AZUL_KEY key) override;

private:

	void clear();

	
	FILE* outputFile;

	const char* ofilename;

	std::list<KeyTracker*> Keylist;
};


#endif // !_LiveKeyInput
