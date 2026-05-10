class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        vector<int> dp(n,false);

        dp[0] = true;
        int reachable = 0;

        for(int i=1;i<n;i++){
            //include the incoming position
            if(i-minJump >= 0 && dp[i-minJump]){
                reachable++;
            }

            //exclude the outgoing position
            if(i-maxJump-1 >= 0 && dp[i-maxJump-1]){
                reachable--;
            }

            dp[i] = reachable > 0 && s[i] == '0';
        }

        return dp[n-1];
    }
};