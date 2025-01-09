class Solution {
    private:
    int solve(vector<int>& cost, vector<int>& time,int i,int walls){
        if(walls<=0){
            return 0; //no cost now for the walls all completed
        }
        if(i>=cost.size()){
            return 1e9;
        }
        if(t[i][walls]!=-1) return t[i][walls];
        int paint=cost[i]+solve(cost,time,i+1,walls-1-time[i]);
        int no_paint=solve(cost,time,i+1,walls);
        return t[i][walls]=min(paint,no_paint);
    }
public:
int t[501][501];
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        memset(t,-1,sizeof(t));
        return solve(cost,time,0,n);
    }
};
