#include<iostream>
#include<string>
#include"counter.h"

int main(){
	Counter a;
	Counter b = a;
	a=a;
	for(int i=0;i<12;++i)
		a.ad((char)(i+43));
	a.pnal();
	b=a;
	a.delal();
	Counter* c= new Counter;
	c->ad((char)100);
	b.pnal();
	c->pnal();
	a.pnal();
}

/*
int count_words(counter<string>& cnt, istream& source){
return 0;
}
*/
