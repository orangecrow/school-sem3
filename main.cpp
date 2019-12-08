#include<iostream>
#include<string>
#include"counter.h"
#include<fstream>
int count_words(Counter<std::string>&, std::istream&);
int test();
int itest();
int main(){
	itest();
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
		a.ad("asdf");
	a.pnal();
	b=a;
	a.usr_del();
	Sequence<std::string>* c= new Sequence<std::string>;
	c->ad("qewr");
	c->pnal();
	b.pnal();
	c->pnal();
	a.pnal();
	delete c;
}

/*
int count_words(counter<std::string>& cnt, istream& source){
return 0;
}
*/
