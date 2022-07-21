class Solution {
public:
    string intToRoman(int num) {
        vector<int> val = {1,4,5,9,10,40,50,90,100,400,500,900,1000};   //13 size
        vector<string> ch = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};   //13 size
        
        string ans="";
        // while(num) {
            for(int i=val.size()-1; i>=0; i--) {
                while(num>=val[i]) {
                    // cout<<"val->"<<val[i]<<" ";
                    ans+=ch[i];
                    num-=val[i];
                    // cout<<"num->"<<num<<endl;
                }
            }
        // }
        
        return ans;
    }
};