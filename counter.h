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
		int count;
		node *next;
	};
	node head;
	int recursive_copy(node*);
    int recursive_print(node*);
public:
	Counter(){head.next=NULL;};
	Counter(Counter&);
	Counter& operator=(Counter&);
	~Counter();
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
//print all node values
	int pnal();
// looks for the key and increases the count if it exists or adds a key
	int specialad(key);
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
int Counter<key>::specialad(key a){
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
	specialad(a->value);
	return 0;
}
template<typename key>
Counter<key>::~Counter(){
	delal();
}
template<typename key>
Counter<key>::Counter(Counter<key> & a){
	head.next=NULL;
	recursive_copy(a.head.next);
}
template<typename key>
Counter<key>& Counter<key>::operator=(Counter<key> & a){
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
