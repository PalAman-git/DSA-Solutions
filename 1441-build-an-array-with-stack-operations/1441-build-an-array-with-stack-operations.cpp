class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j=0;
        vector<string> output;
        for(int i=1;i<=n;i++){
            if(j >= target.size()) break;

            if(i == target[j]) {
                output.push_back("Push");
                j++;
            }

            else {
                output.push_back("Push");
                output.push_back("Pop");
            }
        }
        return output;
    }
};