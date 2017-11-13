/// Jacob P. Liddy
// JSON implimentation in c++.
// Classes go here.
#pragma once

#include <vector>
#include <map>

#include <iostream>

struct  Value{

	virtual void print() = 0;

	virtual ~Value() = default; 
};


struct Array : Value{

	Array(std::vector<Value*> vals)
		: vals(vals)
	{ }

	void print() override {
		std::cout << '[';
		for (auto iter = vals.begin(); iter != vals.end(); ++iter){
			(*iter)->print();
			if (std::next(iter) != vals.end())
				std::cout << ", ";
		}
		std::cout << ']';
	}
	
	~Array() override {
		for (val : vals)
			delete val;
	}

	std::vector<Value*> vals;

	
};

struct String : Value {



};

 
struct Object{

	Object() { }

	~Object() { 
		for (auto p : map){
			delete p.first;
			delete p.second;
		}
	}

	void print(){
		std::cout << '{';
		for ( auto iter = map.begin(); iter!= map.end(); ++iter){
			iter->first->print();
			std::cout << " : ";
			iter->second->print();
			if (std::next(iter)!= map.end())
				std::cout << ", ";
		}
		std::cout << "}";
	}

	void add(String* nm, Value* v){
		map.emplace(nm, v);
	}

	std::map<String*, Value*> map;
};


