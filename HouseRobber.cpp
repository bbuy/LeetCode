// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.


class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size())
        return 0;

        int length = nums.size();

        vector<int> NS(length);
        vector<int> S(length);

        S[0] = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            S[i] = nums[i] + NS[i-1];
            NS[i] = max(S[i-1],NS[i-1]);
        }

        return max(S[length-1],NS[length-1]);
    }
};
