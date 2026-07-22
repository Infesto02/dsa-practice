// here i was stuck on the helper function solution (on how i can run with passing to another function with a bool setting how we work inside the function) and 
// also that i can run the same the same also wth 2 diff values 2 times to get the result and no need to get it in 1 run 

// mojor mistake we passed the array by value creating a copy should create a ref here so no extra space also make it const so we dont modify the array by mistake 

// we use lower bound theory twice but second times is just a mirror 


class Solution {
public:
    int findBound( const vector<int>& nums, int target, bool findFirst){
        int l = 0, r = nums.size() -1, ans = -1;
        while(l <= r)
        {
            int mid = l + ( r - l ) / 2;
            if(nums[mid] == target){
                if(findFirst){
                    r = mid - 1;
                    ans = mid;
                }
                else {
                    l = mid + 1;
                    ans = mid;
                }
            }
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound( nums, target, true);
        int last = findBound( nums, target, false);

        return {first, last};
    }
};