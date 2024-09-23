class Solution {
public:
    int solve(int i,string &s,unordered_set<string> &st,int n,unordered_map<int,int> &mp)
    {
        if(i >= n) return 0;//koi bhi extra character nhi milega

        int result = 1 + solve(i+1,s,st,n,mp);

        if(mp.find(i) != mp.end()) return mp[i];

        for(int j=i;j<n;j++)
        {
            string curr = s.substr(i,j-i+1);
            if(st.count(curr) != 0)
            {
                result = min(result,solve(j+1,s,st,n,mp));
            }
        }
        return mp[i] = result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<int,int> mp;//for memoization
        int n = s.length();
        unordered_set<string> st(begin(dictionary),end(dictionary));
        return solve(0,s,st,n,mp);
    }
};