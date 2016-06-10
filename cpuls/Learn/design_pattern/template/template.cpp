
#include "hummermodel.h"
#include "hummerh1model.h"
#include "hummerh2model.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "ph1 model ..." << endl;
	CHummerModel *ph1= new CHummerH1Model();
	ph1->Run();
	delete ph1;

	cout << "ph2 model ..." << endl;
	CHummerModel *ph2= new CHummerH2Model();
	ph2->Run();
	delete ph2;

	cout << "ph11 model ..." << endl;
	CHummerH1Model *ph11= new CHummerH1Model();
	ph11->SetAlarm(false);
	ph11->Run();
	delete ph11;
	
	return 0;
}
