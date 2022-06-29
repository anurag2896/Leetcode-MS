class Solution {
public:
    
    // static bool order( vector<int>& a, vector<int> const& b) {
    //     return a[0]<b[0] || a[0]==b[0] && a[1]>b[1];
    // }
    
    static bool comp(vector<int>& a, vector<int>& b){ //Comparator function for the logic of sort
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        
        sort(people.begin(), people.end(), comp);
        
        for(auto person:people) {
            int index = person[1];
            ans.insert(ans.begin()+index, person);
        }
        
        return ans;
    }
};