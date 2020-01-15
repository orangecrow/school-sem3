#include"tree.h"
void test1();
int main(){
	test1();
	return 0;
}
void test1(){ // add print and rotate test
	Tree a;
	a.add(39,"root");
	a.add(4,"h");
	a.add(2,"sf");
	a.add(3,"sf");
	a.add(123,"sf");
	a.add(23,"sf");
	a.add(51,"sf");
	a.add(19,"sf");
	a.print();
	std::cout << "\n-------------------------\n";
	a.testfunc();
	a.print();
	std::cout << "\n-------------------------\n";
	a.testfunc2();
	a.print();
	std::cout << "\n-------------------------\n";
	a.testfunc2();
	a.print();
	std::cout << "\n-------------------------\n";
	a.add(13,"sf");
	a.add(17,"sf");
	a.add(33,"sf");
	a.add(63,"sf");
	a.print();
	return;
}

