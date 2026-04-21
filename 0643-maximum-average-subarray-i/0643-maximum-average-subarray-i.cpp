class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double kElementSum=0;


        //first window
        for(int i=0;i<k;i++){
            kElementSum += nums[i];
        }

        double maxSum = kElementSum;

        //rest of the elements
        for(int i=k;i<n;i++){
            kElementSum += nums[i] - nums[i-k];
            maxSum = max(maxSum,kElementSum);
        }

        return maxSum/k; 
    }
};