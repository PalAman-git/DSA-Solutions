class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0;i<n-1;i++){//no. of time the process will continue n-1 times

            for(int j=0;j<n-1-i;j++){// in each iteration just adding nums[j] , nums[j+1] and mod with 10 to get the last digit and storing at nums[j]

                nums[j] = (nums[j] + nums[j+1]) % 10;
            }
        }

        return nums[0];
    }
};