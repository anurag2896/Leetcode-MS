class Trie {
    vector<Trie*> links;
    bool isEnd = false;

public:
    Trie() {
        links.resize(26, NULL);
    }

public:
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
};

class WordDictionary {
    Trie* root;

public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->checkChar(word[i])) {
                node->putChar(word[i], new Trie());
            }
            node = node->getChar(word[i]);
        }
        node->setEnd();
    }

    bool searchHelper(string word, int index, Trie* node) {
        if(index==word.size())
            return node->isEnding();
        
        if(word[index]=='.') {
            for(int i=0; i<26; i++) {
                if(node->checkChar('a'+i)) {
                    if(searchHelper(word, index+1, node->getChar('a'+i)))
                        return true;
                }
            }
            return false;
        } else {
            if(!node->checkChar(word[index])) {
                return false;
            }
            return searchHelper(word, index+1, node->getChar(word[index]));
        }
        // return false;
    }
    
    bool search(string word) {
        Trie* node = root;
        return searchHelper(word, 0, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
