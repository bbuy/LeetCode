class Solution {
public:

void DFS(vector<vector<string>>& res, vector<string>& solution, vector<bool>& colQ, vector<bool>& diag1, vector<bool>& diag2, int row, int& col)
{
    if(row == col)
    {
        res.push_back(solution);
        return;
    }

    for(int i=0;i<col;i++)
    {
        if(!colQ[i]&&!diag1[row+i]&&!diag2[col-row-1+i])
        {
            solution[row][i]='Q';
            colQ[i]=true;
            diag1[row+i]=true;
            diag2[col-row-1+i]=true;
            DFS(res,solution,colQ,diag1,diag2,row+1,col);
            solution[row][i]='.';
            colQ[i]=false;
            diag1[row+i]=false;
            diag2[col-row-1+i]=false;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> res;
    string row (n,'.');
    vector<string> solution(n,row);
    vector<bool> colQ(n,false);
    vector<bool> diag1(2*n-1,false);
    vector<bool> diag2(2*n-1,false);
    DFS(res,solution,colQ,diag1,diag2,0,n);
    return res;
}

};
