#include"tree2.h"
#include<cstdlib>
#include<time.h>
#include<chrono>
#include<iostream>
#include<fstream>
#include<map>
#include<iterator>
template <typename T>
T loadtext();
AVLTree<int, std::string> rendTest(bool,int,int);
	void timeTest();
int main(){
	rendTest(0,123,50);
	timeTest();
}
void timeTest(){
	std::string tab[]= {"for","the","love","of","God","Jesus"};
	auto t1= std::chrono::high_resolution_clock::now();
	auto tree = loadtext<AVLTree<std::string, int>>();
	auto t2= std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds> (t2 -t1).count();
	std::cout << "time of tree load\t:" << duration << "ms\n";

	t1= std::chrono::high_resolution_clock::now();
	auto map = loadtext<std::map<std::string, int>>();
	t2= std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds> (t2 -t1).count();
	std::cout << "time of map load\t:" << duration << "ms\n";

	std::cout << "amount of elements:" << tree.count() << "\n";

	std::cout << "time of tree getInfoOld\t:";
	for(int i=0;i<6;++i){
		t1= std::chrono::high_resolution_clock::now();
		tree.getInfoOld(tab[i]);
		t2= std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds> (t2 -t1).count();
		std::cout << duration << " | ";
	}
	std::cout  << "ns\n";

	std::cout << "time of tree getInfo\t:" ;
	for(int i=0;i<6;++i){
		t1= std::chrono::high_resolution_clock::now();
		tree.getInfo(tab[i]);
		t2= std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds> (t2 -t1).count();
		std::cout << duration << " | ";
	}
	std::cout  << "ns\n";

	std::cout << "time of map find    \t:" ;
	for(int i=0;i<6;++i){
		t1= std::chrono::high_resolution_clock::now();
		map.find(tab[i]);
		t2= std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds> (t2 -t1).count();
		std::cout << duration << " | ";
	}
	std::cout  << "ns\n";

	std::cout << "time of tree check\t:" ;
	for(int i=0;i<6;++i){
		t1= std::chrono::high_resolution_clock::now();
		tree.check(tab[i]);
		t2= std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds> (t2 -t1).count();
		std::cout << duration << " | ";
	}
	std::cout  << "ns\n";

	std::cout << "time of map count\t:" ;
	for(int i=0;i<6;++i){
		t1= std::chrono::high_resolution_clock::now();
		map.count(tab[i]);
		t2= std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds> (t2 -t1).count();
		std::cout << duration << " | ";
	}
	std::cout  << "ns\n";

	std::cout << "time of map erase \t:" ;
	for(int i=0;i<6;++i){
		t1= std::chrono::high_resolution_clock::now();
		map.erase(tab[i]);
		t2= std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds> (t2 -t1).count();
		std::cout << duration << " | ";
	}
	std::cout  << "ns\n";

	std::cout << "time of tree remove \t:" ;
	for(int i=0;i<6;++i){
		t1= std::chrono::high_resolution_clock::now();
		tree.remove(tab[i]);
		t2= std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds> (t2 -t1).count();
		std::cout << duration << " | ";
	}
	std::cout  << "ns\n";

	std::cout << "time of tree add\t:" ;
	for(int i=0;i<6;++i){
		t1= std::chrono::high_resolution_clock::now();
		tree.add(tab[i], 1);
		t2= std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds> (t2 -t1).count();
		std::cout << duration << " | ";
	}
	std::cout  << "ns\n";
	
	std::cout << "time of map insert \t:" ;
	for(int i=0;i<6;++i){
		t1= std::chrono::high_resolution_clock::now();
		map.insert(std::make_pair(tab[i],1));
		t2= std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds> (t2 -t1).count();
		std::cout << duration << " | ";
	}
	std::cout  << "ns\n";
}

AVLTree<int, std::string> rendTest(bool bonus, int seed, int nc){
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
		if(bonus){
			a.print(1,1,1);
			std::cout << "\n------------"<< tab[t] <<"-------------\n";
		}
		t=rand()%nc;
		a.remove(tab[t]);
	}
	a.print(1,1,1);
	return a;
}

int count_words(AVLTree<std::string, int>& cnt, std::istream& source){
	for (std::string word; source >> word; ){
		if(cnt.add(word,1))
			cnt.modInfo(word,cnt.getInfo(word)+1);
	}
}
int count_words(std::map<std::string, int>& cnt, std::istream& source){
	for (std::string word; source >> word; ){
		auto var = cnt.find(word);
		if(var!=cnt.end())
			var->second++;
		else
			cnt.insert(std::make_pair(word,1));
	}
}

template <typename T>
T loadtext(){
	T mycounter;
	std::ifstream fs;
	fs.open("Bible.txt");
	if (fs.is_open()) {
		std::istream& is = fs;
		count_words(mycounter,is);
		fs.close();
	}
	return mycounter;
}
