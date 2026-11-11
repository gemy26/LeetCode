class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        if (need1 > need2) {
            swap(cost1, cost2);
            swap(need1, need2);
        }
        if (costBoth < cost1 + cost2) {
            int diff = (need2 - need1);
            return (1LL * need1 * costBoth ) + min(1LL * diff * cost2, 1LL * costBoth * diff);
        }
        return (1LL * cost1 * need1) + (1LL * cost2 * need2);
    }
};