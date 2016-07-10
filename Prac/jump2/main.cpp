// 45. Jump Game II

//     Total Accepted: 67614
//     Total Submissions: 265043
//     Difficulty: Hard

// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// For example:
// Given array A = [2,3,1,1,4]

// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

// Note:
// You can assume that you can always reach the last index.

// My first thought is using DP. Start from back and towards front.  Allocate an array to store the minimum jumps N_i from i.  MiniJumps[size]. 
// Then DP got Timeout, 

// int canJump2(vector<int>& nums)
// {
// 	vector<int> miniJumps(nums.size(), 0);
 
// 	for(int i = nums.size()-2;i>=0;i--)
// 	{
// 		int range = nums[i];
// 		if(range == 0)
// 		continue;

// 		int min = INT_MAX;
// 		bool found = false;

// 		for(int j=1;j<=range;j++)
// 		{
// 			if(i + j >= nums.size()-1)
// 			{
// 				miniJumps[i] = 1;
// 				break;
// 			}
// 			else
// 			{
// 				if (miniJumps[i+j]!=0 && miniJumps[i+j] +1 < min)
// 				{
// 					min = miniJumps[i+j] + 1;
// 				}

// 				if (miniJumps[i+j] != 0)
// 					found = true;
// 			}
// 			if(found && j == range)
// 				miniJumps[i] = min;
// 		}
// 	}

// 	for(auto i:miniJumps)
// 		cout<<i<<" ";
// 	cout<<endl;

// 	return miniJumps[0];
// }


// Let's think about greedy then. The minimum number of jumps, For example From position 0, it can jump to 1 ,2 ,3,  which one shoule it jump to?  If from 1 you can jump to farest to 4, 2 you can jump to farest to 5, 3 you can jump to farest 4. 
// Then always jump to the position from where your next range is the farest. Easy. 



#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int canJump2(vector<int>& nums)
{
	int steps = 0;
	int i = 0;
	while(true)
	{
		cout<<"i"<<i<<endl;
		if(i>= nums.size()-1)
		break;
		
		int range = nums[i];
		int tmpMax = INT_MIN;
		int tmpIdx = i;
		for(int j=1;j<=range;j++)
		{
			if(i+j+nums[i+j] > tmpMax)
			{
				tmpMax = i+j+nums[i+j];
				tmpIdx = i+j;
			}
		}

		steps++;
		i = tmpIdx; 
	}

	return steps;
}

int main()
{
	vector<int> test1 = {5,9,3,2,1,0,2,3,3,1,0,0};

	cout<<canJump2(test1)<<endl;
	return 0;
}