class Solution {
public:

    void solve(vector<int> output,vector<int> input,vector<vector<int>> &ans)
    {
        if(input.size() == 0)
        {
            ans.push_back(output);
            return;
        }

        //first element of the input vector
        int firstElem = input[0];
        input.erase(input.begin());//removing the first element as it is processed

        //not selecting the first element
        solve(output,input,ans);

        //selecting the first element
        output.push_back(firstElem);
        solve(output,input,ans);

        return;   
    }

    vector<vector<int>> subsets(vector<int>& input) {
        vector<vector<int>> ans;

        vector<int> output;
        solve(output,input,ans);

        return ans;
    }
};