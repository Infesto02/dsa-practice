class Solution {
public:

    int hoursNeeded(const vector<int>& piles, int speed){
        int hours = 0;
        for(int banana : piles){
            hours += banana / speed;
            if(banana % speed != 0) hours++;  // ceiling one liner form (p + k - 1) / k
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for( int banana : piles){
            if(max < banana ) max = banana ;
        }
        int l = 1, r = max, ans = max;
        while(l <= r ){
            int mid = l + ( r - l )/2;
            if( hoursNeeded(piles, mid) <= h){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }


        // for(current_speed = 1 ; current_speed < max ; current_speed++ ){
        //     hours = hoursNeeded(piles, current_speed);
        //     if(hours <= h) return current_speed;
        // }
        return ans;
    }
};