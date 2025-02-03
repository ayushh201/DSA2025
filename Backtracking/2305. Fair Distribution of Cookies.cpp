class Solution {
    private:
    void solve(int idx,vector<int>& cookies,vector<int>& children,int k){
        if(idx>=n){
            int unfairness=*max_element(begin(children),end(children));
            minResult=min(minResult,unfairness);
            return;
        }
        int cookie=cookies[idx];
        for(int i=0;i<k;i++){
            children[i]+=cookie;
            solve(idx+1,cookies,children,k);
            children[i]-=cookie;
        }
    }
public:
    int n;
    int minResult=INT_MAX;
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        vector<int> children(k,0);
        solve(0,cookies,children,k);
        return minResult;
    }
};
