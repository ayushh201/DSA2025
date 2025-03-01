class Solution {
    private:
    int solve(int n){
        if(n==1){
            return 1;
        }
        if(t[n]!=-1) return t[n];
        int result=INT_MIN;
        for(int i=1;i<=n-1;i++){
            int product=i*max(n-i,solve(n-i));
            result=max(result,product);
        }
        return t[n]=result;
    }
public:
    int t[59];
    int integerBreak(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};
