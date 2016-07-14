//  Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:

//     All numbers (including target) will be positive integers.
//     The solution set must not contain duplicate combinations.

// For example, given candidate set [2, 3, 6, 7] and target 7,
// A solution set is:

// [
//   [7],
//   [2, 2, 3]
// ]


// This question needs an DFS search, loop through all the combinations and add the combination to the result if its sum equals target.


#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<int>& candidates, int idx, int target, vector<int>& solution, vector<vector<int>>& result)
{
	if(target == 0)
	{
		result.push_back(solution);
		return;
	}
	else if(target<0)
	{
		return;
	}
	else
	{
		for(int i=idx;i<candidates.size();i++)
		{
			solution.push_back(candidates[i]);
			DFS(candidates,i,target-candidates[i],solution,result);
			solution.pop_back();
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> result;
	vector<int> solution;
	DFS(candidates,0,target,solution,result);

	return result;
}

int main()
{
	vector<int> test1 = {2, 3, 6, 7};
	vector<vector<int>> test1Result = combinationSum(test1,7);
	for(auto v:test1Result)
	{
		for(auto i:v)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
} 