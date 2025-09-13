class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowelFreq, consonantFreq;
        int maxVowelFreq = 0, maxConsonantFreq = 0;
        string vowels = "aeiou";

        for (char ch : s) {
            if (vowels.find(ch) != string::npos) {
                vowelFreq[ch]++;
                maxVowelFreq = max(maxVowelFreq, vowelFreq[ch]);
            } else {
                consonantFreq[ch]++;
                maxConsonantFreq = max(maxConsonantFreq, consonantFreq[ch]);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};