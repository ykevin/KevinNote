
#include <iostream>
#include "wangpo.hpp"
#include "panjinlian.hpp"

using namespace std;

void DoPanJinLian()
{
	CWangPo *pWangPo;
	pWangPo = new CWangPo(new CPanJinLian());
	pWangPo->MakeEyesWithMan();
	pWangPo->HappyWithMan();
}

int main(void)
{
	DoPanJinLian();
	return 0;
}
