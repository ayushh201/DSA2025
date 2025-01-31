//Approach - 1 DSU
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int n;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if(root_i != root_j) {
            if(rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else  if(rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else {
                parent[root_j] = root_i;
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(i,j);
                }
            }
        }
        int groups=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                groups++;
            }
        }
        return n-groups;
    }
};

//Approach - 2 DFS
class Solution {
    private:
    void dfs(int index,vector<vector<int>>& stones,vector<bool> &visited){
        visited[index]=true;
        for(int i=0;i<stones.size();i++){
            if(!visited[i] && (stones[index][0]==stones[i][0] || stones[index][1]==stones[i][1])){
                dfs(i,stones,visited);
            }
        }
    }
public:   
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> visited(n,false);
        int groups=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,stones,visited);
                groups++;
            }
        }
        return n-groups;
    }
};
