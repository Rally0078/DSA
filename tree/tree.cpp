#include <iostream>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int data) {
    this->data = data;
    left = right = NULL;
  }
};

void preorder_traverse(struct Node* node)
{
	if(node == NULL)
		return;
	std::cout<<node->data<<" -> ";
	preorder_traverse(node->left);
	preorder_traverse(node->right);
}

void postorder_traverse(struct Node* node)
{
	if(node ==NULL)
		return;
	postorder_traverse(node->left);
	postorder_traverse(node->right);
	std::cout<<node->data<<" -> ";
}

void inorder_traverse(struct Node* node)
{
	if(node ==NULL)
		return;
	postorder_traverse(node->left);
	std::cout<<node->data<<" -> ";
	postorder_traverse(node->right);
}

int main(void)
{
	struct Node* root = new Node(1);
	root->left = new Node(12);
	root->right = new Node(9);
	root->left->left = new Node(5);
	root->left->right = new Node(6);
	std::cout<<"Preorder traversal: ";
	preorder_traverse(root);
	std::cout<<"\nPostorder traversal: ";
	postorder_traverse(root);
	std::cout<<"\ninorder traversal: ";
	inorder_traverse(root);
	return 0;
	
}