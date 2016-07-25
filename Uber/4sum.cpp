#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void twosum(vector<int>& nums, int target, vector<int>& sol, vector<vector<int>>& sols)
{
	int left = 0;
	int right = nums.size()-1;
	sort(nums.begin(),nums.end());;
	while(left<right)
	{
		int sum = nums[left]+nums[right];
		if(sum==target)
		{
			cout<<"target!"<<endl;
			sol.push_back(nums[left]);
			sol.push_back(nums[right]);
			sols.push_back(sol);
			sol.pop_back();
			sol.pop_back();
			left++;
			right--;
		}
		else if (sum<target)
		{
			cout<<"small"<<endl;
			left++;
		}
		else 
		{
			cout<<"big"<<endl;
			right--;
			cout<<nums[left]<<endl;
			cout<<nums[right]<<endl;
		}

		while(left>0 && nums[left]==nums[left-1] && left<nums.size()){left++;}
		while(right<nums.size()-1 && nums[right]==nums[right+1] && right>=0){right--;}
	}
}

int main()
{
	vector<int> test = {1,2,3,4,5,6,7,8,9,10};
	vector<vector<int>> rtn;
	vector<int> sol;
	twosum(test,9,sol,rtn);

	for(auto l:rtn)
	{
		cout<<"Start:";
		for(auto c:l)
			cout<<c<<" ";
		cout<<endl;
	}
	return 0;
}