//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        int first=0, sec=0;
        vector<int> ans;
        
        while(first<n && sec<m) {
            if(arr1[first]<arr2[sec]) {
                ans.push_back(arr1[first++]);
                
                while(first<n && arr1[first]==arr1[first-1])
                    first++;
                    
            } else if(arr1[first]>arr2[sec]){
                ans.push_back(arr2[sec++]);
                
                while(sec<m && arr2[sec]==arr2[sec-1])
                    sec++;
                    
            } else {
                ans.push_back(arr2[sec++]);
                first++;
                
                while(first<n && arr1[first]==arr1[first-1])
                    first++;
                
                while(sec<m && arr2[sec]==arr2[sec-1])
                    sec++;
            }
        }
        
        while(first<n) {
            ans.push_back(arr1[first++]);
            while(first<n && arr1[first]==arr1[first-1])
                    first++;
                    
        }
        
        while(sec<m) {
            ans.push_back(arr2[sec++]);
            while(sec<m && arr2[sec]==arr2[sec-1])
                    sec++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends