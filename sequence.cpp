#include<sequence.h> template<typename val_type>
sequence<val_type>::~sequance(){
	node *ptr;
	ptr = head;
	while(ptr=!NULL){
		ptr=ptr->next;	
	}
}

