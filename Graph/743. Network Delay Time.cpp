class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &time:times){
            int u=time[0];
            int v=time[1];
            int wt=time[2];
            adj[u].push_back({v,wt});
        }
        vector<int> distance(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        distance[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int dist=curr.first;
            int u=curr.second;
            for(auto &ngbr:adj[u]){
                int adjNode=ngbr.first;
                int wt=ngbr.second;
                if(dist+wt<distance[adjNode]){
                    distance[adjNode]=dist+wt;
                    pq.push({dist+wt,adjNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,distance[i]);
        }
        return ans==INT_MAX? -1:ans;
    }
};
