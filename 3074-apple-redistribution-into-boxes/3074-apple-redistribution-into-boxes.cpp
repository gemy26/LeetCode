class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = 0, cap = 0, boxesCount= 0, ans = 1;
        for(auto i : apple) apples += i;
        sort(capacity.begin(), capacity.end(), std::greater<>());
        for(auto i : capacity){
            cap += i;
            boxesCount ++;
            if(cap >= apples){
                ans = boxesCount;
                break;
            }
        }
        return ans;
    }
};