#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) :
	tree_bag(other) {}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other){
	tree_bag::operator=(other);
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag() {}

bool searchable_tree_bag::has(int x) const{
	node *temp = tree;

	while (temp != nullptr){
		if (temp->value == x)
			return true;
		else if (temp->value > x && temp->l != nullptr)
			temp = temp->l;
		else if (temp->value < x && temp->r != nullptr)
			temp = temp->r;
		else
			return false;
	}
	return false;
}
