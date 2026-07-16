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