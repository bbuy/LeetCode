// Coding: 给一颗二叉树，每一个节点有一个value，找出一堆不相邻的节点，使得他们value的和最大。节点之间有link就算相邻，比如parent和children

#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
	int val;
	Node* left;
	Node* right;
	Node(int v):left(NULL),right(NULL),val(v){}
};

vector<Node*> MaxFromRoot(Node* root, int& max);

int MaxWithOutRoot(Node* root, vector<Node*>& list)
{
	int left = 0;
	int right = 0;

	auto leftV = MaxFromRoot(root->left, left);
	auto rightV = MaxFromRoot(root->right, right);
	list.insert(list.end(),leftV.begin(),leftV.end());
	list.insert(list.end(),rightV.begin(),rightV.end());
	return left + right;
}

int MaxWithRoot(Node* root, vector<Node*>& list)
{
	int sum = 0;
	if(!root)
		return sum;

	sum += root->val;
	list.push_back(root);

	if(root->left)
	{
		sum += MaxWithOutRoot(root->left, list);
	}
	if(root->right)
	{
		sum += MaxWithOutRoot(root->right, list);
	}

	return sum;
}

vector<Node*> MaxFromRoot(Node* root, int& max)
{
	vector<Node*> withRoot;
	vector<Node*> withOutRoot;
	if(!root)
		return withRoot;

	int wr = MaxWithRoot(root, withRoot);
	int wor = MaxWithOutRoot(root, withOutRoot);

	if(wr>wor)
	{
		max = wr;
		return withRoot;
	}
	else
	{
		max = wor;
		return withOutRoot;
	}
}

int main()
{
	Node Node1(1);
	Node Node2(22);
	Node Node3(3);
	Node Node4(4);
	Node Node5(5);
	Node Node6(6);
	Node Node7(7);

	Node1.left = &Node2;
	Node1.right = &Node3;

	Node2.left = &Node4;
	Node2.right = &Node5;

	Node3.left = &Node6;
	Node3.right = &Node7;

	int sum = 0;
	vector<Node*> result = MaxFromRoot(&Node1, sum);
	cout<<sum<<endl;
	return 0;
}