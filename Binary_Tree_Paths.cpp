Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:


   1
 /   \
2     3
 \
  5



All root-to-leaf paths are:
["1->2->5", "1->3"]


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void DFS(TreeNode* root,vector<string>& result,string& path)
    {
        if(root==NULL)
        {
            return;
        }

        int size = path.size();
        if(size)
        {
            path+=("->");
        }
        path+=to_string(root->val);

        if(root->left==NULL&&root->right==NULL)
        {
            result.push_back(path);
        }
        else
        {
            DFS(root->left,result,path);
            DFS(root->right,result,path);
        }
        path= path.substr(0,size);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> result;
        if(root==NULL)
        return result;

        DFS(root,result,path);
        return result;
    }
};
