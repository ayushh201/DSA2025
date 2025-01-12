class Solution {
    private:
    int solve(int i,int j,int k,vector<vector<int>>& coins){
        if(i==n-1 && j==m-1){
            if(k>0 && coins[i][j]<0){
                return 0;
            }else{
                return coins[i][j];
            }
        }
        if(i>=n || j>=m) return INT_MIN;
        if(t[i][j][k]!=-1){
            return t[i][j][k];
        }
        int take=INT_MIN, skip=INT_MIN;
        take=coins[i][j]+max(solve(i+1,j,k,coins),solve(i,j+1,k,coins));
        if(k>0 && coins[i][j]<0){
            skip=max(solve(i+1,j,k-1,coins),solve(i,j+1,k-1,coins));
        }
        return t[i][j][k]=max(take,skip);
    }
public:
    int n,m;
    int t[501][501][3];
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,2,coins);
    }
};
