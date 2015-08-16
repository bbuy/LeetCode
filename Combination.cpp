Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
 If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]



class Solution {
public:
    void DFS(vector<vector<int>>& result, vector<int>& path, int n, int k, int start)
    {
        if(k==0)
        {
            result.push_back(path);
            return;
        }

        for(int i=start;i<=n-k+1;i++)
        {
            path.push_back(i);
            DFS(result,path,n,k-1,i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector< vector<int> > result;
        if(!n||!k) return result;
        vector<int> path;
        DFS(result,path,n,k,1);
        return result;
    }
};
