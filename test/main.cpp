#include"sequence.h"
int main(){
    //	int count_words(counter&, istream& source);
    Sequence a;
    a.add(2);
    Sequence b = a;
    a.add(9);
    b.add(8);
    Sequence *c=new Sequence;
    c->add(5);
    c->print_all();
    b.print_all();
    a.print_all();
    delete c;
    return 0;
}
