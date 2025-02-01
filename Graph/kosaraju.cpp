#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node,vector<int> &visited,vector<vector<int>> &adj,stack<int> &st){
        visited[node]=1;
        for(auto &it:adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj,st);
            }
        }
        st.push(node);
    }
    void dfs1(int node,vector<int> &visited,vector<int> adjT[]){
        visited[node]=1;
        for(auto &it:adjT[node]){
            if(!visited[it]){
                dfs1(it,visited,adjT);
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int V=adj.size();
        vector<int> visited(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            visited[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!visited[node]){
                scc++;
                dfs1(node,visited,adjT);
            }
        }
        return scc;
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
        cout << obj.kosaraju(adj) << "\n";
    }

    return 0;
}
