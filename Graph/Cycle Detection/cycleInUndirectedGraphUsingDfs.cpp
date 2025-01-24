#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool dfs(int u,vector<vector<int>>& adj,vector<bool> &visited,int parent){
        visited[u]=true;
        for(int &v:adj[u]){
            if(v==parent) continue;
            if(visited[v]) return true;
            if(dfs(v,adj,visited,u)) return true;
        }
        return false;
    }
  public:
    bool isCycle(vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(!visited[i] && dfs(i,adj,visited,-1)){
                return true;
            }
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
