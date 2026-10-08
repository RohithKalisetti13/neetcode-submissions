class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int>dist(n+1,INT_MAX);
        int answer=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto& it: times){
            adj[it[0]].push_back({it[1],it[2]}); //adjacency list u-->v,wt
        }

        dist[k]=0;
        pq.push({0,k});

        while(pq.size()>0){

            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if(d>dist[u]) continue;
            for(auto& edge : adj[u]){
                int v = edge.first;
                int wt = edge.second;

                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
                
            }
        }

        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            answer = max(answer, dist[i]);
        }

        return answer;
    }
};
