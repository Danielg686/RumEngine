//Daniel Goodrum May 2018
//KeyPlayback

#ifndef _KeyPlayback
#define _KeyPlayback


#include "KeysBase.h"
#include <iostream>
#include <fstream>
#include <list>

class KeyPlayback : public virtual KeysBase
{
public:
	///-------------------------------------------------------------------------
	/// \brief called when started in Playback Mode
	///-------------------------------------------------------------------------
	KeyPlayback();
	virtual ~KeyPlayback();
	virtual void Update() override;
	///-------------------------------------------------------------------------
	/// \brief called from the KeypressLogging system to get apropriate key information
	///-------------------------------------------------------------------------
	virtual bool GetKeyState(AZUL_KEY key) override;

private:

	void clear();

	FILE* inputFile;

	const char* infilename;

	std::list<KeyTracker*> Keylist;

	std::list<KeyTracker*> FrameList;

	std::list<KeyTracker*>::const_iterator ListIterator;

	int linecount = 0;
};


#endif // !_KeyPlayback
