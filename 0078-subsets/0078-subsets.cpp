class Solution {
public:

    void solve(vector<int> &output,vector<int> &input,int i,vector<vector<int>> &ans)
    {
        if(i == input.size())
        {
            ans.push_back(output);
            return;
        }

        //not selecting the first element
        solve(output,input,i+1,ans);

        //selecting the first element
        output.push_back(input[i]);
        solve(output,input,i+1,ans);

       output.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& input) {
        vector<vector<int>> ans;

        vector<int> output;
        int i = 0;
        solve(output,input,i,ans);

        return ans;
    }
};