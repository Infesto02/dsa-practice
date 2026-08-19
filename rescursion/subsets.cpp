class Recursion {

    void Snapshot( int index, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result ){
        if( index == nums.size()){
            result.push_back(current);
            return ;
        }

        current.push_back(nums[index]);
        Snapshot(index + 1, nums, current, result );
        current.pop_back();

        Snapshot(index + 1 , nums, current, result);
    }
     
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        Snapshot(0, nums, current, result);
        return result;
    }
};