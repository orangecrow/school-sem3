#include<iostream>
#include<string>
#include"counter.h"
#include<fstream>
int count_words(Counter& cnt, std::istream& source){
	for (std::string word; source >> word; cnt.specialad(word) );
	return 0;
}
int test();
int itest();
int main(){
	itest();
}
int itest() {
	Counter mycounter;
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
	Counter a;
	Counter b = a;
	a=a;
	for(int i=0;i<2;++i)
		a.specialad("asdf");
	a.pnal();
	b=a;
	a.delal();
	Counter* c= new Counter;
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
