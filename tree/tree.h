class Tree{

	struct Node{
		Node* l;
		Node* r;
		Node* u;
		Key k;
		Info i;
		int balance=0;
		int whereamI(){
			if(u!=NULL){
				if(this==u.l)
					return -1;
				if(this==u.r)
					return 1;
			}
			return 0;
		}
	};
	Node* root;
}
