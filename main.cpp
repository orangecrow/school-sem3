#include<iostream>
#include<string>
#include"counter.h"

int main(){
	Counter a;
	Counter b = a;
	a=a;
	for(int i=0;i<12;++i)
		a.ad("asdf");
	a.pnal();
	b=a;
	a.delal();
	Counter* c= new Counter;
	c->ad("qewr");
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
