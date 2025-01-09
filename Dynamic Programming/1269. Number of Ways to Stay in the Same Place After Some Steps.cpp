class Solution {
    private:
    int solve(int i,int steps){
        if(i>=n || i<0) return 0;
        if(steps==0){
            return i==0;
        }
        if(t[i][steps]!=-1){
            return t[i][steps];
        }
        int p1=solve(i+1,steps-1);
        p1=(p1+solve(i,steps-1))%MOD;
        p1=(p1+solve(i-1,steps-1))%MOD;
        return t[i][steps]=p1%MOD;
    }
public:
    int n;
    int t[501][501];
    const int MOD=1e9+7;
    int numWays(int steps, int arrLen) {
        n=min(arrLen,steps);
        memset(t,-1,sizeof(t));
        return solve(0,steps);
    }
};
