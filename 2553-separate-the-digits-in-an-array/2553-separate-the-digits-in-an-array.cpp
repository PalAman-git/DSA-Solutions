class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;

        for(int num: nums){

            while(num > 0){
                int lastDigit = num % 10;
                num /= 10;

                st.push(lastDigit);
            }

            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};