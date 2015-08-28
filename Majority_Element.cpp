Majority Element Total Accepted: 57715 Total Submissions: 161771 My Submissions
Question  Solution





Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int max = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == max)
            {
                counter++;
            }
            else
            {
                counter--;
                if(counter==0)
                {
                    max = nums[i];
                    counter += 1;
                }
            }
        }

        return max;
    }
};
