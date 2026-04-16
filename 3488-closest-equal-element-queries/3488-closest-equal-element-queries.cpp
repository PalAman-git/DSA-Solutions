class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        vector<int> minDist(n, -1);

        // precompute group indices for each value
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& it : mp) {
            vector<int>& indices = it.second;
            int k = indices.size();

            // if only 1 incide then return -1
            if (k == 1)
                continue;

            for (int j = 0; j < k; j++) {
                int curr = indices[j];

                // circular neighbour
                int prev = indices[(j - 1 + k) % k];
                int next = indices[(j + 1) % k];

                // because it is circular array:
                // curr = 0 , prev = 5 , the actual distance would be abs(0-5) =
                // 5,but we need circular distance so
                //  we do n=6 , then n-d1 => 6 - 5 => 1, which is the circular
                //  distance;
                int d1 = abs(curr - prev);
                d1 = min(d1, n - d1);

                int d2 = abs(curr - next);
                d2 = min(d2, n - d2);

                minDist[curr] = min(d1, d2);
            }
        }

        vector<int> answer;
        for (int q : queries) {
            answer.push_back(minDist[q]);
        }

        return answer;
    }
};