class Solution {
    private:
    void solve(int idx,int count,int n,vector<int>& resultant,vector<vector<int>>& requests){
        if(idx>=m){
            bool allZero=true;
            for(int &val:resultant){
                if(val!=0){
                    allZero=false;
                    break;
                }
            }
            if(allZero==true){
               maxRequest=max(maxRequest,count); 
            }
            return;
        }
        int from=requests[idx][0];
        int to=requests[idx][1];
        resultant[from]--;
        resultant[to]++;
        solve(idx+1,count+1,n,resultant,requests);
        resultant[from]++;
        resultant[to]--;
        solve(idx+1,count,n,resultant,requests);
    }
public:
    int maxRequest=INT_MIN;
    int m;
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m=requests.size();
        vector<int> resultant(n,0);
        solve(0,0,n,resultant,requests);
        return maxRequest;
    }
};
