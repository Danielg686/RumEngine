//TimeManagerAttorney
//Daniel Goodrum

#ifndef TIMEMANAGERATTORNEY_H
#define TIMEMANAGERATTORNEY_H

#include "TimeManager.h"

class TimeManagerAttorney
{
public:
	class GameLoop
	{
	private: 
		friend class RumEngine;

		///		\brief Passthrough for the Engine to delete the TimeManager.
		static void Delete() { TimeManager::Delete(); };

		///		\brief Passthrough for the Engine to access TimeManager process time.
		static void ProcessTime(float sys_time) { TimeManager::ProcessTime(sys_time); }
	};




};






#endif // !TIMEMANAGERATTORNEY_H
