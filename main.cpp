#include"sequence.h"
#include<iostream>
#include<string>
#include"counter.h"
#include<fstream>
int count_words(Counter<std::string>&, std::istream&);
int test();
int itest();
int stest();    
int main(){
}
int itest() {
	Counter<std::string> mycounter;
	std::ifstream fs;
	fs.open("test.txt");
	if (fs.is_open())
	{
		std::istream& is = fs;
		count_words(mycounter,is);
		fs.close();
	}
	mycounter.pnal();
	return 0;
}


int ctest(){
	Counter<std::string> a;
	Counter<std::string> b = a;
	a=a;
	for(int i=0;i<2;++i)
		a.specialad("asdf");
	a.pnal();
	b=a;
	a.usr_del();
	Counter<std::string>* c= new Counter<std::string>;
	c->specialad("qewr");
	c->pnal();
	b.pnal();
	c->pnal();
	a.pnal();
	delete c;
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
	delete c;
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
}
