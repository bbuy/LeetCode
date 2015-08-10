Dungeon Game
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K) -3 3
-5 -10 1
10 30 -5 (P)

DP: move from lowerright corner and check Bottom and Right, pick min and compare with 0. 

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(!dungeon.size()) return 0;

        vector<int> Health(dungeon[0].size(),0);
        Health[dungeon[0].size()-1] = 1;

        for(int i=dungeon.size()-1;i>=0;i--)
        {
            for(int j=dungeon[0].size()-1;j>=0;j--)
            {
                if((i == dungeon.size()-1)&&(j==dungeon[0].size()-1))
                    Health[j] = 1 - dungeon[i][j];
                else if(i == dungeon.size()-1)
                    Health[j] = Health[j+1]-dungeon[i][j];
                else if(j==dungeon[0].size()-1)
                    Health[j] = Health[j]-dungeon[i][j];
                else
                    Health[j] = min((Health[j+1]-dungeon[i][j]),(Health[j]-dungeon[i][j]));

                Health[j] = Health[j]<=0?1:Health[j];
            }
        }
        return Health[0];
    }
};
