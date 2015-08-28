Search for a Range Total Accepted: 53950 Total Submissions: 197387 My Submissions
Question  Solution





Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithms runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].


 class Solution {
 public:
     vector<int> searchRange(vector<int>& nums, int target) {
         int left = findBound(nums,target,true);
         int right = findBound(nums,target,false);

         if(nums[left]!=target)
             return vector<int>{-1,-1};
         else
             return vector<int>{left,right};
     }

     int findBound(vector<int>& nums, int target, bool lower)
     {
         int left = 0;
         int right = nums.size();
         int mid = 0;

         while(left<right)
         {
             mid = left + (right-left)/2;
             if(lower)
             {
                 if(nums[mid]<target)
                     left = mid + 1;
                 else
                     right = mid;
             }
             else
             {
                 if(nums[mid]<=target)
                     left = mid + 1;
                 else
                     right = mid;
             }
         }

         return lower?left:left-1;
     }
 };
