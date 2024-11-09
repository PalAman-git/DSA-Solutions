class Solution {
public:
    long long minEnd(int n, int x) {
        long long last_number = x;

        for(int i=1;i<n;i++)
        {
            last_number = x | last_number + 1;
        }

        return last_number;
    }
};