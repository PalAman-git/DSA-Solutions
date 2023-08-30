class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        /*
            1.We start from the right side,if current element is <= then continue;
            2.If not then we need to break the current element in smaller parts such that all parts are
            <= current_max seen
            3.while breaking the element we also have to maximize the minimum number obtained during the
            breaking of element.
            4.In case of breaking [3,9,3] the optimal way to break 9 is 3 3 3.
            5.In case of breaking [3,7,6] the optimal way to break 7 is 3,4 not 6,1 or 2,5
        */
        int n = nums.size();
        long long int ans = 0;
        int current_min = nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] > current_min)
            {
                //** IMPORTANT ceil expects double,typecasting is important
                long long parts = ceil(nums[i]/(double)current_min);//in how many parts the number got
                //divided

                //steps required is always number of divided parts - 1;
                ans += parts -1;

                current_min = (current_min,nums[i] / parts);
            }
            else
            {
                current_min = nums[i];
            }
        }
        return ans;
        //time = O(n) and space = O(1);
    }
};