#include"sequence.h"
#include<iostream>
#include<string>
#include"counter.h"
#include<fstream>
int count_words(Counter<std::string>&, std::istream&);
int stest();    
int stest2();
int stest3();
int ctest();
int ctest2();
int main(){
 stest();    
 stest2();
 stest3();
 ctest();
 ctest2();
}

int ctest2(){
	Counter<std::string> mycounter;
	std::ifstream fs;
	fs.open("test.txt");
	if (fs.is_open())
	{
		std::istream& is = fs;
		count_words(mycounter,is);
		fs.close();
	}
	mycounter.print_all();
	Counter<std::string> a;
	a=mycounter;
	//a.print_all();
	std::cout << a.get_index("reit")<< std::endl;
	std::cout << a.mov_key("reit", 20) << std::endl;
	a.print_all();
	a.print("reit");
	std::cout << a.get_index("reit")<< std::endl;
	std::cout << a.mov_key("toer", -4) << std::endl;
	a.print_all();
	a.usr_ad("holaamigo", 3);
	a.print_all();
	std::cout << "\n======\n";
}
int ctest(){
	Counter<std::string> a;
	Counter<std::string> b = a;
	a=a;
	for(int i=0;i<2;++i)
		a.usr_ad("asdf");
	a.pnal();
	b=a;
	a.usr_del();
	Counter<std::string>* c= new Counter<std::string>;
	c->usr_ad("qewr");
	c->pnal();
	b.pnal();
	c->pnal();
	a.pnal();
    std::cout<<"---\n";
	for(int i=0;i<5;++i)
		a.usr_ad("bhyf");
    b.usr_del();
	for(int i=100;i<105;++i)
		b.usr_ad("nkopytj");
    b.usr_cat(a);
    b.pnal();
	delete c;
	std::cout << "\n======\n";
}
int stest(){
	Sequence<std::string> a;
	Sequence<std::string> b = a;
	a=a;
	for(int i=0;i<2;++i)
		a.usr_ad("asdf");
	a.pnal();
	b=a;
	a.usr_del();
	Sequence<std::string>* c= new Sequence<std::string>;
	c->usr_ad("qewr");
	c->pnal();
	b.pnal();
	c->pnal();
	a.pnal();
    std::cout<<"---\n";
	for(int i=0;i<5;++i)
		a.usr_ad("bhyf");
    b.usr_del();
	for(int i=100;i<105;++i)
		b.usr_ad("nkopytj");
    b.usr_cat(a);
    b.pnal();
	delete c;
	std::cout << "\n======\n";
}
int stest2(){
	Sequence<int> a;
	Sequence<int> b = a;
	a=a;
	for(int i=0;i<12;++i)
		a.usr_ad(i);
	a.pnal();
	b=a;
	a.usr_del();
	Sequence<int>* c= new Sequence<int>;
	c->usr_ad(100);
	b.pnal();
	c->pnal();
	a.pnal();
    std::cout<<'\n';
    std::cout<<'\n';
	for(int i=0;i<5;++i)
		a.usr_ad(i);
    b.usr_del();
	for(int i=100;i<105;++i)
		b.usr_ad(i);
    b.usr_cat(a);
    b.pnal();
	std::cout << "\n======\n";
}
int stest3(){
	Sequence<int> a;
	Sequence<int> b; 
	for(int i=0;i<12;++i)
		a.usr_end_ad(i);
	a.print();
	a.rm_index(0);
	a.print();
	a.rm_index(5);
	a.print();
	a.rm_index(10);
	a.print();
	a.rm_index(9);
	a.print();
	a.usr_ad(100,6);
	a.usr_ad(100,3);
	auto tb = a.search(100);
    std::cout<<'\n';
	a.print();
    std::cout<<"\n where are the hundreds:";
    std::cout<<tb[0] << ','<< tb[1];
    std::cout<<'\n';
	a.rm_val(100);
	a.print();
	std::cout << "\n======\n";
}
	
	
	



















