class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(st.find(endWord)==st.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            string word = node.first;
            st.erase(word);
            int currLevel = node.second;

            int nextLevel = currLevel + 1;
            for(int i=0; i<word.size(); i++) {
                char originalChar = word[i];
                for(char c='a'; c<='z'; c++) {
                    word[i] = c;

                    if(st.find(word)!=st.end()) {
                        if(word==endWord)
                            return nextLevel;
                        q.push({word, nextLevel});
                    }
                }
                word[i] = originalChar;
            }
        }

        return 0;
    }
};