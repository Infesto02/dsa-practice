class Solution {
public:

    void CheckCandidate( int index, const vector<int>& candidates, const int& target, vector<int>& checkPossibility, vector<vector<int>>& result){
        auto sum = accumulate(checkPossibility.begin(), checkPossibility.end(), 0);
        if(sum == target){
            result.push_back(checkPossibility);
            return;
        }
        else if(sum > target){
            return;
        }
        if (index == candidates.size()) return;   // no candidates left to consider
        

        checkPossibility.push_back(candidates[index]);
        CheckCandidate(index, candidates, target, checkPossibility, result);
        checkPossibility.pop_back();

        
        CheckCandidate(index + 1, candidates, target, checkPossibility, result);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> checkPossibility;
        vector<vector<int>> result;

        CheckCandidate(0, candidates, target, checkPossibility, result);

        return result;

    }
};