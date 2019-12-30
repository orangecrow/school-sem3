#include"ring.h"
#include<string>
void test(BiRing<int,std::string> &ring){
	ring.print_all();
	auto it=ring.begin();
	std::cout<<"is iterator null?:" << it.isnull() <<"\n";
	++it;
	++it;
	it.modKey(33);
	it.modInfo("zzz");
	it++;
	it--.rm(); // remove forth element
	it.add(100,"hehe");// replace removed with this
	BiRing<int,std::string> b=ring;
	std::cout<< "\n";
	
	b.print_all();
	std::cout<< "\n";
	BiRing<int,std::string>& c=b;
	b.rm_all();
	std::cout<<"nothing here:"; c.print_all();
	std::cout<< "\n" << "search 6:" ;
	auto tab = ring.search(6);
	if(!tab.empty()){
		std::cout << (*tab[0]).k << "|" << tab[0]->i <<" or " << tab[0].print() << "\n";
		std::cout<<"is tab[0] equal to --ring.begin()?:" << (tab[0] == --ring.begin())<<"\n";
		std::cout<<"is tab[0] not equal to ring.begin()?:" << (tab[0] != ring.begin())<<"\n";
	}else
		std::cout<< "\n";
	std::cout<< "-----------------------------------------\n";
}
int main(){
	BiRing<int,std::string> ring;
	test(ring);
	ring.add(1,"aaa");
	test(ring);
	ring.add(1,"aaa");
	ring.add(6,"ccc");
	ring.add(5,"ccc");
	ring.add(4,"ccc");
	ring.add(3,"ccc");
	ring.add(2,"bbb");
	test(ring);
	return 0;
}
