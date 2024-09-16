class Solution {
public:
    int timeToMinutes(string time)
    {
        int hourToMinute = stoi(time.substr(0,2))*60;
        int minutes = stoi(time.substr(3,2));

        return hourToMinute + minutes;
    }
    int findMinDifference(vector<string>& timePoints) {
        //sort the time points
        sort(begin(timePoints),end(timePoints));

        timePoints.push_back(timePoints[0]);

        int ans = INT_MAX, n = timePoints.size(),time_one,time_two;

        for(int i=0;i<n-1;i++)
        {
            time_one = timeToMinutes(timePoints[i]);
            time_two = timeToMinutes(timePoints[i+1]);

            ans = min(ans,abs(time_one - time_two));

            ans = min(ans,abs(time_one - (1440+time_two)));
        }
        return ans;
    }   
};