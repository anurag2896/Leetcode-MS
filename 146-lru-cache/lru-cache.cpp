class LRUCache {

    int size;
    list<pair<int, int>> dll;   //key, val
    unordered_map<int, list<pair<int, int>>::iterator> m;   //key, iterator

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto found = m.find(key);
        if(found==m.end())
            return -1;
        
        dll.splice(dll.begin(), dll, found->second);
        m[key] = dll.begin();
        return found->second->second;
    }
    
    void put(int key, int value) {
        auto found = m.find(key);
        if(found!=m.end()) {
            found->second->second = value;
            dll.splice(dll.begin(), dll, found->second);
            m[key] = dll.begin();
            return;
        }

        if(dll.size()==size) {
            auto keyToDel = dll.back().first;
            m.erase(keyToDel);
            dll.pop_back();
        }

        dll.push_front({key, value});
        m[key] = dll.begin();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */