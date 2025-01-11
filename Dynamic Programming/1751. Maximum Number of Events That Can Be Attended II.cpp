class Solution {
    private:
    int solve(int i,int k,vector<vector<int>>& events){
        //base case
        if(i>=n || k==0){
            return 0;
        }

        if(dp[i][k]!=-1) return dp[i][k];
        
        int start=events[i][0];
        int end=events[i][1];
        int value=events[i][2];

        int skip=solve(i+1,k,events);
        vector<int> temp={end,INT_MAX,INT_MAX};
        int j=upper_bound(events.begin()+i+1,events.end(),temp)-events.begin(); //binary search
        int take=value+solve(j,k-1,events);

        return dp[i][k]=max(take,skip);
    }
public:
    int n;
    vector<vector<int>> dp;
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        sort(begin(events),end(events));
        return solve(0,k,events); //tc->n+1*k+1*logn
    }
};




class Solution {
    private:
    int solve(int i,int k,vector<vector<int>>& events){
        //base case
        if(i>=n || k==0){
            return 0;
        }

        if(dp[i][k]!=-1) return dp[i][k];
        
        int start=events[i][0];
        int end=events[i][1];
        int value=events[i][2];

        int skip=solve(i+1,k,events);
        int j = i+1;
        for(; j < n; j++) {
            if(events[j][0] > events[i][1])
                break;
        }
        int take=value+solve(j,k-1,events);

        return dp[i][k]=max(take,skip);
    }
public:
    int n;
    vector<vector<int>> dp;
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        sort(begin(events),end(events));
        return solve(0,k,events); //tc->n+1*k+1*n
    }
};
