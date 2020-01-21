#include<string>
#include<iostream>
#define DIRECTION k > p->k
typedef int Key;
typedef std::string Info;
class Tree{
	public:

	struct Node{
		Node* up[2]={NULL,NULL};
		int  bal[2]={0,0};
		int balance(){ return bal[1]-bal[0]; }
		int weight(){ return (bal[1]>bal[0] ? bal[1]:bal[0])+1; }
		int weightPlus(){ 
				if(up[1]!=NULL)
					bal[1] = up[1]->weight();
				else
					bal[1]=0;
				if(up[0]!=NULL)
					bal[0] = up[0]->weight();
				else
					bal[0]=0;
				return weight();
			}
		Key k;
		Info i;
	};

	Node * mynullptr=NULL;
	Node * root=NULL;

	int recCountBalance(Node*& p, Key k){
		if(p==NULL)
			return 0;
		if(k==p->k)
			return p->weightPlus();
		p->bal[k > p->k] = recCountBalance(p->up[k > p->k],k);
		return p->weight();
	}

	Node*& recAdd(Node*& p, Key k){
		if(p==NULL){
			p = new Node;
			p->k=k;
			return p;
		}
		if(p->k==k)
			return mynullptr;
		return recAdd(p->up[k > p->k],k);
	}

	Node*& recFind(Node*& p, Key k){
		if(p==NULL){
			return mynullptr;
		}
		if(p->k==k)
			return p;
		return recFind(p->up[k > p->k],k);
	}

	int recRotate(Node*& p, Key k, bool d){
		if (p == NULL)
			return 1;
		if(p->k == k)
			return rotate(p,d);
		return recRotate(p->up[DIRECTION],k,d);
	}

	int rotate(Node*& p, bool d){
		Node* t=p;
		if(p->up[!d] != NULL){ // up[0]eft up[1]otation d=0
			p = p->up[!d];
			t->up[!d] = p->up[d];
			p->up[d] = t;
			recCountBalance(root, t->k);
			return 0;
		}
		return 1;
	}
	int smartRotate(Node*& p, bool d){
		if(p->up[!d]!=NULL){ //rigt rotation d=1
			if(d && p->up[!d]->balance() > 0  || !d && p->up[!d]->balance() < 0 )
				rotate(p->up[!d],!d);
			rotate(p,d);
		}
	}

	void recFixBal(Node*& p, Key k){
		if(p==NULL)
			return;
		recFixBal(p->up[k > p->k],k);
		if(p->balance()>1)
			smartRotate(p,0);
		if(p->balance()<-1)
			smartRotate(p,1);
		return;
	}

	void fixBal(Key k){
		recFixBal(root,k);
	}
//-----------------------------------------------------
	Node*& recFindF(Node*& p, Key k){
		static Node* toret =NULL;
		if(p==NULL)
			return mynullptr;
		if(recFindF(p->up[k > p->k],k)==NULL)
			toret=p;
		return toret;
	}

	Node* getPrev(Node* p){
		Node* prev;
		for(Node* t = root; t!=p ;t = t->up[p->k > t->k]){
			prev=t;
			if ( t==NULL)
				return NULL;
		}
		return prev;
	}

	int removeNode(Node*& p){
		bool i=false;
		Node* replacement=NULL;
		Node* previous=NULL;
		Key kkk;
		if (p==NULL)
			return 1;
		if(p->up[0]==NULL&&p->up[1]==NULL){
			kkk=p->k;
			delete p;
			p=NULL;
			recCountBalance(root,kkk);
			fixBal(kkk);
			return 0;
		}
		do{
			if(p->up[i]==NULL&&p->up[!i]!=NULL){
				replacement=p->up[!i];
				delete p;
				p=replacement;
				recCountBalance(root,replacement->k);
				fixBal(replacement->k);
				return 0;
			}
			i=!i;
		}while(i);
		if(p->up[i]!=NULL&&p->up[!i]!=NULL){
			replacement=recFindF(root,p->k);
				while(replacement->up[0]!=NULL){
					recRotate(root, replacement->k, 1);
				}
			previous=getPrev(replacement);
			for(int j=0;j<2;++j){
				if (previous->up[j]==replacement)
					previous->up[j]=NULL;
				replacement->up[j]=p->up[j];
				replacement->bal[j]=p->bal[j];
			}
			delete p;
			p=replacement;
			recCountBalance(root,previous->k);
			fixBal(previous->k);
			return 0;
		}
		return 1;

	}
	bool recRemove(Node*& p, Key k){
		if(p==NULL)
			return 0;
		if(k==p->k)
			return removeNode(p);
		return recRemove(p->up[k > p->k],k);
	}
//-----------------------------------------------------

	int getLvl(Key k){
		int i = 0;
		for(Node* p=root; p!=NULL;p=p->up[k > p->k]){
			if(p->k==k)
				return i;
			++i;
		}
		return 0;
	}

	void pn(Node* p){
		for(int i=0; i < getLvl(p->k);++i)
			std::cout << "\t";
		//std::cout << p->k << ":" << p->up[0] << ":" << p->up[1] << "\n";
		std::cout << p->k << ":" << p->balance() << "\n";
	}

	void recPrint(Node* p ){
		if ( p == NULL)
			return;
		recPrint( p->up[0]);
		pn( p );
		recPrint( p->up[1]);
		return;
	}

	public:
	int remove(Key k){
		return recRemove(root,k);
	}

	int rot(Key k, bool d){
		recRotate(root,k,d);
	}

	void print(){
		recPrint(root);
	}

	int add(Key k, Info i){
		Node * t = recAdd(root,k);
		if (t==NULL)
			return 1;
		t->i=i;
		recCountBalance(root,k);
		fixBal(k);
		return 0;
	}
};


