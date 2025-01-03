class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        //eliminating edge conditions
        //like low shifting by 1 towards right and high back by 1
        if(n==1) return arr[0];
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];
        //low->low+1 and high=high-1
        int low=1,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
            else{
                if((mid%2==0 && arr[mid]==arr[mid+1])||(mid%2==1 && arr[mid]==arr[mid-1])){
                    //eliminate left->search in right
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
