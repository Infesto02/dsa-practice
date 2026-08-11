//the binary search is trivial; the predicate function is where the bugs live.
//Insight: same as Koko — BS-on-answers, lower bound over [max_weight, sum] with predicate cal_days(cap) <= days. Wrinkle vs Koko: lower bound is max(weights), not 1, because a capacity below the heaviest package can never ship it.
//Trap: the feasibility function, not the search, is the bug source. Specifically: the package that overflows the current day must still ship on the new day — load the weight unconditionally after the fit-check, not inside the else.

class Solution {
public:
    int cal_days(const vector<int>& weights, int cap){
        int days = 1, current_weigh = 0;
        for(int w : weights){
            int temp = current_weigh + w;
            if( temp > cap ) {
                days++;
                current_weigh = 0;   
            }
            current_weigh += w;            
        }
        return days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int max_cap = 0, min_cap = 0;
        for(int size : weights){
            if(min_cap < size ) min_cap = size;
            max_cap += size;
        }
        
        int l = min_cap, r = max_cap, ans = max_cap;
        while( l <= r ){
            int mid = l + (r - l ) / 2;
            if(cal_days( weights, mid ) <= days){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};