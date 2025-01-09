//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find largest rectangular area possible in a given histogram.
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> s;
        int maxi = 0;
        
        for(int i = 0; i<n ;i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                int element = s.top();
                s.pop();
                
                int nextSmallestElement = i;
                int prevSmallestElement = s.empty() ? -1 : s.top();
                
                maxi = max(maxi, arr[element] * (nextSmallestElement - prevSmallestElement -1));
            }
            s.push(i);
        }
        
        while(!s.empty()){
            int nextSmallestElement = n;
            int element = s.top();
            s.pop();
            int prevSmallestElement = s.empty() ? -1 : s.top();
            
            maxi = max(maxi, arr[element] * (nextSmallestElement - prevSmallestElement - 1));
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends