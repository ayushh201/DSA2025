class Solution {
    private:
    int dfs(int curr,int parent,unordered_map<int,vector<int>> adj,vector<bool>& hasApple){
        int time=0;
        for(int &child : adj[curr]){
            if(child == parent) continue;
            int timeFromChild = dfs(child,curr,adj,hasApple);
            if(timeFromChild>0 || hasApple[child]){
                time += timeFromChild+2;
            }
        }
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0,-1,adj,hasApple);
    }
};
