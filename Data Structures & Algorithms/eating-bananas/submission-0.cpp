class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int maxPile=INT_MIN;
        for( int i: piles){
            maxPile = max(maxPile, i);
        }
        int right = maxPile;
        while(left<=right){
        
        int mid = left+(right-left)/2;
        long long totalH=0;
        for(int i = 0;i<piles.size();i++){
            totalH+=ceil(((double)piles[i])/(double)mid);
        }
            if(totalH<=h){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        
        }
        return left;
    }
};
