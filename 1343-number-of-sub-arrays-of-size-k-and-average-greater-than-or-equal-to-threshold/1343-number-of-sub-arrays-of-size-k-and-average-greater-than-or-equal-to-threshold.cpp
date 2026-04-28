class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();

        int i=0,j=0;
        int ans = 0;
        int window_sum=0;

        while(j<n){
            //do calculation
            window_sum += arr[j];

            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                //check if the average is greater or equal to threshold
                int avg = window_sum / k; 

                if(avg >= threshold){
                    ans++;
                }

                //remove the ith element from the window
                window_sum -= arr[i];
                i++;
                j++;
            }
        }

        return ans;
    }
};