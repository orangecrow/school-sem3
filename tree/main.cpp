#include"tree2.h"
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
	a.add(13,"sf");
	a.add(17,"sf");
	a.add(33,"sf");
	a.add(63,"sf");
	a.print();
	std::cout << "\n-------------------------\n";
	a.remove(19);
	a.remove(17);
	a.remove(13);
	a.remove(4);
	a.print();
	std::cout << "\n-------------------------\n";
	/*a.testfunc2();
	a.print();
	std::cout << "\n-------------------------\n";
	a.add(5,"sf");
	a.add(32,"sf");
	a.add(22,"sf");
	a.add(222,"sf");
	a.add(21,"sf");
	a.print();
	std::cout << "\n-------------------------\n";
	a.testfunc3(32);
	a.print();
	std::cout << "\n-------------------------\n";
	a.testfunc3(23);
	a.print();
	std::cout << "\n-------------------------\n";
	a.usr_remove(19);
	a.usr_remove(21);
	a.usr_remove(22);
	a.usr_remove(33);
	a.usr_remove(39);
	a.print();
	std::cout << "\n-------------------------\n";
	*/
	return;
}

