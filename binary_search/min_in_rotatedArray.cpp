class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = INT_MAX, l = 0, r = nums.size() - 1;
        while( l < r )
        {
            int mid = l + ( r - l ) / 2;
            if( nums[r] < nums[mid] ) l = mid + 1;
            else r = mid;
        }
        return nums[l];

// min is below 

        int lowest = INT_MAX, l = 0 , r = nums.size() - 1;
        while( l <= r ){
            int mid = l + ( r - l ) / 2;
            if( nums[mid] >= nums[l])
            {
                if( nums[l] < lowest ) lowest = nums[l];
                l = mid + 1;
            }
            else
            {
                if( nums[mid] < lowest ) lowest = nums[mid];
                r = mid - 1;
            }
        }
        return lowest;
    }
};