class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream s(s1);
        istringstream w(s2);

        unordered_map<string,int> mp;
        string word;

        while(s >> word)
        {
            mp[word]++;
        }
        while(w >> word)
        {
            mp[word]++;
        }

        vector<string> ans;
        for(auto i: mp)
        {
            if(i.second == 1) ans.push_back(i.first);
        }
        return ans;        
    }
};