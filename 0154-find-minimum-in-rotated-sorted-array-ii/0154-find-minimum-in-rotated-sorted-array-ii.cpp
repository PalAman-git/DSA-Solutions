class Solution {
public:
    int findMin(vector<int>& arr) {
        int s = 0;
        int e = arr.size() -1;
        int ans = INT_MAX;

        //left side ke duplicate elements ko skip kr rhe hain
        while(s < e && arr[s] == arr[s+1])
        {
            s++;
        }

        while(e > s && arr[e] == arr[e-1])
        {
            e--;
        }

        while(s <= e)
        {
            int mid = s + (e - s)/2;

            //left part sorted
            if(arr[s] <= arr[mid])
            {
                ans = min(ans,arr[s]);
                s = mid + 1;
            }
            //right part sorted
            else {
                ans = min(ans,arr[mid]);
                e = mid -1;
            }
        }
        return ans;
    }
};