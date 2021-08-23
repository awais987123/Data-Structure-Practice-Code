#include<iostream>
template<typename T>
class Node{
	public:
		T data;
		Node<T>* next;
		Node<T>():data(0),next(NULL){}
Node<T>(T data):data(data)
{
	this->next=NULL;
}
};

template<typename T>
class linkedlist
{
	private:
	int m_count;
	public:
	Node<T>* head;
	Node<T>* tail;

	linkedlist():m_count(0),head(NULL),tail(NULL){}	
    void inserthead(T);
void inserttail(T);
void insertindex(int,T);
void printlist();	 
};
template<typename T>
void linkedlist<T>::inserthead(T val)
{
	Node<T>* node=new Node<T>(val);
	node->next=head;
	head=node;
	if(m_count==0)
	tail=head;
	m_count++;
}
template<typename T>
void linkedlist<T>::inserttail(T val)
{
	if(m_count==0)
	{
		inserthead(val);
	}
Node<T>* node=new Node<T>(val);
tail->next=node;
tail=node;	
m_count++;
}
template<typename T>
void linkedlist<T>::insertindex(int index,T val)
{
	if(index<0||index>m_count)
	return;
	
	if(index==0)
	{
		inserthead(val);
		return;
	}
	else if(index==m_count)
	{
		inserttail(val);
		return;
	}
		Node<T>* p_node=NULL;
		p_node=head;
		for(int i=0;i<index-1;++i)
		{
			p_node=p_node->next;
		}
		Node<T>* n_node=p_node->next;
		Node<T>* node=new Node<T>(val);
		
		node->next=n_node;
		p_node->next=node;
		
	
	m_count++;
}
template<typename T>
void linkedlist<T>::printlist()
{
	Node<T>* node=head;
	while(node!=NULL)
	{
		std::cout<<node->data<<"->";
		node=node->next;
	}
	std::cout<<"NULL";}
int main()
{
	linkedlist<int> obj;
	obj.insertindex(0,2);
obj.insertindex(1,3);
obj.insertindex(2,7);
obj.inserttail(9);
obj.inserthead(6);
obj.printlist();
	

	
		return 0;
}
