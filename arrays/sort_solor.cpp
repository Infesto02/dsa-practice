class Solution {
public:
    void sortColors(vector<int>& nums) {
      int low = 0, high = nums.size() - 1, run = 0 ;
      while( run <= high){
        if(nums[run] == 0){
            swap(nums[low], nums[run]);
            low++;
            run++;
        }
        else if(nums[run] == 2){
            swap(nums[run], nums[high]);
            high--;
        }
        else run++;
      }
    }
};