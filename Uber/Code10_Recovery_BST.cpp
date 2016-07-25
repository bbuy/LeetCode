// there is a BST, two nodes has been swapped, recover it. 


#include <iostream> 

using namespace std;

class Node
{
public:
	int value;
	Node* left;
	Node* right;
	Node(int v):value(v),left(NULL),right(NULL){}
};

static Node* node1;
static Node* node2;

void DFS(Node* root, Node* preNode)
{
	if(root==NULL)
	{
		return;
	}

	DFS(root->left, preNode);
	if(preNode) cout<<"PreNode"<<preNode->value<<" Root:"<<root->value<<endl;
	if(preNode && (root->value < preNode->value))
	{
		if(node1 == NULL)
		{
			node1 = preNode;
			cout<<"Node1 found:"<<node1->value<<endl;
		}
		else
		{
			node2 = root;
			cout<<"Nodde2 found"<<node2->value<<endl;
		}
	}
	preNode = root;
	//cout<<"preNode:"<<preNode->value<<endl;
	DFS(root->right, preNode);
}

void RecoverBST(Node* root)
{
	Node* preNode = NULL;
	DFS(root, preNode);

	//cout<<"Node1:"<<node1->value<<endl;
	//cout<<"Node2:"<<node2->value<<endl;
	swap(node1->value, node2->value);
}

int main()
{
	Node node1(1);
	Node node2(2);
	Node node3(3);
	Node node4(4);
	Node node5(5);
	Node node6(6);
	Node node7(7);
	Node node8(8);
	

	node1.left = &node2;
	node1.right = &node3;

	node2.left = &node4;
	node2.right = &node5;

	node3.left = &node6;
	node3.right = &node7;

	node7.right = &node8;

	swap(node2.value,node8.value);

	RecoverBST(&node1);

	cout<<"Node2:"<<node2.value<<" Node8:"<<node8.value<<endl;
	return 0;
}