class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // using the extra space;
        //     vector<int> result(m+n);

        //     int i = 0,j = 0;
        //     int k = 0;
        //     while(i < m && j < n){
        //         if(nums1[i] < nums2[j]){
        //             result[k] = nums1[i];
        //             i++;
        //         }else{
        //             result[k] = nums2[j];
        //             j++;
        //         }
        //         k++;
        //     }

        //     while(i < m){
        //         result[k] = nums1[i];
        //         i++;
        //         k++;
        //     }

        //     while(j < n){
        //         result[k] = nums2[j];
        //         j++;
        //         k++;
        //     }

        //     for(int i=0;i<m+n;i++){
        //         nums1[i] = result[i];
        //     }

        //    --------------------------------------------------------------------------------------------------
        //    using two pointers to fill the nums1 array from the last position
        //    , we will compare the last values of both nums1 and nums2 and put
        //    the value that is greater and decrease the pointer of that array

        int l1 = m - 1;
        int l2 = n - 1;
        int lastIdx = m + n - 1;

        while (l2 >= 0) {
            if(l1 >= 0 && nums1[l1] > nums2[l2]){
                nums1[lastIdx] = nums1[l1];
                l1--;
            }
            else{
                nums1[lastIdx] = nums2[l2];
                l2--;
            }
            lastIdx--;
        }
    }
};