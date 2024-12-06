class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0;
        int sum = 0;
        unordered_set<int> ban;

        for(int i=0;i<banned.size();i++){
            ban.insert(banned[i]);
        }

        for (int i = 1; i <= n; i++) {
            if ( ban.find(i) == ban.end()) {
                if (sum + i <= maxSum) {
                    sum += i;
                    count++;
                }
            }
        }
        return count;
    }
};