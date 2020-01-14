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
		std::cout << (*tab[0]).k << "|" << tab[0]->i <<" or " ;tab[0].print();
		std::cout<<"is tab[0] equal to --ring.begin()?:" << (tab[0] == --ring.begin())<<"\n";
		std::cout<<"is tab[0] not equal to ring.begin()?:" << (tab[0] != ring.begin())<<"\n";
	}else
		std::cout<< "\n";
	std::cout<< "-----------------------------------------\n";
}
BiRing<int,std::string> shuffle(const BiRing<int,std::string>& first, const BiRing<int,std::string>& second, int nb_first, int nb_second, int reps){
	BiRing<int,std::string> toret;
	BiRing<int,std::string>::Iterator to;
	auto fi = first.begin();
	auto si = second.begin();
	for(int x=0;x<reps;++x){
		for(int f=0;f<nb_first;++f){
			if(x==0&&f==0){
				toret.add(fi->k,fi->i);
				to = toret.begin();
				++fi;
			}else{
				to.add(fi->k,fi->i);
				++to;
				++fi;
			}
		}
		for(int s=0;s<nb_second;++s){
			to.add(si->k,si->i);
			++to;
			++si;
		}
	}
	return toret;
}
int main(){
	BiRing<int,std::string> ring;
	BiRing<int,std::string> ring2;
	BiRing<int,std::string> ring1;
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
std::cout << "================================\n";
	ring1.add(1,"first");
	ring1.add(6,"first");
	ring1.add(5,"first");
	ring1.add(4,"first");
	ring1.add(3,"first");
	ring1.add(2,"first");
	ring2.add(11,"second");
	ring2.add(16,"second");
	ring2.add(15,"second");
	ring2.add(14,"second");
	ring2.add(13,"second");
	ring2.add(12,"second");
ring1.print_all();
std::cout << "================================\n";
ring2.print_all();
std::cout << "================================\n";
shuffle(ring1,ring2,3,4,5).print_all();
	return 0;
}
