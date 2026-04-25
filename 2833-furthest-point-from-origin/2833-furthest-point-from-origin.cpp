class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int R = 0, L = 0, free = 0;
        int n = moves.size();
        for(auto i : moves){
            R += i == 'R';
            L += i == 'L';
            free += i == '_';
        }
        if(R > L){
            swap(R, L);
        }
        int diff = L - R;
        return free + diff;
    }
};