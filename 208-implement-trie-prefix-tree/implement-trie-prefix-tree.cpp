class Trie {

    vector<Trie*> links;
    bool isEnd;

public:
    Trie() {
        links.resize(26, NULL);
        isEnd = false;
    }

    bool checkChar(char c) {
        return links[c-'a']!=NULL;
    }

    void putChar(char c, Trie* node) {
        links[c-'a'] = node;
    }

    Trie* getChar(char c) {
        return links[c-'a'];
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEnding() {
        return isEnd;
    }

    
    void insert(string word) {
        Trie* node = this;
        for(int i=0; i<word.size(); i++) {
            if(!node->checkChar(word[i])) {
                node->putChar(word[i], new Trie());
            }
            node = node->getChar(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Trie* node = this;
        for(int i=0; i<word.size(); i++) {
            if(!node->checkChar(word[i])) {
                return false;
            }
            node = node->getChar(word[i]);
        }
        return node->isEnding();
    }
    
    bool startsWith(string word) {
        Trie* node = this;
        for(int i=0; i<word.size(); i++) {
            if(!node->checkChar(word[i])) {
                return false;
            }
            node = node->getChar(word[i]);
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