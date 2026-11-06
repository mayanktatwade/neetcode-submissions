
class MyHashSet {
public:
    vector<int> v;

    MyHashSet() {}

    void add(int key) {
        int idx = lower_bound(v.begin(), v.end(), key) - v.begin();

        if(idx == v.size() || v[idx] != key) {
            v.insert(v.begin() + idx, key);
        }
    }

    void remove(int key) {
        int idx = lower_bound(v.begin(), v.end(), key) - v.begin();

        if(idx < v.size() && v[idx] == key) {
            v.erase(v.begin() + idx);
        }
    }

    bool contains(int key) {
        int idx = lower_bound(v.begin(), v.end(), key) - v.begin();

        return idx < v.size() && v[idx] == key;
    }
};
