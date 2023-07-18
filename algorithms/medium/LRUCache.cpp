class LRUCache {
private:
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> pairs;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (pairs.count(key)) {
            auto iter = pairs.at(key);
            auto pair = *iter;
            dll.erase(iter);
            dll.push_front(pair);
            pairs.at(key) = dll.begin();
            return pair.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (pairs.count(key) > 0) {
            dll.erase(pairs.at(key));
            dll.push_front({ key, value });
            pairs.at(key) = dll.begin();
            return;
        }
        if (dll.size() == capacity) {
            pairs.erase(dll.back().first);
            dll.pop_back();
        }
        dll.push_front({ key, value });
        pairs.insert({ key, dll.begin() });
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
