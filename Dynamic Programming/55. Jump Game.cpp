class Solution {
    private:
    bool solve(vector<int> &nums,int idx){
        int n=nums.size();
        if(idx==n-1){
            return true;
        }
        if(idx>=n){
            return false;
        }
        if(t[idx]!=-1) return t[idx];
        for(int i=1;i<=nums[idx];i++){
            if(solve(nums,idx+i)){
                return t[idx]=true;
            }
        }
        return t[idx]=false;
    }
public:
    int t[10001];   
    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0);
    }
};
