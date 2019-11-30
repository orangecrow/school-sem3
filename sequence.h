//template <typename val_type>
typedef int val_type;
class sequence{
private:
	struct node{
		val_type value;
		node *next;
	}
	node head;
	int recursive_copy(node*);
public:
	sequence(val_type);
	sequence(sequence&);
	sequence operator=(sequence&);
	~sequence();
	node* ad(val_type, node*);// adds node after the one that is pointed to by the pointer
	node* del(node*);// deletes a node after the one that is pointed to by the pointer
	node* delal();//deletes all elements
}
	/*struct iterator{
		node* curr;
		node* prev;
		iterator operator++();
		iterator operator++(int);
		node& operator*();
		iterator(){curr=head; prev=NULL}
	}*/
