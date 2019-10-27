#include<cstdlib>
#include<cstddef>
typedef int val_type ;
class sequence{
private:
    struct node{
        val_type value;
        node *next;
    };
	node head;
public:
	sequence();
	~sequence();
    int add(val_type);
};
