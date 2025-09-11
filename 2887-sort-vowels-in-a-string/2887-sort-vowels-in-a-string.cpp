class Solution {
public:
    bool isVowel(char c) {
        char ch = tolower(c);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        } else
            return false;
    }

    string sortVowels(string s) {
        priority_queue<char,vector<char>,greater<char>> min_heap;
        int size = s.length();
        vector<char> result(size);

        for (int i = 0; i < size; i++) {
            result[i] = '&';
        }

        for (int i = 0; i < size; i++) {
            if (isVowel(s[i])) {
                min_heap.push(s[i]);
            } else {
                result[i] = s[i];
            }
        }

        for (int i = 0; i < size; i++) {
            if (result[i] == '&') {
                result[i] = min_heap.top();
                min_heap.pop();
            } else
                continue;
        }

        return string(result.begin(),result.end());
    }
};