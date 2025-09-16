class Solution {
public:
    int hcf(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    bool non_coprime(int a, int b) { return hcf(a, b) != 1; }

    int lcm_func(int a, int b) { return (a / hcf(a, b)) * b; }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> s; // long long to prevent overflow

        for (int num : nums) {
            long long current = num;

            // merge backward while top and current and non-coprime
            while (!s.empty()) {
                long long g = hcf(s.top(), current);
                if (g == 1)
                    break; // coprime
                current = lcm_func(s.top(), current);
                s.pop();
            }
            s.push(current);
        }

        vector<int> result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};