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

	int recad(Node*& p, Key k, Info i){
		int& r=p->br;
		int& l=p->bl;
		if(p==NULL){
			p = new Node;
			p->k=k;
			p->i=i;
			return 1;
		}
		if(k==p->k)
			return (p->br > p->bl ? p->br : p->bl )+1;
		if(k>p->k){
			r=recad(p->r,k,i);
			if(r==1)
				p->r->u=p;
		}
		if(k<p->k){
			l=recad(p->l,k,i);
			if(l==1)
				p->l->u=p;
		}
		return (r > l ? r : l)+1;
	}
	int recbal(Node*& p, Key k){
		int& r=p->br;
		int& l=p->bl;
		if(p==NULL){
			return 0;
		}
		if(k==p->k)
			return (p->br > p->bl ? p->br : p->bl )+1;
		if(k>p->k){
			r=recbal(p->r,k);
		}
		if(k<p->k){
			l=recbal(p->l,k);
		}
		return (r > l ? r : l)+1;
	}

	void balup(Node* p){
		if(p->r==NULL)
			p->br=0;
		else 
			recad(root,p->r->k);
		if(p->l==NULL)
			p->bl=0;
		else 
			recad(root,p->l->k);
		recad(root,p->k);
	}
//----------------------
	int smartrotate(Node*& p, bool d){
		Node* t=p;
		if(d&&p->l!=NULL){ //rigt rotation d=1
            if(p->l->balance()>0){
                rotate(p->l,0);
                p=p->u;
            }
			p=p->l;
			p->u=t->u;
			t->u=p;
			t->l=p->r;
			if(p->r!=NULL)
				p->r->u=t;
			p->r=t;
		}
		if(!d&&p->r!=NULL){ // left rotation d=0
            if(p->r->balance()<0){
                rotate(p->r,1);
                p=p->u;
            }
			p=p->r;
			p->u=t->u;
			t->u=p;
			t->r=p->l;
			if(p->l!=NULL)
				p->l->u=t;
			p->l=t;
		}
		balup(t);
	}
	
    void fix(Key k){
        recfix(root,k);
    }
    int recfix(Node* p, Key k){
		if(p==NULL){
			return 1;
		}
		if(k==p->k)
		if(k>p->k){
			recfix(p->r,k);
		}
		if(k<p->k){
			recfix(p->l,k);
		}
        if(p->balance()>1)
            smartrotate(p,0);
        if(p->balance()<-1)
            smartrotate(p,1);
		return 0;
    }
//----------------------
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
		balup(t);
	}

	void pn(Node* ptr){
//		if (ptr==NULL)
//		return;
		for(int i=0; i < ptr->getlv();++i)
			std::cout << "\t";
		//std::cout << ptr->k << "\n";
		//std::cout << ptr->k << ":" << ptr->bl << ":" << ptr->br << "\n";
		std::cout << ptr->k << ":" << ptr->balance() << "\n";
	}

	void recprint(Node* ptr){
		if (ptr==NULL)
			return;
		recprint(ptr->l);
		pn(ptr);
		recprint(ptr->r);
		return;
	}

	public:
	void testfunc(){
		rotate(root->l->l, 0);
		rotate(root->l->r, 1);
		rotate(root->r, 1);
	}
	void testfunc2(){
		rotate(root, 1);
		//rotate(root, 1);
	}

	Tree(){};
	~Tree(){};
	void print(){
		recprint(root);
	}

	int add(Key k, Info i){
		int ret = recad(root,k,i);
        //fix(k);
        return ret;
	}
};
