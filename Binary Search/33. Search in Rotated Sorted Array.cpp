class Solution {
    private:
    int findPivot(vector<int>& nums){
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return r;
    }
    int binarySearch(int l,int r,vector<int>& nums, int target){
        int idx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                idx=mid;
                break;
            }
            if(nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return idx;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=findPivot(nums);
        int leftBinarySearchIndex=binarySearch(0,pivot-1,nums,target);
        if(leftBinarySearchIndex!=-1) return leftBinarySearchIndex;
        int rightBinarySearchIndex=binarySearch(pivot,n-1,nums,target);
        return rightBinarySearchIndex;
    }
};
