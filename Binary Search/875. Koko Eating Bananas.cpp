class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            long long totalHours=0;
            int mid=low+(high-low)/2;
            for(int &pile:piles){
                totalHours+=ceil((double)pile/(double)mid);
            }
            if(totalHours<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
