//  Given a binary tree

//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Note:

//     You may only use constant extra space.
//     You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

// For example,
// Given the following perfect binary tree,

//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7

// After calling your function, the tree should look like:

//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL


// I was thinking of level travesal. But the question requires costant space.
// The solution is easy. populate left and right, then move to next level, When moved to next level, root already has next pointer, so it will be easy when populiating it's child node.

#include <iostream>
#include <vector>

using namespace std;

class Node
{
  public:
    Node* left;
    Node* right;
    Node* next;
    int val;
    Node(int v) : left(NULL),right(NULL),next(NULL),val(v)
    {
    }
};

void printLevel(vector<Node*>& level)
{
  for(int i=0;i<level.size();i++)
  {
    if(level[i]==NULL)
      cout<<"NULL"<<endl;
    else
    {
      cout<<level[i]->val;
    }
  }

  cout<<endl;
}

void printLevelUseNext (Node* root)
{

}

void printTree(Node* root, bool useNext)
{
    vector<Node*> levelA;
    vector<Node*> levelB;
    levelA.push_back(root);

    while(levelA.size() || levelB.size())
    {
        // Print level A
        if(!useNext)
        printLevel(levelA);
        else
        {
          printLevelUseNext(levelA[0]);
        }

        while(levelA.size())
        {
          Node* first = levelA.front();
          if(first->left) levelB.push_back(first->left);
          if(first->right) levelB.push_back(first->right);
          levelA.erase(levelA.begin());
        }

        levelA.swap(levelB);
    }
}

Node* findNext(Node* root)
{
  while(root)
  {
    if(root->left) return root->left;
    if(root->right) return root->right;
    root = root->next;
  }

  return NULL;
}

void populateNext(Node* root)
{
  if(!root)
    return;
  if(root->left)
  {
    root->left->next = root->right? root->right:findNext(root->next);
  }

  if(root->right)
  {
    root->right->next = findNext(root->next);
  }

  populateNext(root->right);
  populateNext(root->left);
}

int main()
{
  Node* root = new Node(1);
  root->left = new Node(3);
  root->right = new Node(4);
  root->left->left = new Node(8);
  root->right->right = new Node(12);
  printTree(root, false);

  cout<<"Populating..."<<endl;

  populateNext(root);

  printTree(root,true);
  return 0;
}