class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st = {brokenLetters.begin(), brokenLetters.end()};
        int result = 0;
        bool broken = false;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                if (!broken)
                    result += 1;
                broken = false;
            } else {
                if (st.find(text[i]) != st.end())
                    broken = true;
            }
        }

        // ✅ Check last word after loop ends
        if (!broken)
            result++;

        return result;
    }
};