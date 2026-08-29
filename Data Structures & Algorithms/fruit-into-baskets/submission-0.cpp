class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int left = 0;
       unordered_map<int,int> freq;
        int maxFruits=0;
       for(int right =0;right<fruits.size();right++){
        freq[fruits[right]]++;
        if(freq.size()>2){
            freq[fruits[left]]--;
            if(freq[fruits[left]]==0) {
                freq.erase(fruits[left]);
            }
            left++;
        }
        maxFruits = max(maxFruits, right-left+1);

       }
     return maxFruits;   
    }
};