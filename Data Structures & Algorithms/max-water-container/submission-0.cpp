class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n-1;
        int currArea=0;
        int maxWater=0;
        int maxHeight=0;
        int width=0;
        while(left<right){
            width = right - left;
            maxHeight = min(heights[left],heights[right]);
            currArea = width * maxHeight;
            if(heights[left]<heights[right]) left++;
            else
            right--;

            maxWater = max(currArea, maxWater);
        }
        return maxWater;
    }
};
