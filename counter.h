#ifndef COUNTER
#define COUNTER
#include<iostream>
#include<string>
//typedef std::string key;
template<typename key>
class Counter{
private:
	struct node {
		key value;
		unsigned int count;
		node *next;
	};
	node head;
	int recursive_copy(node*);
    int recursive_print(node*);
// adds node after the one that is pointed to by the pointer
	node* ad(key, node*);
//adds node after head
	node* ad(key);
// deletes a node after the one that is pointed to by the pointer
	node* del(node*);
//deletes all elements
	node* delal();
//print the value of the node pointed by pointer
	bool pn(node*);
public:
	Counter(){head.next=NULL;};
	Counter(const Counter&);
	Counter& operator=(const Counter&);
	~Counter();
//print all node values
	int pnal();
// looks for the key and increases the count if it exists or adds a key
	int usr_ad(key);
	int usr_del(){delal();}
	int rm_key(key a){
		node* ptr;
		node* prev=head;
		for(ptr=head.next;ptr!=NULL;ptr=ptr->next){
			if(ptr->value==a){
				if(ptr->count=0){
					del(prev);
					return 0;
				}
				--ptr->count;
				return 1;
			}
			prev=ptr;
		}
		return 2;
	}
	int rm_key_al(key a){
		node* ptr;
		node* prev=head;
		for(ptr=head.next;ptr!=NULL;ptr=ptr->next){
			if(ptr->value==a){
					del(prev);
					return 0;
			}
			prev=ptr;
		}
		return 1;
	}
    void usr_cat(Counter &a){
        recursive_copy(a.head.next);
    }
	//-------------------------------------------
	void ad_at_index(key k, int index){
		if(!get_index(k)){
			usr_ad(k);
			mov_key(k,index);
		}else
			usr_ad(k);
	}
	//-------------------------------------------
private:
int innerfunc1(node* p2, int num,key k){
	node *p1;
	node *ptr;
	int a=num;
	if(p2==NULL||p2->next==NULL||p2->next->next==NULL)
		return 0;
	p1=p2->next;
	ptr=p1->next;
	if(ptr->value!=k)
		a=innerfunc1(p2->next,num,k);
	if(a<0){
		p1=p2->next;
		ptr=p1->next;
		p2->next=ptr;
		p1->next=ptr->next;
		ptr->next=p1;
		++a;
	}
	return a;
}
int innerfunc2(key k, int dir){ 
	node* p1 = &head;
	node* temp;
	node* ptr;
	int a = 0;
	for(ptr=head.next;ptr!=NULL;ptr=ptr->next){
		if(ptr->value==k){
			for(int i=0;i<dir;++i){
				if(ptr->next!=NULL){
					p1->next=ptr->next;
					temp=ptr->next->next;
					ptr->next->next=ptr;
					ptr->next=temp;
					p1=p1->next;
					a=i+1;
				}
			}
		}
		p1=ptr;
	}
	return a;
}
	
public:
	int mov_key(key k, int dir){
		if(dir<0)
			return dir-innerfunc1(&head,dir,k);
		if(dir>0)
			return innerfunc2(k,dir);
		return 0;
	}
	unsigned int get_index(key k){
		node* ptr;
		int index=0;
		for(ptr=head.next;ptr!=NULL;ptr=ptr->next){
			++index;
			if(ptr->value==k)
				return index;
		}
		return 0;
	}
	void print_all(){
		node* ptr;
		for(ptr=head.next;ptr!=NULL;ptr=ptr->next)
			std::cout << ptr->value << ':' << ptr->count << " | ";
		std::cout << std::endl;
	}
	void print(key k){
		for(node* ptr=head.next;ptr!=NULL;ptr=ptr->next)
			if(ptr->value==k)
				std::cout << ptr->value << ':' << ptr->count << "\n";
	}

};
template<typename key>
typename Counter<key>::node* Counter<key>::ad(key a, typename Counter<key>::node* np){
	if (np == NULL)
		return np;
	typename Counter<key>::node* tmp = np->next;
	np->next = new typename Counter<key>::node;
	np->next->value = a;
	np->next->next = tmp;
	np->next->count=1;
	return np;
}
template<typename key>
int Counter<key>::usr_ad(key a){
	typename Counter<key>::node* ptr=head.next;
	for(ptr=head.next;ptr!=NULL;ptr=ptr->next){
		if(ptr->value==a){
			++ptr->count;
			return 0;
		}
	}
	ad(a);
	return 1;
}
template<typename key>
typename Counter<key>::node* Counter<key>::ad(key a){
	return ad(a, &head);
}
template<typename key>
typename Counter<key>::node* Counter<key>::del(typename Counter<key>::node* np){
	if (np == NULL)
		return np;
	typename Counter<key>::node* del=np->next;
	if (np->next!=NULL){
		np->next=np->next->next;
		delete del;
	}
	return np;
}
template<typename key>
typename Counter<key>::node* Counter<key>::delal(){
	while(del(&head)->next!=NULL);
	return &head;
}
template<typename key>
int Counter<key>::recursive_copy(typename Counter<key>::node* a){
	if(a==NULL)
		return 0;
	recursive_copy(a->next);
	for(int i=0;i<a->count;++i)
		usr_ad(a->value);
	return 0;
}
template<typename key>
Counter<key>::~Counter(){
	delal();
}
template<typename key>
Counter<key>::Counter(const Counter<key> & a){
	head.next=NULL;
	recursive_copy(a.head.next);
}
template<typename key>
Counter<key>& Counter<key>::operator=(const Counter<key> & a){
	if (this==&a)
		return *this;
	delal();
	recursive_copy(a.head.next);
	return *this;
}
template<typename key>
bool Counter<key>::pn(typename Counter<key>::node* a){
	if (a==NULL)
		return 1;
	std::cout<<a->value<<":" <<a->count << ", ";
	return 0;
}
template<typename key>
int Counter<key>::recursive_print(typename Counter<key>::node* a){
	if(a==NULL)
		return 0;
	recursive_print(a->next);
    pn(a);
	return 0;
}
template<typename key>
int Counter<key>::pnal(){
recursive_print(head.next);
std::cout<<std::endl;
std::cout<<std::endl;
}
#endif
