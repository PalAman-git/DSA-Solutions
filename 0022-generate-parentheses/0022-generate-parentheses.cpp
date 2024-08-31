class Solution {
public:

    void solve(string output,int open_bracket,int closed_bracket,vector<string> &ans)
    {
        if(open_bracket == 0 && closed_bracket == 0)
        {
            ans.push_back(output);
            return;
        }

        if(open_bracket != 0)
        {
            string op1 = output;
            op1.push_back('(');
            solve(op1,open_bracket-1,closed_bracket,ans);
        }

        if(closed_bracket>open_bracket)
        {
            string op2 = output;
            op2.push_back(')');
            solve(op2,open_bracket,closed_bracket-1,ans);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        int open_bracket = n;
        int closed_bracket = n;

        solve(output,open_bracket,closed_bracket,ans);

        return ans;
    }
};