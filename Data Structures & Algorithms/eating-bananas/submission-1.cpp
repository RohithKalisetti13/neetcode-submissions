class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();

        int maxPile=0;
        for(int i=0;i<n;i++){
            maxPile=max(maxPile, piles[i]);
        }
        int left = 1;
        int right = maxPile;

        
        while(left<=right){
            int mid = left+(right-left)/2;

            long long totalHours=0;
            for(int i=0;i<n;i++){
            totalHours += ceil((double)piles[i]/(double)mid);
            }
            
            if(totalHours<=h){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
