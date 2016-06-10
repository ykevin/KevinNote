
#include  "iterator.hpp"

int main()
{
	//ConcreteAggregate *pName = NULL;
	ConcreteAggregate *pName = new ConcreteAggregate();
	if(NULL != pName)
	{
		pName->Push("Hello");
		pName->Push("word");
		pName->Push("kevin");
	}

	Iterator *iter = NULL;
	iter = pName->CreateIterator();
	if(NULL != iter)
	{
		string strItem = iter->First();
		while(!iter->IsEnd())
		{
			cout << iter->GetCur() << " is ok " << endl;
			iter->Next();
		}
	}

	delete pName;

	return 0;
}
