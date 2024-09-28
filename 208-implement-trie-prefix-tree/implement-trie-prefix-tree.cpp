class Trie {
    vector<Trie*> links;
    bool isEnd;

    bool containsChar(char c) {
        return links[c-'a'] != NULL;
    }

    Trie* getNode(char c) {
        return links[c-'a'];
    }

    void putNode(char c, Trie* node) {
        links[c-'a'] = node;
    }

    bool isTerminal(){
        return isEnd;
    }

    void setEnd(){
        isEnd = true;
    }

public:
    Trie() {
        links.resize(26, NULL);
        isEnd = false;
        // Trie* root = this;
    }
    
    void insert(string word) {
        Trie* node = this;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsChar(word[i])) {
                node->putNode(word[i], new Trie());
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Trie* node = this;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsChar(word[i])) {
                return false;
            }
            node = node->getNode(word[i]);
        }
        return node->isTerminal();
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(int i=0; i<prefix.size(); i++) {
            if(!node->containsChar(prefix[i])) {
                return false;
            }
            node = node->getNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */