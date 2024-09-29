class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,pair<int,int>> mp;
        int n = s.length();
        int k = p.length();

        for(int i=0;i<p.size();i++)
        {
            mp[p[i]].first++;
            mp[p[i]].second = 0;
        }

        int i=0,j=0;
        vector<int> result;
        
        while(j < n)
        {
            mp[s[j]].second++;

            if(j-i+1 < k) j++;

            else if(j-i+1 == k){
                //check for the valid anagram
                int matched=0;
                for(auto it:mp)
                {
                   if(it.second.first == it.second.second) matched++;
                }

                if(matched == mp.size()) result.push_back(i);

                mp[s[i]].second--;
                i++;
                j++;
            }
        }
        return result;
    }
};