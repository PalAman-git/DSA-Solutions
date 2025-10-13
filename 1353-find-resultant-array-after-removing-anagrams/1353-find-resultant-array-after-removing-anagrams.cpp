class Solution {
public:
    bool isAnagram(string a,string b){
        if(a.length() != b.length()) return false;

        int count[26] = {0};

        for(char c : a){
            count[c - 'a']++;
        }

        for(char c : b){
            count[c - 'a']--;
        }

        for(int i=0;i<26;i++){
            if(count[i] != 0) return false;
        }
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;

        result.push_back(words[0]);

        for(int i=1;i<words.size();i++){
            if(!isAnagram(words[i],result.back())) result.push_back(words[i]);
        }

        return result;
    }
};