class Solution {
public:
    int trap(vector<int>& height) {
      int maxWater=0;
      int leftMax=0;
      int rightMax=0;
      int left =0;
      int right = height.size()-1;
      while(left<right){
        if(height[left]<height[right]){
        if(leftMax>height[left]){
            maxWater += leftMax-height[left];
        }
        else{
            leftMax=height[left];
        }
        left++;
        }
        else{
            if(rightMax>height[right]){
            maxWater += rightMax-height[right];
        }
        else{
            rightMax=height[right];
        }
        right--;
        }
      }
      return maxWater;
    }
};
