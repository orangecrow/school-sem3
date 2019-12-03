#ifndef COUNTER
#define COUNTER
#include<iostream>
#include<string>
typedef std::string key;
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
Counter::node* Counter::ad(key a, Counter::node* np){
	if (np == NULL)
		return np;
	Counter::node* tmp = np->next;
	np->next = new Counter::node;
	np->next->value = a;
	np->next->next = tmp;
	np->next->count=1;
	return np;
}
int Counter::specialad(key a){
	Counter::node* ptr=head.next;
	for(ptr=head.next;ptr!=NULL;ptr=ptr->next){
		if(ptr->value==a){
			++ptr->count;
			return 0;
		}
	}
	ad(a);
	return 1;
}
Counter::node* Counter::ad(key a){
	return ad(a, &head);
}
Counter::node* Counter::del(Counter::node* np){
	if (np == NULL)
		return np;
	Counter::node* del=np->next;
	if (np->next!=NULL){
		np->next=np->next->next;
		delete del;
	}
	return np;
}
Counter::node* Counter::delal(){
	while(del(&head)->next!=NULL);
	return &head;
}
int Counter::recursive_copy(Counter::node* a){
	if(a==NULL)
		return 0;
	recursive_copy(a->next);
	for(int i=0;i<a->count;++i)
	specialad(a->value);
	return 0;
}
Counter::~Counter(){
	delal();
}
Counter::Counter(Counter & a){
	head.next=NULL;
	recursive_copy(a.head.next);
}
Counter& Counter::operator=(Counter & a){
	if (this==&a)
		return *this;
	delal();
	recursive_copy(a.head.next);
	return *this;
}
bool Counter::pn(Counter::node* a){
	if (a==NULL)
		return 1;
	std::cout<<a->value<<":" <<a->count << ", ";
	return 0;
}
int Counter::recursive_print(Counter::node* a){
	if(a==NULL)
		return 0;
	recursive_print(a->next);
    pn(a);
	return 0;
}
int Counter::pnal(){
recursive_print(head.next);
std::cout<<std::endl;
std::cout<<std::endl;
//int i=0;
//Counter::node* ptr=&head;
//while(ptr!=NULL){
//	ptr=ptr->next;
//	pn(ptr);
//	++i;
//}
//return i;
}
#endif
