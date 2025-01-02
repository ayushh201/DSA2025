class Solution {
    int t[100001];
    const int MOD=1e9+7;
    private:
    int solve(int start,string &s,int &k){
        if(start>=s.length()){
            return 1;
        }
        if(s[start]=='0') return 0;
        if(t[start]!=-1){
            return t[start];
        }
        long long ans=0;
        long long num=0;
        for(int end=start;end<s.length();end++){
            num=(num*10)+(s[end]-'0');
            if(num>k){
                break;
            }
            ans+=(solve(end+1,s,k)%MOD)%MOD;
        }
        return t[start]=ans%MOD;
    }
public:
    int numberOfArrays(string s, int k) {
        memset(t,-1,sizeof(t));
        return solve(0,s,k);
    }
};
