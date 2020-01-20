#include<string>
#include<iostream>
typedef int Key;
typedef std::string Info;
class Tree{

	struct Node{
		Node* l=NULL;
		Node* r=NULL;
		Node* u=NULL;
		Key k;
		Info i;
		int bl=0;
		int br=0;
		int getlv(){
			int count=0;
			for(Node* ptr=this;ptr->u!=NULL;ptr=ptr->u)
				++count;
			return count;
		}
		int balance(){
			return br-bl;
		}
		int pos(){
			if(u==NULL)
				return 0;
			if(this==u->l)
				return -1;
			if(this==u->r)
				return 1;
		}
	};

	Node* root=NULL;
	Node* hold=NULL;
	bool addSwitch=true;

	int setInfo(Node* p, Info i){
		if (p==NULL)
			return 1;
		p->i=i;
		return 0;
	}

	int recAdd(Node*& p, Key k){
		int& r=p->br;
		int& l=p->bl;
		if(p==NULL){
			if(addSwitch==true){
				hold = p = new Node;
				p->k=k;
				return 1;
			}else{
				hold=p;
				return 0;
			}
		}
		if(k==p->k){
			hold=p;
			return (r > l ? r : l)+1;
		}
		if(k>p->k){
			r=recAdd(p->r,k);
			if(r==1)
				p->r->u=p;
		}
		if(k<p->k){
			l=recAdd(p->l,k);
			if(l==1)
				p->l->u=p;
		}
		return (r > l ? r : l)+1;
	}

	void balCount(Node* p){
		if(p->r==NULL)
			p->br=0;
		else 
			recAdd(p,p->r->k);
		if(p->l==NULL)
			p->bl=0;
		else 
			recAdd(p,p->l->k);
		recAdd(root,p->k);
	}
	int smartrotate(Node*& p, bool d){
		if(d&&p->l!=NULL){ //rigt rotation d=1
			if(p->l->balance()>0)
				rotate(p->l,0);
			rotate(p,1);
		}
		if(!d&&p->r!=NULL){ // left rotation d=0
			if(p->r->balance()<0)
				rotate(p->r,1);
			rotate(p,0);
		}
	}

	void fixBal(Key k){
		recFixBal(root,k);
	}

	void recFixBal(Node*& p, Key k){
		if(p==NULL)
			return;
		if(k>p->k)
			recFixBal(p->r,k);
		if(k<p->k)
			recFixBal(p->l,k);
		if(p->balance()>1)
			smartrotate(p,0);
		if(p->balance()<-1)
			smartrotate(p,1);
		return;
	}

	int rotate(Node*& p, bool d){
		Node* t=p;
		if(d&&p->l!=NULL){ //rigt rotation d=1
			p=p->l;
			p->u=t->u;
			t->u=p;
			t->l=p->r;
			if(p->r!=NULL)
				p->r->u=t;
			p->r=t;
		}
		if(!d&&p->r!=NULL){ // left rotation d=0
			p=p->r;
			p->u=t->u;
			t->u=p;
			t->r=p->l;
			if(p->l!=NULL)
				p->l->u=t;
			p->l=t;
		}
		balCount(t);
	}

	//----------------------
	void rotateKey(Node*& p, Key k,bool b){
		if(p==NULL)
			return;
		if(k>p->k)
			rotateKey(p->r,k,b);
		if(k<p->k)
			rotateKey(p->l,k,b);
		if(k==p->k)
			rotate(p,b);
		return;
	}

	int removeKey(Node*& p, Key k){
		static Node * replNode = NULL;
		static Key replaceKey;
		static Node * balanceNode = p;
		if(p==NULL)
			return 1;
		if(k>p->k && removeKey(p->r,k)){
			replaceKey=p->k;
			recAdd(root, replaceKey);
			while(hold->l!=NULL){
				rotateKey(root,replaceKey,1);
				recAdd(root, replaceKey);
			}
			replNode=hold;
			return 0;
		}
		if(k<p->k && removeKey(p->l,k)){
			replaceKey=p->k;
			recAdd(root, replaceKey);
			while(hold->r!=NULL){
				rotateKey(root,replaceKey,0);
				recAdd(root, replaceKey);
			}
			replNode=hold;
			return 0;
		}
		if(p->k==k){
			if(p->r==NULL&&p->l==NULL){
				balanceNode=p->u;
				delete p;
				p=NULL;
				balCount(balanceNode);
				return 0;
			}
			if(p->r==NULL)
				replNode=p->l;
			if(p->l==NULL)
				replNode=p->r;
			if(p->r!=NULL&&p->l!=NULL){
				if ( p->balance() > 0 )
					removeKey(p->r,k);
				else
					removeKey(p->l,k);
			}
			balanceNode=replNode->u;
			if (balanceNode->r==replNode)
				balanceNode->r=NULL;
			if (balanceNode->l==replNode)
				balanceNode->l=NULL;
			replNode->u=p->u;
			replNode->r=p->r;
			replNode->l=p->l;
			delete p;
			p=replNode;
			balCount(balanceNode);
			return 0 ;
		} 
		return 0;
	}


	/*int removeNode(Node* p){
		Node* replacement;
		Node* replaced;
		Node* temp;
		if(p==NULL)
			return 1;
		if(p->u==NULL)
			;
		else{
			switch (pos()){
				case 0:
					break;
				case 1:
					break;
				case -1:
					if(p->r=NULL&&p->l=NULL){
						temp=p->u;
						delete p;
						if(p->r==NULL&&p->l!){
							replacement=p->l;
							replaced = p->u->l=replacement;
							replaced->r=p->r;
							replaced->l=p->l;
							delete p;
						}
						for(Node* ptr=p;ptr->r!=NULL;ptr=ptr->r)
							for(Node* ptl=p;ptl->l!=NULL;ptl=ptl->l)
					}
			}
		}
	}*/


//----------------------

	void pn(Node* ptr){
//		if (ptr==NULL)
//		return;
		for(int i=0; i < ptr->getlv();++i)
			std::cout << "\t";
		//std::cout << ptr->k << "\n";
		//std::cout << ptr->k << ":" << ptr->bl << ":" << ptr->br << "\n";
		std::cout << ptr->k << ":" << ptr->balance() << "\n";
	}

	void recPrint(Node* ptr){
		if (ptr==NULL)
			return;
		recPrint(ptr->l);
		pn(ptr);
		recPrint(ptr->r);
		return;
	}

	public:
	void testfunc1(){
		rotate(root->l->l, 0);
		rotate(root->l->r, 1);
		rotate(root->r, 1);
	}
	void testfunc2(){
		rotate(root, 1);
		//rotate(root, 1);
	}
	void testfunc3(Key k){
		removeKey(root,k);
	}
		

	Tree(){};
	~Tree(){};
	void print(){
		recPrint(root);
	}

	void add(Key k, Info i){
		recAdd(root,k);
		setInfo(hold,i);
		fixBal(k);
	}
};
