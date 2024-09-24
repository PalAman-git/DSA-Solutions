class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //here we have to notice that we are told that the numbers in the array would always be [1,n]
        //ans also the size of the array will always be n+1;
        //that means that every number in the array would be a valid index so 
        //we could just traverse whole array and for each element arr[i] we would go to that index and make
        //the number at the index -ve; if we again reach at a element which is already -ve then we would return
        //arr[i];

        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int index = abs(nums[i]);
            if(nums[index] < 0){
                return abs(nums[i]);
            }

            nums[index] = -nums[index];
        }

        return 0;
        
    }
};