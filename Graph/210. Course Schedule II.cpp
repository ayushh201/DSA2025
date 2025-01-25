class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
        vector<int> adj[v];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(int &it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int &ngbr:adj[node]){
                indegree[ngbr]--;
                if(indegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }
        if(ans.size()==v){
            return ans;
        }else{
            return {};
        }
    }
};
