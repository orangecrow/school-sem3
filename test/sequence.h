#include<cstdlib>
#include<cstddef>
#include<cstdio>
#include<iostream>
#include<string>
typedef int val_type ;
class Sequence{
private:
    struct node{
        val_type value;
        node *next=NULL;
    };
	node head;
    int copy_all(const Sequence&); //use only on empty lists
public:
	Sequence();
	Sequence(const Sequence&);
	~Sequence();
    Sequence& operator=(const Sequence&);
    Sequence& operator+(const Sequence&);
    int delete_all();
    int add(val_type);
    int print_all(); 
};
