#pragma once

#include "searchable_bag.hpp"

class set : public searchable_bag {
	private:
		searchable_bag *_bag;
	public:
		set();
		set(searchable_bag& b);
		set(const set& other);
		set& operator=(const set& other);
		~set();

		void insert (int n);
		void insert (int *x, int y);
		void print() const;
		void clear();
		bool has(int x) const;

		const searchable_bag& get_bag() const;
};
