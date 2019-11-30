#include<sequence.h> 
//template<typename val_type>
node* sequence::ad(val_type a, node* np){
	if (np == NULL)
		return np;
	node* tmp = np->next;
	np->next = new node;
	np->next->value = a;
	np->next->next = tmp;
	return np;
}
node* sequence::del(node* np){
	if (np == NULL)
		return np;
	node* del=np->next;
	if (np->next!=NULL){
		np->next=np->next->next;
		delete del;
	}
	return np;
}
node* sequence::delal(){
	while(del(*head)->next!=NULL);
	return *head;
}
int sequence::recursive_copy(node* a){
	if(a==NULL)
		return 0;
	recursive_copy(a->next);
	ad(a->value,*head);
	return 0;
}
sequence::sequence(sequence& a){
		recursive_copy(&(a.head))
}
sequence sequence::operator=(sequence& a){
	if (this==&a)
		return;
	
}
