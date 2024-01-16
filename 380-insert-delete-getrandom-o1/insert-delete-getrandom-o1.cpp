class RandomizedSet {
public:
    unordered_map<int, int> s;
    RandomizedSet() {}

    bool insert(int val) {
        if (s.find(val) == s.end()) {
            s[val]++;
            return true;
        }

        return false;
    }

    bool remove(int val) {
        if (s.find(val) != s.end()) {
            s.erase(val);
            return true;
        }

        return false;
    }

    int getRandom() {
        if (s.size() == 0)
            return false;
        auto  item = s.begin();
        int random_index = rand() % s.size();
         advance(item, random_index);
         return item->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */