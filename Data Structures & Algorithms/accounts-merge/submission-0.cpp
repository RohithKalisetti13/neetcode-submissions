class Solution {
public:
    vector<int>accountIndex;
    vector<int>rank;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        accountIndex.resize(n);
        rank.resize(n, 0);

        for(int i=0;i<n;i++){
            accountIndex[i]=i;
        }
        unordered_map<string,int>match;
        vector<vector<string>>grouped(n);
        vector<vector<string>>result;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];

                if(match.find(email)==match.end()){
                    match[email]=i;
                }
                else{
                    mergeUnion(i, match[email]);
                }
            }
        }

        for(auto& it : match){
            string email = it.first;
            int root = findF(it.second);
            grouped[root].push_back(email);
        }

        for(int i=0;i<n;i++){
            if (grouped[i].empty()) continue;
            sort(grouped[i].begin(),grouped[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto& it : grouped[i]){
                temp.push_back(it);
            }
            result.push_back(temp);
        }
        return result;
    }

    int findF(int s){
        if(accountIndex[s]==s) return s;
        accountIndex[s]=findF(accountIndex[s]);
        return accountIndex[s];
    }

    bool mergeUnion(int a1, int a2){
        int parentA = findF(a1);
        int parentB = findF(a2);

        if(parentA == parentB) return true;

        if(rank[parentA]==rank[parentB]){
            accountIndex[parentB] = parentA;
            rank[parentA]++;
        }

        else if(rank[parentA]>rank[parentB]){
            accountIndex[parentB] = parentA;
        }
        else{
            accountIndex[parentA] = parentB;
        }

        return false;
    }
};