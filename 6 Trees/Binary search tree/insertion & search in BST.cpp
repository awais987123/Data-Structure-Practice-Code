#include<iostream>


template <typename T>
class BstNode{
	public:
		T data;
		BstNode<T>* left;
		BstNode<T>* right;
		BstNode():left(NULL),right(NULL){}
		
		BstNode(T data):data(data),left(NULL),right(NULL){}
};
template <typename T>
BstNode<T>*  GetnewNode(T data)
{
	BstNode<T>* node=new BstNode<T>();
	node->data=data;
	node->left=node->right=NULL;
	return node;
}
template <typename T> 
BstNode<T>* insert(BstNode<T>* root,T data)
{
	if(root==NULL)
	{
		root=GetnewNode(data);
	}
	else if(data<=root->data)
	{
	root->left=insert(root->left,data);
	}
	else 
	{
		root->right=insert(root->right,data);
	}

	return root;
}
template <typename T>
bool search(BstNode<T>* root,T data)
{
	if(root==NULL) return false;
	else if(root->data==data) return true;
	else if(data<=root->data)
	{
	return	search(root->left,data);
	}
	else 
	{
	return	search(root->right,data);
	}
}
int main()
{
	char element;
	 BstNode<char> *root = new BstNode<char>() ;  
     root=insert(root,'a');
	 root=insert(root,'d');
	 root=insert(root,'e');
	 root=insert(root,'f'); 
	 root=insert(root,'j');
    std::cout<<"Enter the element :\n";
	std::cin>>element;
	if(search(root,element))std::cout<<"Found ";
	else std::cout<<"not found";  

}
