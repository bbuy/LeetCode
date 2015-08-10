Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

DP: 用一维数组来记录上一行的minmum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(!grid.size())
            return 0;

        vector<int> PathSum(grid[0].size(),0);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==0&&j==0)
                    PathSum[0]=grid[0][0];
                else if(i==0)
                    PathSum[j]=grid[0][j]+PathSum[j-1];
                else if(j==0)
                    PathSum[0]=grid[i][0]+PathSum[0];
                else
                    PathSum[j]=min(PathSum[j],PathSum[j-1]) + grid[i][j];
            }
        }

        return PathSum[grid[0].size()-1];
    }
};
