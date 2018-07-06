//KeypressLogging
//Daniel Goodrum April 2018

#ifndef _KeypressLogging
#define _KeypressLogging

//#include "Keyboard.h"
#include "KeysBase.h"


class KeypressLogging
{
public:
	///----------------------------------------------------------------------------------------
	///\brief Called from GameInitialize to set live key or playback mode
	///\ingroup EXTRAFEATURES
	/// Live Key mode allows player input for control over the game. Playback replays the same inputs used 
	/// from the last Live key run of the game. This should be initialized in the GameInitialize section
	///
	/// par Example:
	/// The following example shows how to initialize the KeypressLogging system
	///		\code
	///			KeypressLogging::Initialize(KeyInputState::LiveKeys);
	///		\endcode
	///-------------------------------------------------------------------------------------------
	static void Initialize(KeyInputState state) { Instance().privInitizlize(state); };
	static void Delete() { Instance().privDelete(); }
	static bool GetKeyState(AZUL_KEY key) { return Instance().privGetKeyState(key); }
	static void Update() { Instance().privUpdate(); }
	
private:
	static KeypressLogging* ptrInstance;


	KeypressLogging() = default;
	KeypressLogging(const KeypressLogging&) = delete;
	KeypressLogging &operator = (const KeypressLogging&) = delete;
	~KeypressLogging();

	static KeypressLogging& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new KeypressLogging;
		}
		return *ptrInstance;
	}

	void privDelete();
	bool privGetKeyState(AZUL_KEY key);
	void privInitizlize(KeyInputState state);
	void privUpdate() { CurrentInput->Update(); }

	KeyInputState CurrentInputState;

	KeysBase* CurrentInput;
	
	
};




#endif // !_KeypressLogging

