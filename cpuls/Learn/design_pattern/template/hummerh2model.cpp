
#include "hummerh2model.h"
#include <iostream>

using namespace std;

CHummerH2Model::CHummerH2Model()
{

}

CHummerH2Model::~CHummerH2Model()
{

}

void CHummerH2Model::Start()
{
	cout << "Hummer H2 Start..." << endl;
}

void CHummerH2Model::Stop()
{
	cout << "Hummer H2 Stop..." << endl;
}

void CHummerH2Model::Alarm()
{
	cout << "Hummer H2 Alarm..." << endl;
}

void CHummerH2Model::EngineBoom()
{
	cout << "Hummer H2 voice..." << endl;
}

bool CHummerH2Model::IsAlarm()
{
	return false;
}

