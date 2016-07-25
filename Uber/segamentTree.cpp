#include <vector>
#include <iostream>

using namespace std;

class Node{
    public:
    int leftR;
    int rightR;
    int value;
    int sum;
    Node* left;
    Node* right;
    Node(int l,int r):leftR(l),rightR(r),value(0),left(NULL),right(NULL),sum(0){}
};

Node* root;
    Node* ConstructTree(vector<int>& nums, int left, int right)
    {
        if(left>right)
        return NULL;
        
        Node* newNode = new Node(left,right);
        if(left == right)
        {
            newNode->sum = nums[left];
            return newNode;
        }
        
        int mid = left + (right - left)/2;
        newNode->right = ConstructTree(nums,mid+1,right);
        newNode->left = ConstructTree(nums,left,mid);
        newNode->value = mid;
        
        newNode->sum += newNode->right?newNode->right->sum:0;
        newNode->sum += newNode->left?newNode->left->sum:0;
        
        return newNode;
    }
    
    void NumArray(vector<int> &nums) {
        root = ConstructTree(nums,0,nums.size()-1); 
    }

    int sumRangeDFS(int i, int j, Node* it)
    {
        if(i==it->leftR && j==it->rightR)
        return it->sum;
        else
        {
            if(j<=it->value)
                return sumRangeDFS(i,j,it->left);
            else if(i>it->value)
                return sumRangeDFS(i,j,it->right);
            else
                {
                    int mid = it->value;
                    return sumRangeDFS(i,mid,it->left) + sumRangeDFS(mid+1,j,it->right);
                }
        }
    }

    int sumRange(int i, int j) {
        return sumRangeDFS(i,j,root);
    }

int main()
{
    vector<int> testV = {1,2,3,4,5,6,7};

    NumArray(testV);

    Node* it = root;

    while(it)
    {
        cout<<"Range"<<it->leftR<<":"<<it->rightR<<endl;
        it=it->left;
    }

    cout<<sumRange(2,5)<<endl;
    return 0;
}






// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);