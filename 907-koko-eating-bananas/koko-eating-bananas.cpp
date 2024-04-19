class Solution {
public:
bool ok(vector<int> &piles, long long  mid, int h){
    long long  houres = 0;
    for(auto i : piles){
        houres += ( (i / mid) + (i % mid == 0 ? 0 : 1) );
    }
    return houres <= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
    long long  l = 1, r = 1e18, ans = -1;
     while(r >= l){
        long long  mid =  ( l + r ) / 2 ;
        int sum = 0;
        if(ok(piles,mid,h)){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
     }
     return ans;   
    }
};