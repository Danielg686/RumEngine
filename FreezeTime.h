// FreezeTime
// Andre Berthiaume, Jan 2016

#ifndef _FreezeTime
#define _FreezeTime

#include "AzulCore.h"

class FreezeTime
{
private:
	/// \brief Freezes all game functionality, press again to unfreeze
	static const AZUL_KEY FREEZE_KEY = AZUL_KEY::KEY_F10;
	/// \brief Step Frame by Frame through the game.
	static const AZUL_KEY SINGLE_FRAME_KEY = AZUL_KEY::KEY_F9;

	float totalFrozenTime;
	bool freeze_mode_active;

	float WaitAndReturnFrozenTime(float activetime);
	bool HackedKeyRelease(AZUL_KEY k);

public:
	FreezeTime();
	~FreezeTime() {};
	FreezeTime(const FreezeTime&) = delete;
	FreezeTime& operator=(const FreezeTime&) = delete;

	float GetTimeInSeconds(float sys_time);
};

#endif _FreezeTime