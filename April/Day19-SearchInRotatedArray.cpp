/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start =0, end = n-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            cout<<mid<<" ";
            if(nums[mid] == target)
                return mid;
            //if both target and mid are on same side
            if((nums[mid] - nums[n-1])*(target - nums[n-1]) > 0){
                if(target > nums[mid])
                    start = mid+1;
                else
                    end = mid-1;// -1;
            }
            else if(target > nums[n-1]){ //target on the left side
                end = mid-1;//-1;
            }else{ //target on the right side, mid on the left side
                start = mid+1;
            }
        }
        return -1;
    }
};
