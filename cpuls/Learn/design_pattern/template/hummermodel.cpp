
#include "hummermodel.h"
#include <iostream>

using namespace std;

CHummerModel::CHummerModel()
{

}

CHummerModel::~CHummerModel()
{

}

void CHummerModel::Run()
{
	Start();
	EngineBoom();
	if(IsAlarm())
		Alarm();
	Stop();
}

bool CHummerModel::IsAlarm()
{
	return true;
}
