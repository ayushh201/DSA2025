class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>> adj;
        for(auto &edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        unordered_map<int,unordered_set<int>> mp;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int &ngbr:adj[node]){
                mp[ngbr].insert(node);
                for(auto &preq:mp[node]){
                    mp[ngbr].insert(preq);
                }
                indegree[ngbr]--;
                if(indegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }
        int Q=queries.size();
        vector<bool> result(Q,false);
        for(int i=0;i<Q;i++){
            int src=queries[i][0];
            int dest=queries[i][1];
            bool isReachable=mp[dest].contains(src);
            result[i]=isReachable;
        }
        return result;
    }
};
