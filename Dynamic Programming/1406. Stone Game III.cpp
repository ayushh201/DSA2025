class Solution {
    int solve(int i,vector<int>& arr){
        if(i>=n){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int result=INT_MIN;
        result=max(result,arr[i]-solve(i+1,arr));
        if(i+1<n){
            result=max(result,arr[i]+arr[i+1]-solve(i+2,arr));
        }
        if(i+2<n){
            result=max(result,arr[i]+arr[i+1]+arr[i+2]-solve(i+3,arr));
        }
        return t[i]=result;
    }
public:
    int n;
    int t[50001];
    string stoneGameIII(vector<int>& arr) {
        n=arr.size();
        memset(t,-1,sizeof(t));
        int diff=solve(0,arr);
        if(diff>0){
            return "Alice";
        }else if(diff<0){
            return "Bob";
        }
        return "Tie";
    }
};
