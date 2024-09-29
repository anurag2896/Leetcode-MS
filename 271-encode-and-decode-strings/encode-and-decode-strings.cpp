class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans="";
        for(auto word:strs) {
            int len = word.size();
            ans+=to_string(len) + "#" + word;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.size()) {
            string length = "";
            while(s[i]!='#') {
                length+=s[i];
                i++;
            }

            int len = (stoi)(length);
            i++;

            string w = s.substr(i, len);
            i+=len;
            ans.push_back(w);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));