Surrounded Regions Total Accepted: 35718 Total Submissions: 241476 My Submissions 
Question  Solution  





Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region. 

For example,

X X X X
X O O X
X X O X
X O X X



After running your function, the board should be: 
X X X X
X X X X
X X X X
X O X X

class Solution {
public:
    void populate(vector<vector<char>>& board,vector<vector<char>>& newboard, int i, int j)
    {
        newboard[i][j]='O';
        if(i>1 && board[i-1][j]=='O'&&newboard[i-1][j]=='X')
        {
            populate(board,newboard,i-1,j);
        }
        if(i<board.size()-1 && board[i+1][j]=='O'&&newboard[i+1][j]=='X')
        {
            populate(board,newboard,i+1,j);
        }
        if(j>1 && board[i][j-1]=='O'&&newboard[i][j-1]=='X')
        {
            populate(board,newboard,i,j-1);
        }
        if(j<board[0].size()-1 && board[i][j+1]=='O'&&newboard[i][j+1]=='X')
        {
            populate(board,newboard,i,j+1);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        int m = board.size();
        int n = board[0].size();
        vector<char> line(n,'X');
        vector< vector<char> > newboard(m,line);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0||j==0||i==(m-1)||j==(n-1))&&board[i][j]=='O')
                populate(board,newboard,i,j);
            }
        }
        board = newboard;
    }
};
