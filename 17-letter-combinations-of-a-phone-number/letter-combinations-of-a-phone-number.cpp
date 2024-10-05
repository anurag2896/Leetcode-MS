class Solution {

    void helper(vector<string>& ans, unordered_map<char, vector<string>>& m, string temp, string digits, int index) {
        if(index==digits.size()) {
            ans.push_back(temp);
            return;
        }

        auto chars = m[digits[index]];
        for(auto c:chars) {
            helper(ans, m, temp+c, digits, index+1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {


        unordered_map<char, vector<string>> m;
        m['2'] = {"a", "b", "c"};
        m['3'] = {"d", "e", "f"};
        m['4'] = {"g", "h", "i"};
        m['5'] = {"j", "k", "l"};
        m['6'] = {"m", "n", "o"};
        m['7'] = {"p", "q", "r", "s"};
        m['8'] = {"t", "u", "v"};
        m['9'] = {"w", "x", "y", "z"};

        vector<string> ans;
        if(digits=="")
            return ans;
            
        string temp="";
        helper(ans, m, temp, digits, 0);
        return ans;
    }
};