class Solution {
    private:
    bool checkBipartiteBFS(int node,vector<vector<int>>& adj,vector<int> &color,int currColor){
        queue<int> q;
        color[node]=currColor;
        q.push(node);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                if(color[v]==color[u]){
                    return false;
                }else if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(checkBipartiteBFS(i,adj,color,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
