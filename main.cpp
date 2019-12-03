#include<iostream>
#include<string>
#include"counter.h"
int test();
int main(){
	test();
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
