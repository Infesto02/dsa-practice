class Solution {
public:

    bool placeBalls(const vector<int>& position, int max_force, int m ){
        int last_place = position[0];
        int balls = 1;
        for(int i = 1; i < position.size() ; i++){
            if((position[i] - last_place) >= max_force){
                balls++;
                last_place = position[i];
            }
        }
        return balls >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());        
        int l = 1, r = position.back() - position.front(), ans = 0;
        while( l <= r){
            int mid = l + ( r - l ) / 2;
            if(placeBalls(position, mid, m)){
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
        } 

        return ans;
    }
};