/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/



class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = 0;
        vector<int> prefix(nums.size()+1, 0);
        for(int i=0; i< nums.size(); i++)
            if(nums[i] == 0)
                nums[i] = -1;
        
        prefix[0] = 0;
        for(int i=1; i<prefix.size(); i++)
            prefix[i] = prefix[i-1] + nums[i-1];
        
        unordered_map<int, int> index;
        for(int i=0; i< prefix.size(); i++){
            if(index.count(prefix[i]))
                len = max(len, i - index[prefix[i]]);
            else
                index[prefix[i]] = i;
        }
        return len;
    }
};
