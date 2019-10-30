#include"sequence.h"
using namespace std;
Sequence::Sequence(){
    head.next=(node*)0;
}
Sequence::~Sequence(){
/*    node *ptr=head.next;
    node *temp;
    while(ptr!=(node*)0){
        temp=ptr;
        ptr=ptr->next;	
        delete temp;
    }*/
this->delete_all();
}
int Sequence::add(val_type a){
    node *first=head.next;
    head.next=new node;
    head.next->next=first;
    head.next->value=a;
    return 0;
}
int Sequence::copy_all(const Sequence& a){
    node *src=a.head.next;
    node *des=&head;
    while(src!=(node*)0){
       des->next=new node;
       des=des->next;
       des->value=src->value;
       src=src->next;
    }
}
int Sequence::delete_all(){
    node *ptr=head.next;
    node *temp;
    while(ptr!=(node*)0){
        temp=ptr;
        ptr=ptr->next;	
        delete temp;
    }
    return 0;
}
Sequence::Sequence(const Sequence& a){
    //this->delete_all();
    copy_all(a);
}
Sequence Sequence::operator=(const Sequence& a){
    delete_all();
    copy_all(a);
}
int Sequence::print_all(){
    node *ptr=head.next;
    while(ptr!=(node*)0){
        cout<< ptr->value << "\n";
        ptr=ptr->next;
    }
}
