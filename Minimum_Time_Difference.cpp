// https://leetcode.com/problems/minimum-time-difference/?envType=daily-question&envId=2024-09-16
class Solution {
public:
    int calculateMins(string& time1, string& time2) {
        int hour1 = stoi(time1.substr(0, 2));
        int min1 = stoi(time1.substr(3, 2));
        int hour2 = stoi(time2.substr(0, 2));
        int min2 = stoi(time2.substr(3, 2));
        
        int totalMins = 0;
        while(min1 != min2) {
            if(min1+1 == 60) hour1 = (hour1+1)%24;
            min1 = (min1+1)%60;
            totalMins++;
        }

        if(hour1 == hour2) return totalMins;
        

        while(hour1 != hour2) {
            hour1 = (hour1+1)%24;
            totalMins += 60;
        }
        return totalMins;
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int minTime = INT_MAX;
        int n = timePoints.size();
        for(int i = 1; i < timePoints.size(); i ++) {
            if(timePoints[i-1].substr(0, 2) == timePoints[i].substr(0,2)) {
                minTime = min(minTime, calculateMins(timePoints[i-1], timePoints[i]));
            } else
            minTime = min(minTime, 
                      min(calculateMins(timePoints[i-1], timePoints[i]), calculateMins(timePoints[i], timePoints[i-1])));
        }
        if(timePoints[n-1].substr(0, 2) == timePoints[0].substr(0,2)) {
                minTime = min(minTime, calculateMins(timePoints[n-1], timePoints[0]));
            } else
            minTime = min(minTime, 
                      min(calculateMins(timePoints[n-1], timePoints[0]), calculateMins(timePoints[0], timePoints[n-1])));
        return minTime;
    }
};


// Other way
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> mins(n);

        for(int i = 0; i < timePoints.size(); i ++) {
            string time = timePoints[i];
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3));
            mins[i] = h*60 + m;
        }

        sort(mins.begin(), mins.end());

        int ans = INT_MAX;
        for(int i = 0; i < mins.size() - 1; i ++) {
            ans = min(ans, mins[i+1] - mins[i]);
        }

        return min(ans, 24*60 - mins[n-1] + mins[0]);
    }
};
