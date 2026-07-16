class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 ;
        for(int day = 0; day < prices.size() ; day++ )
        {
            if(day > 0 && prices[day] > prices[day-1]) 
            {
                profit = profit + prices[day] - prices[day-1];
            }
        }
         return profit;
    }
};