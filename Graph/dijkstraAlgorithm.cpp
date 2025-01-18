#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    typedef pair<int,int> P;
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n=adj.size();
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<int> result(n,INT_MAX);
        result[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int cost=curr.first;
            int node=curr.second;
            for(auto ngbr:adj[node]){
                int adjNode=ngbr.first;
                int wt=ngbr.second;
                if(cost+wt<result[adjNode]){
                    result[adjNode]=cost+wt;
                    pq.push({cost+wt,adjNode});
                }
            }
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
