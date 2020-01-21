#include"tree2.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
#include<fstream>
AVLTree<int, std::string> test2(bool,int,int);
int main(){
	test2(0,123,50);
	return 0;
}

int count_words(AVLTree<std::string, int>& cnt, std::istream& source){
	for (std::string word; source >> word; ){
		if(cnt.add(word,1))
			cnt.modInfo(word,cnt.getInfo(word)+1);
	}
}

AVLTree<int, std::string> test2(bool bonus, int seed, int nc){
	AVLTree<int,std::string> a;
	srand(seed);
	int tab[nc];
	int t;
	for ( int i=0 ; i<nc ; ++i){
		t=rand()%(nc*10);
		a.add(t, "wafd");
		tab[i]=t;
		if(bonus){
			a.print(1,1,1);
			std::cout << "\n------------"<< tab[i] <<"-------------\n";
		}
	}
	if(bonus)
		std::cout << "removing" << "\n";
	for ( int i=0 ; i<nc ; ++i){
		t=rand()%nc;
		a.print(1,1,1);
		if(bonus){
			std::cout << "\n------------"<< tab[t] <<"-------------\n";
			a.remove(tab[t]);
		}
	}
	a.print(1,1,1);
	return a;
}

void test1(){
	AVLTree<std::string, int > mycounter;
	std::ifstream fs;
	fs.open("Bible.txt");
	if (fs.is_open())
	{
		std::istream& is = fs;
		count_words(mycounter,is);
		fs.close();
	}
	mycounter.print(1,0,3);
}
