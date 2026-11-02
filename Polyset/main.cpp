#include "searchable_bag.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"

#include <iostream>

static void test_set() {
	searchable_array_bag base;
	set s(base);

	std::cout << "--- test_set ---" << std::endl;

	int a1[] = {1, 1, 2};
	s.insert(a1, 3);
	std::cout << "esperado: 1 2   | obtido: ";
	s.print();

	s.clear();
	int a2[] = {1, 2, 2};
	s.insert(a2, 3);
	std::cout << "esperado: 1 2   | obtido: ";
	s.print();

	s.clear();
	s.insert(5);
	int a3[] = {5, 6, 5, 7};
	s.insert(a3, 4);
	std::cout << "esperado: 5 6 7 | obtido: ";
	s.print();

	s.clear();
	s.insert(3);
	s.insert(3);
	s.insert(a1, 0);
	std::cout << "esperado: 3     | obtido: ";
	s.print();

	std::cout << "has(3) esperado 1 | obtido: " << s.has(3) << std::endl;
	std::cout << "has(4) esperado 0 | obtido: " << s.has(4) << std::endl;

	const set cs(base);
	std::cout << "const get_bag esperado: 3 | obtido: ";
	cs.get_bag().print();

	set s2(s);
	s2.insert(9);
	set s3(base);
	s3 = s;
	s3.insert(10);
	std::cout << "copia/atribuicao esperado: 3 9 10 | obtido: ";
	base.print();
}

int main(int argc, char **argv) {
  if (argc == 1)
    return 1;
  searchable_bag *t = new searchable_tree_bag;
  searchable_bag *a = new searchable_array_bag;

  for (int i = 1; i < argc; i++) {
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));
  }
  t->print();
  a->print();

  for (int i = 1; i < argc; i++) {
    std::cout << t->has(atoi(argv[i])) << std::endl;
    std::cout << a->has(atoi(argv[i])) << std::endl;
    std::cout << t->has(atoi(argv[i]) - 1) << std::endl;
    std::cout << a->has(atoi(argv[i]) - 1) << std::endl;
  }

  t->clear();
  a->clear();

  const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
  tmp.print();
  tmp.has(1);

  set sa(*a);
  set st(*t);
  for (int i = 1; i < argc; i++) {
    st.insert(atoi(argv[i]));
    sa.insert(atoi(argv[i]));

    sa.has(atoi(argv[i]));
    sa.print();
    sa.get_bag().print();
    st.print();
    sa.clear();
    sa.insert(
        (int[]){
            1,
            2,
            3,
            4,
        },
        4);
    std::cout << std::endl;
  }

  test_set();

  return 0;
}
