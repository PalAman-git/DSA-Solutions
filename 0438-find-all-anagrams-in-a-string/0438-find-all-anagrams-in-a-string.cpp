class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;
        int n = s.length();
        int k = p.length();

        for(int i=0;i<p.size();i++)
        {
            mp[p[i]]++;
        }
        int count = mp.size();//when this count will be zero that will mean that all the character in same quantity have been found so it is an anagram


        int i=0,j=0;
        vector<int> result;
        
        while(j < n)
        {
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }

            if(j-i+1 < k) j++;

            else if(j-i+1 == k){
                //check for the valid anagram
                if(count == 0) result.push_back(i);

                //removing the calculation for 
                if(mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) count++;
                }

                i++;
                j++;
            }
        }
        return result;
    }
};