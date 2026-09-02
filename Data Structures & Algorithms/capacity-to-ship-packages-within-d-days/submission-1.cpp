class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
         int maxW=0;
         int totalW = 0;
         
         for(int i: weights){
            totalW += i;
            maxW = max(maxW, i);
         }
         
         int left = maxW;
         int right = totalW;

         while(left<=right){
            int mid = left + (right-left)/2;
            int daysneeded=1;
            int currentload=0;

            for(int i : weights){
               if(currentload+i > mid){
                  daysneeded++;
                  currentload =0;
               }
               currentload+=i;
            }
            if(daysneeded<=days){
               right=mid-1;
            }
            else{
               left=mid+1;
            }
         }
         return left;
    }
};