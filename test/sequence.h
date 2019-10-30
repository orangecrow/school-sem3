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
        node *next=(node*)0;
    };
	node head;
public:
	Sequence();
	Sequence(const Sequence&);
	~Sequence();
    Sequence operator=(const Sequence&);
    int delete_all();
    int copy_all(const Sequence&);
    int add(val_type);
    int print_all(); 
};
