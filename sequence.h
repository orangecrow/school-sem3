struct node{
	val_type value;
	node *next;
}
template <typename val_type>
class sequence{
private:
	node *head;
public:
	sequance(){head=NULL;}
	~sequance();
}
