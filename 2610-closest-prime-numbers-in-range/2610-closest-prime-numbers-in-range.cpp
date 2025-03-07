class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right + 1, true);
        for(int p = 2; p * p <= right; p ++){
            if(prime[p] == true){
                for(int j = p * p; j <= right; j += p){
                    prime[j] = false;
                }
            }
        }

        vector <int> primes;
        for(int i = max(2, left); i <= right; i ++){
           //cout << "here\n";
            if(prime[i]){
                //cout << i << endl;
                primes.push_back(i);
            }
        }

        int ans = 1e9;
        int f = -1, s = -1;
        for(int i = 1; i < primes.size(); i ++){
            //cout << primes[i - 1] << " " << primes[i] << endl;
            if(primes[i] - primes[i - 1] < ans){
                ans = primes[i] - primes[i - 1];
                f = primes[i - 1], s = primes[i];
            }
        }

        vector <int> ret = {-1, -1};
        if(ans != 1e9){
            ret = {f, s};
        }
        return ret;
    }
};