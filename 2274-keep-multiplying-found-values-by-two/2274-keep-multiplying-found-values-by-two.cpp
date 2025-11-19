class Solution {
public:
    bool search(vector<int>& nums,int original){
        for(auto i: nums){
            if(i == original) return true;
        }
        return false;
    }

    int findFinalValue(vector<int>& nums, int original) {
        
        bool original_present = search(nums,original);

        while(original_present){
            original *= 2;
            original_present = search(nums,original);
        }

        return original;
    }
};