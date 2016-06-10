#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Composite
{
	public:
		Composite():_name(""){}
		Composite(string name):_name(name){}
		virtual ~Composite(){}

		virtual void operation()=0;    
		virtual void add(Composite*){}
		virtual void del(Composite*){}
		virtual Composite* find(int index){return NULL;}

	protected:
		string _name;
};

class Leaf : public Composite
{
	public:
		Leaf(){}
		Leaf(string name){_name=name;}
		virtual ~Leaf(){}
		void operation(){cout<< "Leaf---- " << _name<<endl;}
};

class subComposite : public Composite
{
	public:
		subComposite():level(0){}
		subComposite(string name):level(0){_name=name;}
		virtual ~subComposite(){}

		void add(Composite*);
		void del(Composite*);
		Composite* find(int index);
		void operation();

	private:
		vector<Composite*> v_pcom;
		int level;
};

void subComposite::add(Composite* com)
{
	level++;
	v_pcom.push_back(com);

}

void subComposite::del(Composite* com)
{
	v_pcom.pop_back();
}

Composite* subComposite::find(int index)
{
	return v_pcom[index];
}

void subComposite::operation()
{
	for(int i=0;i<level;i++)
		cout<<"+";
	cout<<_name<<endl;
	vector<Composite*>::iterator it;
	for (it=v_pcom.begin();it!=v_pcom.end();it++)
	{
		(*it)->operation();

	}
}

int main()
{
	Composite* psubcom=new subComposite("动物");
	Composite* psubcom1=new subComposite("非哺乳动物");
	Composite* pleaf1=new Leaf("鸟");
	Composite* pleaf2=new Leaf("鱼");
	Composite* psubcom2=new subComposite("哺乳动物");
	Composite* pleaf3=new Leaf("人");    
	psubcom1->add(pleaf1);
	psubcom1->add(pleaf2);
	psubcom2->add(pleaf3);
	psubcom->add(psubcom1);
	psubcom->add(psubcom2);
	psubcom->operation();

	delete pleaf1;
	delete pleaf2;
	delete pleaf3;
	delete psubcom1;
	delete psubcom2;
	delete psubcom;

	return 0;
}
