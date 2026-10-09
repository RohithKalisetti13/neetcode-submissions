class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq; //cost, nodes, stops
        
        vector<vector<int>>cost(n, vector<int>(k+2, INT_MAX));
        
        
        vector<vector<pair<int,int>>> adj(n);

        for(auto& it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        cost[src][0]=0;
        pq.push({0, src, 0});

        while(pq.size()>0){

            auto [price, node, stop] = pq.top();
            pq.pop();
            
            if(price > cost[node][stop] || stop == k+1) continue;

            for(auto& it : adj[node]){
                int v = it.first;
                int wt = it.second;

                int newStop = stop+1;
                int newPrice = price+wt;

                if(cost[v][newStop]>newPrice){
                    cost[v][newStop]=newPrice;
                    
                    pq.push({cost[v][newStop],v, newStop});
                }
            }
        }
        int answer = INT_MAX;
        for(int i=0; i<=k+1; i++){
            answer = min(answer,cost[dst][i]);
        }
        return answer == INT_MAX ? -1 : answer;



    }
};
