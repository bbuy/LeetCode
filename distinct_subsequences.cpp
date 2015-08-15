Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

用DP: DP[i][j] repersent: number of distinct subsenquence first i char in T  and first j char in string S

转移方程为： DP[i][j] = DP[i][j-1] + (if S[j-1](第j个字母)==T[i-1])DP[i-1][j-1];
如果最后一个字母不同 那么 DP[i][j] = DP[i][j-1]
如果最后一个字母相同 那么还要加上 DP[i-1][j-1];

class Solution {
public:
    int numDistinct(string s, string t) {
        if(!s.length())
        return 0;
        if(s.length()<t.length())
        return 0;

        vector<int> Line(s.length()+1,0);
        vector < vector<int> > DP(t.length()+1,Line);
        for(int i=0;i<=s.length();i++)
            DP[0][i] = 1;

        for(int i=1;i<=t.length();i++)
        {
            for(int j=1;j<=s.length();j++)
            {
                if(t[i-1]==s[j-1])
                    DP[i][j]=DP[i-1][j-1]+DP[i][j-1];
                else
                    DP[i][j]=DP[i][j-1];
            }
        }
        return DP[t.length()][s.length()];
    }
};
