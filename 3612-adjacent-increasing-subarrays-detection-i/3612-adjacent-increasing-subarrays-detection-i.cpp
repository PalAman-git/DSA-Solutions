class Solution {
public:
    bool isStrictlyIncreasing(vector<int>& nums,int startIdx,int k){
        for(int i=0;i<k - 1;i++){
            if(nums[startIdx + i] >= nums[startIdx + i+1] )return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0;i <= n - (k*2) ; i++ ){
            if(isStrictlyIncreasing(nums,i,k) && isStrictlyIncreasing(nums,i+k,k)) return true;
        }
        return false;
    }
};