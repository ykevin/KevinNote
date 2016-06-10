
#pragma once

class IGroup{
	public :
		IGroup() {}
		virtual ~IGroup() {}
		virtual void Find() = 0;
		virtual void Add() = 0;
		virtual void Delete() = 0;
		virtual void Change() = 0;
		virtual void Plan() = 0;	
};
