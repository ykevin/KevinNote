#pragma once

class AbstractProduct {
	public:
		AbstractProduct();
		virtual ~AbstractProduct();
		virtual void operation() = 0;
};

class ProductA:public AbstractProduct {
	public: 
		ProductA();
		virtual ~ProductA();
		void operation();
};

class ProductB:public AbstractProduct {
	public: 
		ProductB();
		virtual ~ProductB();
		void operation();
};
