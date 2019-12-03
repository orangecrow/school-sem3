#include<iostream>
#include<string>
typedef string key;
class Counter{
private:
	struct Counter::node {
		key value;
		Counter::node *next;
	};
	Counter::node head;
	int recursive_copy(Counter::node*);
    int recursive_print(Counter::node*);
public:
	Counter(){head.next=NULL;};
	//Counter(key);
	Counter(const& Counter);
	Counter& operator=(const& Counter);
	~Counter();
	Counter::node* ad(key, Counter::node*);// adds Counter::node after the one that is pointed to by the pointer
	Counter::node* ad(key);//adds Counter::node after head
	Counter::node* del(Counter::node*);// deletes a Counter::node after the one that is pointed to by the pointer
	Counter::node* delal();//deletes all elements
	bool pn(Counter::node*);//print the value of the Counter::node pointed by pointer
	int pnal();//print all Counter::node values
};
Counter::node* Counter::ad(key a, Counter::node* np){
	if (np == NULL)
		return np;
	Counter::node* tmp = np->next;
	np->next = new Counter::node;
	np->next->value = a;
	np->next->next = tmp;
	return np;
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
	ad(a->value);
	return 0;
}
Counter::~Counter(){
	delal();
}
Counter::Counter(const& Counter a){
		recursive_copy(a.head.next);
}
Counter& Counter::operator=(const& Counter a){
	if (this==&a)
		return *this;
	delal();
	recursive_copy(a.head.next);
	return *this;
}
bool Counter::pn(Counter::node* a){
	if (a==NULL)
		return 1;
	std::cout<<a->value<<std::endl;
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
//int i=0;
//Counter::node* ptr=&head;
//while(ptr!=NULL){
//	ptr=ptr->next;
//	pn(ptr);
//	++i;
//}
//return i;
}
