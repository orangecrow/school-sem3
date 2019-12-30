#include<iostream>
//template<typename key ,typename info>
//struct bar{
//	template <typename T>
//	struct foo{
//		key a;
//		info b;
//		T c;
//	};
//	typedef foo<int> iterator;
//	iterator d;
//};
//void old(){
//	bar<int,char> e;
//	e.d.c=5;
//	std::cout << e.d.c << "\n";
//	bar<int,int>::iterator f;
//	f.a=f.b=f.c=12;
//	std::cout << f.b << f.a << f.c << "\n";
//}
struct foo{
	int a;
	int b;
};
struct bar{
	foo* operator->(){
		a.a=5;
		a.b=6; 
		return &a;
	}
	private:
	foo a;
};
int main(){
	bar a;
	std::cout << a->a << a->b << "\n";
	return 0;
}
