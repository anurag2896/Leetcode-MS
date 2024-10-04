class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int size;
    list<pair<int, int>> dll;

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto found = m.find(key);
        if(found==m.end()) {
            return -1;
        }
        dll.splice(dll.begin(), dll, found->second);
        m[key] = dll.begin();
        return found->second->second;
    }
    
    void put(int key, int value) {
        auto found = m.find(key);
        if(found!=m.end()) {
            dll.splice(dll.begin(), dll, found->second);
            m[key] = dll.begin();
            found->second->second = value;
            return;
        }
        if(dll.size() == size) {
            int keyTobeDel = dll.back().first;
            m.erase(keyTobeDel);
            dll.pop_back();
        }

        dll.push_front({key, value});
        m[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */