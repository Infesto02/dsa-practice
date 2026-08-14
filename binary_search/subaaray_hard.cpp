class Solution {
public:
    int noOfSubArray(const vector<int>& nums, int bucket_size){
        int bucket = 0, no_of_bucket = 1;
        for( int i : nums){
            int temp = bucket + i;
            if( temp > bucket_size){
                bucket = 0; no_of_bucket++;
            }
            bucket += i;
        }
        return no_of_bucket;
    }
    int splitArray(vector<int>& nums, int k) {
        int max_size = 0, min_size = 0;
        for(int i : nums){
            if(min_size < i) min_size = i;
            max_size += i;
        }
        int l = min_size, r = max_size, ans = 0;
        while(l <= r )
        {
            int mid = l + ( r - l ) / 2;
            if(noOfSubArray(nums, mid) <= k){
               ans = mid;
               r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};