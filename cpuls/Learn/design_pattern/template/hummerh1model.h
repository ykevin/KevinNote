
#pragma once
#include "hummermodel.h"

class CHummerH1Model: public CHummerModel {
	public:
		CHummerH1Model();
		~CHummerH1Model();
		void SetAlarm(bool tag);
		void Start();
		void Stop();
		void Alarm();
		void EngineBoom();
		bool IsAlarm();
	private:
		bool m_isAlarm;
};

