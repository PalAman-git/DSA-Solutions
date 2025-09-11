class Solution {
public:
    bool isVowel(char c) {
        char ch = tolower(c);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string sortVowels(string s) {
        vector<char> vowels;
        
        // Step 1: collect vowels
        for (char c : s) {
            if (isVowel(c)) vowels.push_back(c);
        }
        
        // Step 2: sort vowels
        sort(vowels.begin(), vowels.end());
        
        // Step 3: replace vowels in original string
        int idx = 0;
        for (char &c : s) {
            if (isVowel(c)) {
                c = vowels[idx++];
            }
        }
        
        return s;
    }
};
