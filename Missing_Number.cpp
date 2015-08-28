Missing Number Total Accepted: 5741 Total Submissions: 17966 My Submissions
Question  Solution





Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
 Given nums = [0, 1, 3] return 2.

Note:
 Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.



Hide Tags
 Array Math Bit Manipulation

Hide Similar Problems
 (H) First Missing Positive (M) Single Number

 class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int rtn = 0;
        for(int i=0;i<nums.size();i++)
            rtn ^= nums[i];
        for(int i = 0;i<=n;i++)
            rtn ^= i;

        if(rtn == 0)
        return 0;
        else
        return rtn;
    }
};
