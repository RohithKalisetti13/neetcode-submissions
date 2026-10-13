class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>inMST(n, false);
        int totalCost =0;
        pq.push({0,0});

        while(pq.size()>0){

            int currCost = pq.top().first;
            int curr = pq.top().second;

            pq.pop();

            if(inMST[curr]) continue;

            inMST[curr]=true;
            totalCost += currCost;

            for(int next = 0;next<n;next++){
                if(!inMST[next]){
                    int cost = abs(points[curr][0]-points[next][0]) + abs(points[curr][1]-points[next][1]);

                    pq.push({cost, next});
                }
            }

        }
        return totalCost;
    }
};
