class Solution {
    private:
    int solve(int l,int r,vector<int>& cuts){
        if(r-l<2){
            return 0;
        }
        if(t[l][r]!=-1){
            return t[l][r];
        }
        int result=INT_MAX;
        for(int i=l+1;i<=r-1;i++){
            int cost=solve(l,i,cuts)+solve(i,r,cuts)+(cuts[r]-cuts[l]);
            result=min(result,cost);
        }
        return t[l][r]=result;
    }
public:
    int t[103][103];
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts),end(cuts));
        cuts.insert(begin(cuts),0);
        cuts.push_back(n);
        memset(t,-1,sizeof(t));
        return solve(0,cuts.size()-1,cuts);
    }
};
