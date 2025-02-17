class Solution {
    private:
    int timer=1;
    void dfs(int node,int parent,vector<int> &vis,vector<int> adj[],int low[],int tin[],vector<vector<int>> &bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(int &it:adj[node]){
            if(it==parent) continue;
            else if(vis[it]==0){
                dfs(it,node,vis,adj,low,tin,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> bridges;
        vector<int> vis(n,0);
        int low[n], tin[n];
        dfs(0,-1,vis,adj,low,tin,bridges);
        return bridges;
    }
};
