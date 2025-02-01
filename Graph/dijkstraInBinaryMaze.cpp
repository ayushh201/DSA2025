#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int shortestDistance(int n, int m, vector<vector<int>> mat, int x, int y) {
        if (mat[0][0]==0 || mat[x][y]==0) return -1;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> visited(n,vector<int>(m,INT_MAX));
        visited[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int dist=node.first;
            int r=node.second.first;
            int c=node.second.second;
            if(r==x && c==y) return dist;
            for(vector<int> &dir:directions){
                int di=r+dir[0];
                int dj=c+dir[1];
                if(di>=0 && di<n && dj>=0 && dj<m && mat[di][dj]==1 && 1+dist<visited[di][dj]){
                    visited[di][dj]=1+dist;
                    q.push({1+dist,{di,dj}});
                }
            }
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    
cout << "~" << "\n";
}
}
