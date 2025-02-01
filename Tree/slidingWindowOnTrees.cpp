class Solution {
public:
    int maxlength=0;
    int minnodes=INT_MAX;
    void dfs(int node,int parent,vector<vector<pair<int,int>>> &gr,vector<int>& nums,int pathsum,int start,int end,unordered_map<int,int> &depthmap,vector<int> &path){
        int prevdepth=depthmap.count(nums[node])? depthmap[nums[node]]:-1;
        while(start<=prevdepth){
            pathsum-=path[start++];
        }
        if(pathsum>maxlength){
            maxlength=max(maxlength,pathsum);
            minnodes=end-start+1;
        }else if(pathsum==maxlength){
            minnodes=min(minnodes,end-start+1);
        }
        depthmap[nums[node]]=end;
        for(auto &[neighbour,wt]:gr[node]){
            if(neighbour!=parent){
                path.push_back(wt);
                dfs(neighbour,node,gr,nums,pathsum+wt,start,end+1,depthmap,path);
                path.pop_back();
            }
        }
        depthmap[nums[node]]=prevdepth;
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n=nums.size();
        vector<vector<pair<int,int>>> gr(n);
        for(auto &edge:edges){
            gr[edge[0]].emplace_back(edge[1],edge[2]);
            gr[edge[1]].emplace_back(edge[0],edge[2]);
        }
        unordered_map<int,int> depthmap;
        vector<int> path={};
        dfs(0,-1,gr,nums,0,0,0,depthmap,path);
        return {maxlength,minnodes};
    }
};
