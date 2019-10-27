#include"sequence.h"
using namespace std;
sequence::sequence(){
    head.next=(node*)0;
}
sequence::~sequence(){
    node *ptr=head.next;
    node *temp;
    while(ptr!=(node*)0){
        temp=ptr;
        ptr=ptr->next;	
        delete temp;
    }
}
int sequence::add(val_type a){
    node *first=head.next;
    head.next=new node;
    head.next->next=first;
    head.next->value=a;
}
