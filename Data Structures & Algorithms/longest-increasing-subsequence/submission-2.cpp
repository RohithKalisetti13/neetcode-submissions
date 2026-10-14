class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>tails;

        for(int num : nums){
            
            int left = 0;
            int right = tails.size()-1;
            // auto it = lower_bound(tails.begin(),tails.end(), num);|
            // if(it== tails.end()) tails.push_back(num);
            // else{
            //     *it = num;
            // }

            while(left<=right){
                int mid = left + (right-left)/2;
                if(tails[mid]>= num){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            if(left==tails.size()){
                tails.push_back(num);
            }
            else{
                tails[left]=num;
            }
        }
        return tails.size();
    }
};
