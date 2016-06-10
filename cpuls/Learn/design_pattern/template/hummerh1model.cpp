
#include "hummerh1model.h"
#include <iostream>

using namespace std;

CHummerH1Model::CHummerH1Model()
{
	m_isAlarm = true;
}

CHummerH1Model::~CHummerH1Model()
{

}

void CHummerH1Model::Start()
{
	cout << "Hummer H1 Start..." << endl;
}

void CHummerH1Model::Stop()
{
	cout << "Hummer H1 Stop..." << endl;
}

void CHummerH1Model::Alarm()
{
	cout << "Hummer H1 Alarm..." << endl;
}

void CHummerH1Model::EngineBoom()
{
	cout << "Hummer H1 voice..." << endl;
}

bool CHummerH1Model::IsAlarm()
{
	return this->m_isAlarm;
}

void CHummerH1Model::SetAlarm(bool tag)
{
	this->m_isAlarm = tag;
}

