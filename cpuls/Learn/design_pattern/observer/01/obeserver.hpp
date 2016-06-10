
#pragma once

class Subject;

class Obeserver 
{
	public:
		Obeserver() {}
		virtual ~Obeserver() {}
		virtual void update(Subject *sub) = 0;
};
