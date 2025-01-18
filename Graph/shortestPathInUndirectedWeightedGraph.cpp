#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    typedef pair<int,int> P;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<int> result(n+1,INT_MAX);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        result[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int cost=curr.first;
            int node=curr.second;
            for(auto ngbr:adj[node]){
                int adjNode=ngbr.first;
                int adjWt=ngbr.second;
                if(cost+adjWt<result[adjNode]){
                    result[adjNode]=cost+adjWt;
                    pq.push({cost+adjWt,adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        int destNode=n;
        if(result[destNode]==INT_MAX){
            return {-1};
        }
        vector<int> path;
        
        while(parent[destNode]!=destNode){
            path.push_back(destNode);
            destNode=parent[destNode];
        }
        path.push_back(1);
        reverse(begin(path),end(path));
        return path;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}
