class Solution {
public:

   void backtrack(string& s, int index, string& current, vector<string>& result) {
    // If we have processed all characters, add the current combination to result
    if (index == s.size()) {
        result.push_back(current);
        return;
    }

    // Process the current character
    char c = s[index];
    
    // If it's a letter, branch into both lowercase and uppercase
    if (isalpha(c)) {
        // Lowercase option
        current.push_back(tolower(c));
        backtrack(s, index + 1, current, result);
        // Backtrack to explore uppercase option
        current.pop_back();
        
        // Uppercase option
        current.push_back(toupper(c));
        backtrack(s, index + 1, current, result);
        // Backtrack
        current.pop_back();
    } else {
        // If it's a digit, just add it to the current combination
        current.push_back(c);
        backtrack(s, index + 1, current, result);
        current.pop_back();
    }
}

vector<string> letterCasePermutation(string s) {
    vector<string> result;
    string current;
    backtrack(s, 0, current, result);
    return result;
}
};