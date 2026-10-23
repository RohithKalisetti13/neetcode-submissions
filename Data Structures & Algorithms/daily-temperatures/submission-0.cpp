class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
         stack<int> st;
         vector<int>answer(n, 0);

         for(int i=0;i<n;i++){
            
         }

         for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]) {
                int prev = st.top();
                answer[prev]=(i-prev);
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};
