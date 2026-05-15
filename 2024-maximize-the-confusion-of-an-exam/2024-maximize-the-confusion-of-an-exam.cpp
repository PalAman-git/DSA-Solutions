class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int ans = 0;

        // calculating longest substring with T as base char
        int i = 0, j = 0;
        int diff = 0;
        while (j < n) {
            if (answerKey[j] == 'F')
                diff++;

            while (diff > k) {
                if (answerKey[i] == 'F')
                    diff--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        // calculating longest substring with F as base char
        i = 0, j = 0;
        diff = 0;
        while (j < n) {
            if (answerKey[j] == 'T')
                diff++;

            while (diff > k) {
                if (answerKey[i] == 'T')
                    diff--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};