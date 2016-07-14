// Numbers can be regarded as product of its factors. For example,

// 8 = 2 x 2 x 2;
//   = 2 x 4.

// Write a function that takes an integer n and return all possible combinations of its factors.

// Note:

//     You may assume that n is always positive.
//     Factors should be greater than 1 and less than n.

// Examples:
// input: 1
// output:

// []

// input: 37
// output:

// []

// input: 12
// output:

// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]

// input: 32
// output:

// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]


//My thoughts: This question is very similiar with sum combination. Use the smiliar way to solve this.

#include <iostream>
#include <vector>
using namespace std;
void DFS(vector<vector<int>>& result, vector<int>& solution, int start, int n)
{
  for(int i=start;i<=sqrt(n);i++)
  {
    if(n%i == 0)
    {
      vector<int> newline = solution;
      newline.push_back(i);
      int newN = n/i;
      DFS(result,newline,i,newN);
      newline.push_back(newN);
      result.push_back(newline);
    }
  }
}

vector<vector<int>> factComb(int n)
{
  vector<vector<int>> result;
  vector<int> solution;

  DFS(result,solution,2,n);

  return result;
}

int main()
{
  vector<vector<int>> result;
  result = factComb(24);
  for(auto l:result)
  {
    for(auto s:l)
      cout<<s<<" ";
    cout<<endl;
  }
  return 0;
}