
#pragma once

class Component {
	public:
		Component();
		virtual ~Component();
		virtual void operation() = 0;
};

class ConcreteComponent: public Component
{
	public:
		ConcreteComponent();
		~ConcreteComponent();

		void operation();
};
