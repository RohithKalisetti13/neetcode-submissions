class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int>st;
        int area = 0;
        int width =0;
        int currH =0;

        for(int i=0;i<=n;i++){
            if(i==n) currH = 0;
            else{
                currH = heights[i];
            }

            while(!st.empty() && currH<heights[st.top()]){
                int idx = st.top();
                st.pop();

                 if(st.empty()){
                    width = i;
                 } 
                 else {
                    width = i-st.top()-1;
                 }
                
                area = width * heights[idx];
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }
};
