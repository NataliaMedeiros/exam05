#include "set.hpp"

set::set() : _bag(nullptr) {}

set::set(searchable_bag& b) : _bag(&b) {}

set::set(const set& other) : _bag(other._bag) {}

set& set::operator=(const set& other){
	_bag = other._bag;
	return (*this);
}

set::~set() {}

void set::insert (int n){
	if (_bag->has(n) == false)
		_bag->insert(n);
}

void set::insert (int *x, int y){
	for(int i = 0; i < y; i++){
		if (!(_bag->has(x[i])))
			_bag->insert(x[i]);
	}
}

void set::print() const{
	_bag->print();
}

void set::clear(){
	_bag->clear();
}

bool set::has(int x) const{
	return (_bag->has(x));
}

const searchable_bag& set::get_bag()const {
	return (*_bag);
}
