#include"sequence.h" 
#include<iostream>
//template<typename val_type>
node* Sequence::ad(val_type a, node* np){
	if (np == NULL)
		return np;
	node* tmp = np->next;
	np->next = new node;
	np->next->value = a;
	np->next->next = tmp;
	return np;
}
node* Sequence::ad(val_type a){
	return ad(a, &head);
}
node* Sequence::del(node* np){
	if (np == NULL)
		return np;
	node* del=np->next;
	if (np->next!=NULL){
		np->next=np->next->next;
		delete del;
	}
	return np;
}
node* Sequence::delal(){
	while(del(&head)->next!=NULL);
	return &head;
}
int Sequence::recursive_copy(node* a){
	if(a==NULL)
		return 0;
	recursive_copy(a->next);
	ad(a->value);
	return 0;
}
Sequence::~Sequence(){
	delal();
}
Sequence::Sequence(Sequence& a){
		recursive_copy(a.head.next);
}
Sequence& Sequence::operator=(Sequence& a){
	if (this==&a)
		return *this;
	delal();
	recursive_copy(a.head.next);
	return *this;
}
bool Sequence::pn(node* a){
	if (a==NULL)
		return 1;
	std::cout<<a->next<<std::endl;
	return 0;
}
int Sequence::pnal(){
	int i=0;
	node* ptr=&head;
	while(ptr!=NULL){
		ptr=ptr->next;
		pn(ptr);
		++i;
	}
	return i;
}
