/// Jacob P. Liddy
// JSON implimentation in c++.
// Classes go here.
#pragma once

#include <vector>


struct Object{


	std::string name;
	Value val;
};


struct  Value{

	virtual void print() = 0;

	virtual ~Value = default;
};

struct Array : Value{

	Array(std::vector<Value*> vals)
		: vals(vals);
	{ }

	std::vector<Value*> vals;

	~Array()
}


struct 
