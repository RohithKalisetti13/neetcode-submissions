class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int currP = 0;
        int maxP = INT_MIN;
        int buy = prices[0];
        for( int i=1;i<prices.size();i++){
            buy = min(buy,prices[i]);
            currP = prices[i]-buy;
            maxP = max(maxP, currP);
        }
        return maxP;
    }
};
