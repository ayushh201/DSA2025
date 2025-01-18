class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<P> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                int i=curr.first;
                int j=curr.second;
                for(int k=0;k<=3;k++){
                    int di=i+directions[k][0];
                    int dj=j+directions[k][1];
                    if(di>=0 && di<m && dj>=0 && dj<n && height[di][dj]==-1){
                        height[di][dj]=1+height[i][j];
                        q.push({di,dj});
                    }
                }
            }
        }
        return height;
    }
};
