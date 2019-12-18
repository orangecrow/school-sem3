#include<iostream>
//typedef int val_type;
template <typename val_type>
class Sequence{
private:
	struct node {
		val_type value;
		node *next;
	};
	node head;
	int recursive_copy(node*);
    int recursive_print(node*);
	node* ad(val_type, node*);// adds node after the one that is pointed to by the pointer
	node* ad(val_type);//adds node after head
	node* del(node*);// deletes a node after the one that is pointed to by the pointer
	node* delal();//deletes all elements
	bool pn(node*);//print the value of the node pointed by pointer
public:
	Sequence(){head.next=NULL;};
	//Sequence(val_type);
	Sequence(const Sequence&);
	Sequence& operator=(const Sequence&);
	~Sequence();
	int pnal();//print all node values
    int usr_ad(val_type a){ad(a);};
	int usr_del(){delal();}
	int rm_val(val_type a){
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
	int rm_val_al(val_type a){while(!rm_key(a));}
    int usr_cat(Sequence &a){
        recursive_copy(a.head.next);
        return 0;
    }
};
	/*struct iterator{
		node* curr;
		node* prev;
		iterator operator++();
		iterator operator++(int);
		node& operator*();
		iterator(){curr=head; prev=NULL}
	}*/
template <typename val_type>
typename Sequence<val_type>::node* Sequence<val_type>::ad(val_type a, typename Sequence<val_type>::node* np){
	if (np == NULL)
		return np;
	typename Sequence<val_type>::node* tmp = np->next;
	np->next = new typename Sequence<val_type>::node;
	np->next->value = a;
	np->next->next = tmp;
	return np;
}
template <typename val_type>
typename Sequence<val_type>::node* Sequence<val_type>::ad(val_type a){
	return ad(a, &head);
}
template <typename val_type>
typename Sequence<val_type>::node* Sequence<val_type>::del(typename Sequence<val_type>::node* np){
	if (np == NULL)
		return np;
	typename Sequence<val_type>::node* del=np->next;
	if (np->next!=NULL){
		np->next=np->next->next;
		delete del;
	}
	return np;
}
template <typename val_type>
typename Sequence<val_type>::node* Sequence<val_type>::delal(){
	while(del(&head)->next!=NULL);
	return &head;
}
template <typename val_type>
int Sequence<val_type>::recursive_copy(typename Sequence<val_type>::node* a){
	if(a==NULL)
		return 0;
	recursive_copy(a->next);
	ad(a->value);
	return 0;
}
template <typename val_type>
Sequence<val_type>::~Sequence<val_type>(){
	delal();
}
template <typename val_type>
Sequence<val_type>::Sequence(const Sequence<val_type>& a){
	head.next=NULL;
	recursive_copy(a.head.next);
}
template <typename val_type>
Sequence<val_type>& Sequence<val_type>::operator=(const Sequence<val_type>& a){
	if (this==&a)
		return *this;
	delal();
	recursive_copy(a.head.next);
	return *this;
}
template <typename val_type>
bool Sequence<val_type>::pn(typename Sequence<val_type>::node* a){
	if (a==NULL)
		return 1;
	std::cout<<a->value<<std::endl;
	return 0;
}
template <typename val_type>
int Sequence<val_type>::recursive_print(typename Sequence<val_type>::node* a){
	if(a==NULL)
		return 0;
	recursive_print(a->next);
    pn(a);
	return 0;
}
template <typename val_type>
int Sequence<val_type>::pnal(){
recursive_print(head.next);
//int i=0;
//typename Sequence<val_type>::node* ptr=&head;
//while(ptr!=NULL){
//	ptr=ptr->next;
//	pn(ptr);
//	++i;
//}
//return i;
}
