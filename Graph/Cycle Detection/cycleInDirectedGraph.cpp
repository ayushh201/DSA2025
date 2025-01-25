#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool dfs(int u,vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        for(int &v:adj[u]){
            if(!visited[v] && dfs(v,adj,visited,inRecursion)) return true;
            else if(inRecursion[v]==true) return true;
        }
        inRecursion[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V,false);
        vector<bool> inRecursion(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i,adj,visited,inRecursion)){
                return true;
            }
        }
        return false;
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
