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

// start from the first element, if current position is end() or greater than end(), return steps,  loop through all the possible next positions, if the possible next position is beyond end() then return current steps + 1. 
// if non of the possible next position is end(), then pick the next position that from where can go the farest. 

int canJump2(vector<int>& nums)
{
	int lastPos = nums.size()-1;
	int idx = 0;
	int steps = 0;
	while(true)
	{
		if(idx>=lastPos)
		{
			return steps;
		}

		int range = nums[idx];

		int tmpMax = INT_MIN;
		int tmpIdx = idx;
		for(int i=1;i<=range;i++)
		{
			if(idx<9)
			{
				cout<<"idx"<<idx<<endl;
			}
			if((idx + i) >=lastPos)
			{
				return steps + 1;
			}
			else
			{
				int tmpLength = idx + i + nums[idx + i];
				if(tmpLength > tmpMax)
				{
					tmpMax = tmpLength;
					tmpIdx = idx + i;
				}
			}
		}

		steps++;
		idx = tmpIdx;
	}

	return steps;
}

int main()
{
	vector<int> test1 = {5,9,3,2,1,0,2,3,3,1,0,0};

	cout<<canJump2(test1)<<endl;
	return 0;
}