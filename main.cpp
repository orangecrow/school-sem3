<<<<<<< HEAD
#include"sequence.h"
int main(){
	Sequence<int> a;
	Sequence<int> b = a;
	a=a;
	for(int i=0;i<12;++i)
		a.ad(i);
	a.pnal();
	b=a;
	a.delal();
	Sequence<int>* c= new Sequence<int>;
	c->ad(100);
	b.pnal();
	c->pnal();
	a.pnal();
}

/*
int count_words(counter<string>& cnt, istream& source){
=======
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


int test(){
	Counter<std::string> a;
	Counter<std::string> b = a;
	a=a;
	for(int i=0;i<2;++i)
		a.specialad("asdf");
	a.pnal();
	b=a;
	a.delal();
	Counter<std::string>* c= new Counter<std::string>;
	c->ad("qewr");
	c->pnal();
	b.pnal();
	c->pnal();
	a.pnal();
	delete c;
}

/*
int count_words(counter<std::string>& cnt, istream& source){
>>>>>>> counter
return 0;
}
*/
