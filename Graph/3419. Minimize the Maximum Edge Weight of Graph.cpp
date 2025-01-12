class Solution {
    private:
    bool isPossible(int n, vector<vector<int>>& edges, int maxWeight){
        vector<vector<int>> revGraph(n);
        for(auto &edge:edges){
            if(edge[2]<=maxWeight){
                revGraph[edge[1]].push_back(edge[0]);
            }
        }
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int count=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int ngbr:revGraph[curr]){
                if(!visited[ngbr]){
                    visited[ngbr]=true;
                    q.push(ngbr);
                    count++;
                }
            }
        }
        return count==n;
    }
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int minW=INT_MAX, maxW=INT_MIN;
        for(auto &edge:edges){
            minW=min(minW,edge[2]);
            maxW=max(maxW,edge[2]);
        }
        int ans=-1,l=minW,h=maxW;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(n,edges,mid)){
                ans=mid;
                h=mid-1;            
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
