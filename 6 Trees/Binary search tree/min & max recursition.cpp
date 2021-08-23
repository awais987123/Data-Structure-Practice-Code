#include<iostream>


template <typename T>
class BstNode {
public:
	T data;
	BstNode<T>* left;
	BstNode<T>* right;
	BstNode() :data(0),left(NULL), right(NULL) {}
	BstNode(T data) :data(data), left(NULL), right(NULL) {}
};
template <typename T>
BstNode<T>* GetnewNode(T data)
{
	BstNode<T>* node = new BstNode<T>();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
template <typename T>
BstNode<T>* insert(BstNode<T>* root, T data)
{
	if (root == NULL)
	{
		root = GetnewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}

	return root;
}
template <typename T>
bool search(BstNode<T>* root, T data)
{
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data)
	{
		return	search(root->left, data);
	}
	else
	{
		return	search(root->right, data);
	}
}
template<typename T>
T FindMin(BstNode<T>* root)
{

	if (root == NULL)
	{
		std::cout << "\nEmpty Tree!";	return -1;
	}
else if(root->left==NULL)
{
	return root->data;
}
FindMin(root->left);
}
template <typename T>
T FindMax(BstNode<T>* root)
{

	if (root == NULL)
	{
		std::cout << "\nEmpty Tree!";	return -1;
	}
else if(root->right==NULL)
	{
	return root->data;	
	}
	FindMax(root->right);
}
int main()
{

	BstNode<int>* root = new BstNode<int>();
	root = insert(root, 20);
	root = insert(root, 2);
	root = insert(root, 22);
	root = insert(root, 24);
	root = insert(root, 4);

	std::cout << FindMin(root) << std::endl;
	std::cout << FindMax(root);
}
