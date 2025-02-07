class Solution {
public:
bool isPossible(long long givenTime, vector<int>& time, int totalTrips){
    long long actualTrips=0;
    for(int &t:time){
        actualTrips+=givenTime/t;
    }
    return actualTrips>=totalTrips;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1,h=(long long)*min_element(begin(time),end(time))*totalTrips;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(isPossible(mid,time,totalTrips)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
