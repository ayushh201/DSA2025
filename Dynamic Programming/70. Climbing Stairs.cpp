class Solution {
 public:
  int climbStairs(int n) {
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
  }
};


class Solution {
    private:
    int solve(int n){
        if(n<0) return 0;
        if(n==0) return 1;
        if(t[n]!=-1) return t[n];
        int oneStep=solve(n-1);
        int twoStep=solve(n-2);
        return t[n]=oneStep+twoStep;
    }
 public:
  int t[46];
  int climbStairs(int n) {
    memset(t,-1,sizeof(t));
    return solve(n);
  }
};
