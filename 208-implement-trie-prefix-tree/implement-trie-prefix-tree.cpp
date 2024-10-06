class Node {
    vector<Node*>links;
    bool isEnd;

public:
    Node() {
        links.resize(26, NULL);
        isEnd = false;
    }

    Node* getNode(char ch) {
        return links[ch-'a'];
    }

    void putNode(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    bool containsNode(char ch) {
        return links[ch-'a']!=NULL;
    }

    bool isEnding() {
        return isEnd;
    }

    void setEnding() {
        isEnd = true;
    }
};

class Trie {

    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int n=word.size();
        for(auto ch:word) {
            if(!node->containsNode(ch)) {
                node->putNode(ch, new Node());
            }
            node = node->getNode(ch);
        }
        node->setEnding();
    }
    
    bool search(string word) {
        Node* node = root;
        int n=word.size();
        for(auto ch:word) {
            if(!node->containsNode(ch)) {
                return false;
            }
            node = node->getNode(ch);
        }
        return node->isEnding();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        int n=prefix.size();
        for(auto ch:prefix) {
            if(!node->containsNode(ch)) {
                return false;
            }
            node = node->getNode(ch);
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