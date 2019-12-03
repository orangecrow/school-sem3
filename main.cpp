#include"sequence.h"
#include"sequence.cpp"

int main(){
	Sequence a;
	Sequence b = a;
	a=a;
	for(int i=0;i<12;++i)
		a.ad(i);
	a.pnal();
	b=a;
	a.delal();
	Sequence* c= new Sequence;
	c->ad(100);
	b.pnal();
	c->pnal();
	a.pnal();
}

/*
int count_words(counter<string>& cnt, istream& source){
return 0;
}
*/
