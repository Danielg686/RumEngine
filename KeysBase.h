//KeysBase
//Daniel Goodrum May 2018

#ifndef _KeysBase
#define _KeysBase

#include "Keyboard.h"

class KeysBase
{
public:
	///---------------------------------------------------------------------
	///\brief BaseClass for LiveKey input and KeyPlayback modes
	///---------------------------------------------------------------------
	KeysBase() = default;
	virtual ~KeysBase() {};

	virtual bool GetKeyState(AZUL_KEY key) = 0;
	virtual void Update() = 0;

private:
	


protected:
	int Frame = 0;
};

struct KeyTracker
{
	int Cycle;
	int Key;
	//AZUL_KEY Key;
};
struct FileHeader
{
	int numberOfEntries;
	int Pad0 = 0;
};

enum KeyInputState
{
	LiveKeys,
	RecordedKeys
};

struct KeyBool
{
	bool KeysPressed[119];
};

struct KeyInt
{
	int checkArray[119]{
		32,
		39,
		44,
		45,
		46,
		47,
		48,
		49,
		50,
		51,
		52,
		53,
		54,
		55,
		56,
		57,
		59,
		61,
		65,
		66,
		67,
		68,
		69,
		70,
		71,
		72,
		73,
		74,
		75,
		76,
		77,
		78,
		79,
		80,
		81,
		82,
		83,
		84,
		85,
		86,
		87,
		88,
		89,
		90,
		91,
		92,
		93,
		96,
		161,
		162,
		GLFW_KEY_UP,
		GLFW_KEY_DOWN,
		GLFW_KEY_LEFT ,
		GLFW_KEY_RIGHT,
		GLFW_KEY_ESC,
		GLFW_KEY_ENTER,
		GLFW_KEY_TAB,
		GLFW_KEY_BACKSPACE,
		GLFW_KEY_INSERT,
		GLFW_KEY_DEL ,
		GLFW_KEY_PAGEUP,
		GLFW_KEY_PAGEDOWN,
		GLFW_KEY_HOME,
		GLFW_KEY_END,
		GLFW_KEY_CAPS_LOCK,
		GLFW_KEY_SCROLL_LOCK,
		GLFW_KEY_KP_NUM_LOCK,
		GLFW_KEY_PAUSE,
		GLFW_KEY_F1,
		GLFW_KEY_F2,
		GLFW_KEY_F3,
		GLFW_KEY_F4,
		GLFW_KEY_F5,
		GLFW_KEY_F6,
		GLFW_KEY_F7,
		GLFW_KEY_F8,
		GLFW_KEY_F9,
		GLFW_KEY_F10,
		GLFW_KEY_F11,
		GLFW_KEY_F12,
		GLFW_KEY_F13,
		GLFW_KEY_F14,
		GLFW_KEY_F15,
		GLFW_KEY_F16,
		GLFW_KEY_F17,
		GLFW_KEY_F18,
		GLFW_KEY_F19,
		GLFW_KEY_F20,
		GLFW_KEY_F21,
		GLFW_KEY_F22,
		GLFW_KEY_F23,
		GLFW_KEY_F24,
		GLFW_KEY_F25,
		GLFW_KEY_KP_0,
		GLFW_KEY_KP_1,
		GLFW_KEY_KP_2,
		GLFW_KEY_KP_3,
		GLFW_KEY_KP_4,
		GLFW_KEY_KP_5,
		GLFW_KEY_KP_6,
		GLFW_KEY_KP_7,
		GLFW_KEY_KP_8,
		GLFW_KEY_KP_9,
		GLFW_KEY_KP_DECIMAL,
		GLFW_KEY_KP_DIVIDE,
		GLFW_KEY_KP_MULTIPLY,
		GLFW_KEY_KP_SUBTRACT,
		GLFW_KEY_KP_ADD,
		GLFW_KEY_KP_ENTER,
		GLFW_KEY_KP_EQUAL,
		GLFW_KEY_LSHIFT,
		GLFW_KEY_LCTRL,
		GLFW_KEY_LALT,
		GLFW_KEY_LSUPER,
		GLFW_KEY_RSHIFT,
		GLFW_KEY_RCTRL,
		GLFW_KEY_RALT,
		GLFW_KEY_RSUPER,
		GLFW_KEY_MENU };
};


#endif // !_KeysBase
