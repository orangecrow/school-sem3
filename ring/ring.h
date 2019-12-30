#include<vector>
#include<iostream>
#include<string>
#ifndef BIRING
#define BIRING
//template<typename Key ,typename Info>
typedef int Key;
typedef std::string Info;
class BiRing{
	struct Node{
		Key k;
		Info i;
		Node *next;
		Node *prev;
	};
	struct Package{
		Key k;
		Info i;
	};
	struct Iterator{
		Iterator(){ptr=NULL;ring=NULL;}
		Iterator(const Iterator& a){ring=a.ring;ptr=a.ptr;}
		Iterator(Iterator& a){ring=a.ring;ptr=a.ptr;}
		Package* operator->(){ 
			if (ptr==NULL);
			else{
				pkg.k=ptr->k;
				pkg.i=ptr->i;
			}
			return &pkg;
		}
		Package operator*(){ 
			if (ptr==NULL);
			else{
				pkg.k=ptr->k;
				pkg.i=ptr->i;
			}
			return pkg;
		}
		int modKey(Key c){
			if (ptr==NULL)
				return 1;
			ptr->k=c;
			return 0;
		}
		int modInfo(Info c ){
			if (ptr==NULL)
				return 1;
			ptr->i=c;
			return 0;
		}
		bool print(){
			if(ptr==NULL)
				return 1;
			std::cout << ptr->k << ";" << ptr->i <<"\n";
			return 0;
		}
		bool add(Key k,Info i){
			if(ptr==NULL)
				return 1;
			Node* b = new Node;
			b->k=k;
			b->i=i;
			b->next=ptr->next;
			b->prev=ptr;
			ptr->next->prev=b;
			ptr->next=b;
			return 0;
		}
		bool rm(){
			if (ptr==NULL)
				return 1;
			if (ptr->next==ptr){
				delete ptr;
				ring->anchor=NULL;	
				ptr=NULL;
				return 0;
			}
			if(ring->anchor==ptr)
				ring->anchor=ptr->next;
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			delete ptr;
			ptr=NULL;
			return 0;
		}
		bool operator==(Iterator &a){return ptr==a.ptr;}
		bool operator!=(Iterator &a){return ptr!=a.ptr;}
		bool isnull(){return ptr==NULL;}
		Iterator& operator++(){if(ptr!=NULL)ptr=ptr->next;return *this;}
		Iterator& operator--(){if(ptr!=NULL)ptr=ptr->prev;return *this;}
		Iterator operator++(int){Iterator a=*this; ++*this;return a;}
		Iterator operator--(int){Iterator a=*this; --*this;return a;}
		private:
		Package pkg;
		Node* ptr;
		BiRing* ring;
		friend class BiRing;
	};

	int copyall(Iterator a){
		Node* b=a.ptr;
		Node* c=b;
		if (b==NULL)
			return 1;
		//b=b->prev;
		c=c->next;
		while(b!=c){
			add(b->k,b->i);
			b=b->prev;
		}
		add(b->k,b->i);
		return 0;
	}

	Node* anchor;

	public:
	BiRing(){anchor=NULL;}	

	~BiRing(){rm_all();}	

	BiRing(BiRing& a){
		anchor=NULL;
		copyall(a.begin());
	}

	BiRing(BiRing&& a){
		anchor=a.anchor;
	};

	BiRing& operator=(BiRing& a){
		if(this==&a)
			return *this;
		rm_all();
		copyall(a.begin());
		return *this;
	}

	Iterator begin(){
		Iterator a;
		a.ptr=anchor;
		a.ring=this;
		return a;
	}

	std::vector<Iterator> search(Key k){
		int num=0;
		std::vector<Iterator> tab;
		Iterator dummy;
		dummy.ptr=NULL;
		if(anchor==NULL)
			return tab;
		Node* a=anchor;
		Node* b=a;
		do{
			if(b->k==k){
				++num;
				dummy.ptr=b;
				tab.push_back(dummy);
			}
			b=b->next;
		}while(a!=b);
		return tab;
	} // returns array

	void add(Key k,Info i){
		if(anchor==NULL){
			anchor = new Node;
			anchor->k=k;
			anchor->i=i;
			anchor->next=anchor;
			anchor->prev=anchor;
			return;
		}
		begin().add(k,i);
	}

	void rm_all(){while(!begin().rm());}	

	void print_all(){
		Iterator i = begin();
		Iterator j = i;
		do{
			j.print();
			++j;
		}while(j!=i);
	}
};
#endif
