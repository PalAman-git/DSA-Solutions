class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int size = arr.size();
        int low = 0;
        int high = size - 1;

        if(size == 1) return 0;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            //if it is not end element 
            if(mid > 0 && mid < size - 1)
            {
                if(arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
                {
                    return mid;
                }
                else if(arr[mid - 1] > arr[mid])
                {
                    high = mid - 1;
                }
                else if(arr[mid + 1] > arr[mid])
                {
                    low = mid + 1;
                }
            }
            //if it is starting element
            else if(mid == 0)
            {
                if(arr[mid + 1] < arr[mid])
                {
                    return mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            //if it is ending element
            else if(mid == size - 1)
            {
                if(arr[mid - 1] < arr[mid])
                {
                    return mid;  
                }
                else 
                {
                    high = mid - 1;
                }
            }
        }
        return 0;
    }
};