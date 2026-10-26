class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>sum;
        sort(candidates.begin(),candidates.end());
        combination(0, candidates, target, result, sum);
        return result;
    }

    void combination(int start, vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& sum){
        if(target == 0){
            result.push_back(sum);
            return;
        }
        
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;

            sum.push_back(candidates[i]);
            combination(i+1, candidates, target-candidates[i], result, sum);
            sum.pop_back();

        }
    }

};
