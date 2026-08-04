class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int target_index = -1, l = 0 , r = nums.size() - 1 ;
        while( l <= r){
            int mid = l + ( r - l ) / 2;
            if(nums[mid] == target ) return true;
            else if(nums[r] == nums[l] && nums[l] != target ) {
                r--;
                l++;
            }
            else if( nums[l] <= nums[mid] ){
                if( nums[mid] > target && nums[l] <= target) r = mid - 1;
                else l = mid + 1;
            }
            else{
                if(target > nums[mid] && nums[r] >= target) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};

/*Insight: rotated array + duplicates. When nums[l] == nums[mid] == nums[r], the nums[l] <= nums[mid] detection is fooled (true by equality, not by actual sortedness) — shave one off each end. Safe because mid ≠ target (already checked) + all three equal ⟹ both ends ≠ target.
Why not the two-way nums[l] == nums[r] guard: when only the ends match but mid differs, detection is reliable (the value difference makes <= informative), so steer normally — shaving would be needless. {3,1,3}/9 exercises this; {1,0,1}/1 shows the two-way guard discarding the target.
Complexity: worst case O(n), not O(log n) — trigger {1,1,...,0,...,1,1} searching 0. This is the interview question on the problem.*/