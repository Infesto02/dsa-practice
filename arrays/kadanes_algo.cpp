/*
LC 53 — Maximum Subarray (Kadane's)
Insight: carrying a negative running sum only hurts every future
subarray → reset to 0 when sum < 0. "Extend or restart."
Traps: max_sum must init to INT_MIN (all-negative arrays);
       index variant → update best indices ONLY when max_sum updates.
C++ learned: bare `tuple` needs <int,int,int>; struct + structured
       bindings for multi-return; fix FIRST compiler error only.
Date: 15/07/26 | Re-solve: 22/07, then ~15/08
*/





class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size() ; i ++)
        {
            if(sum < 0 ) sum = 0;
            sum += nums[i];

            if(max_sum < sum) max_sum = sum;
        }
        return max_sum;
    }
};