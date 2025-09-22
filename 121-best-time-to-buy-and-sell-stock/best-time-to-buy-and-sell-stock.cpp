class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = prices[0];
        int sell = -1;
        int maxProfit = 0;

        for(int i=1;i<prices.size();i++)
        {
            if(prices[i] < buy)
            {
                buy = prices[i];
                sell = -1;
            }

            if(sell < prices[i])
            {
                sell = prices[i];
                if(maxProfit < sell - buy)
                {
                    maxProfit = sell - buy;
                }
            }
        }

        return maxProfit;        
    }
};