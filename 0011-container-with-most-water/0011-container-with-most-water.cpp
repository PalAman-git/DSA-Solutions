class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();

        //first approach ,time = O(n^2) space = O(1);

        // for(int i=0;i<n-1;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         int area = abs(i-j)*min(height[i],height[j]);
        //         maxArea = max(maxArea,area);
        //     }
        // }

        //second approach , time O(n) space O(1);

        //the greedy approach
        int i = 0,j = n-1;

        while(i < j)
        {
            int area = (j-i) * min(height[i],height[j]);
            maxArea = max(area,maxArea);
            if(height[i]>height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return maxArea;
    }
};