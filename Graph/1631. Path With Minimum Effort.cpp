class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> direction={{1,0},{-1,0},{0,-1},{0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int diff=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            if(x==m-1 && y==n-1){
                return dist[m-1][n-1];
            }
            for(auto &dir:direction){
                int dx=x+dir[0];
                int dy=y+dir[1];
                if(dx>=0 && dx<m && dy>=0 && dy<n){
                    int absDiff=abs(heights[x][y]-heights[dx][dy]);
                    int maxDiff=max(diff,absDiff);
                    if(dist[dx][dy]>maxDiff){
                        dist[dx][dy]=maxDiff;
                        pq.push({maxDiff,{dx,dy}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};
