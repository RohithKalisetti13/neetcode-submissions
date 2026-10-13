class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n-1;
        int maxWater=0;
        while(left<right){
            int width = right-left;
            int height = min(heights[right],heights[left]);
            int currArea = width * height;
            if(heights[right]<heights[left]) right--;
            else{
                left++;
            }
            maxWater = max(currArea, maxWater);
        }
        return maxWater;
    }
};
