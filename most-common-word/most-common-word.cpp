class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        int n=paragraph.size();
        unordered_set<string> s;
        
        for(auto word:banned) {
            // cout<<word<<endl;
            s.insert(word);
        }
        
        // cout<<endl;
        string word="";
        for(int i=0; i<n; i++) {
            while(i<n && ((paragraph[i]>='a' && paragraph[i]<='z') || (paragraph[i]>='A' && paragraph[i]<='Z'))) {
                word+=tolower(paragraph[i++]);
            }
            
            cout<<word;
            if(word!="" && s.find(word)==s.end()) {
                // cout<<" .here"<<word<<endl;
                m[word]++;
            }
            word="";
        }
        
        string ans;
        int count=0;
        for(auto ele:m) {
            cout<<ele.first<<" "<<ele.second<<endl;
            if(ele.second > count) {
                count = max(count, ele.second);
                ans=ele.first;
            }
        }
        
        return ans;
    }
};