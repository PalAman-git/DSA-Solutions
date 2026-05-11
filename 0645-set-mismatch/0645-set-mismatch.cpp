class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        vector<int> track(n+1,0);
        for(int i=0;i<n;i++){
            track[i+1] = 1;
        }

        for(int i=0;i<n;i++){
            track[nums[i]]--;
        }

        int duplicate = -1;
        int missing = 1;

        for(int i=1;i<n+1;i++){
            if(track[i] == -1 ) missing = i;
            if(track[i] == 1) duplicate = i;
        }

        return {missing,duplicate};
    }
};