// https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2024-07-13
typedef pair<int,pair<int,char>> RobotPair;

class Solution {
public:

    static bool comp(const RobotPair& p1, const RobotPair& p2) {
        return p1.first < p2.first;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // In collision, less health robot is removed and other will reduce by 1, 
        // if same both removed.
        // 
        vector<RobotPair> robotPairs;
        int n = positions.size();
        unordered_map<int, int> positionMap;
        for(int i = 0; i < n; i ++) {
            positionMap[positions[i]] = i;
            robotPairs.push_back({positions[i], {healths[i], directions[i]}});
        }
        sort(robotPairs.begin(), robotPairs.end(), comp);
        
        stack<RobotPair> robotPairStack;

        for(int i = 0; i < n; i ++) {
            if(robotPairStack.empty()) {
                robotPairStack.push(robotPairs[i]);
            } else {
                RobotPair robotPair = robotPairStack.top();
                bool isCurrElementPushable = true;
                while(!robotPairStack.empty() && robotPair.second.second == 'R' && robotPairs[i].second.second == 'L') {
                    if(robotPair.second.first > robotPairs[i].second.first) {
                        robotPair.second.first = robotPair.second.first - 1;
                        robotPairStack.pop();
                        robotPairStack.push(robotPair);
                        isCurrElementPushable = false;
                        break;
                    } else if(robotPair.second.first < robotPairs[i].second.first) {
                        robotPairs[i].second.first = robotPairs[i].second.first - 1;
                        isCurrElementPushable = true;
                        robotPairStack.pop();
                        if(!robotPairStack.empty()) robotPair = robotPairStack.top();
                    } else {
                        isCurrElementPushable = false;
                        robotPairStack.pop();
                        break;
                    }
                }
                if(isCurrElementPushable) robotPairStack.push(robotPairs[i]);
            }
        }
        vector<int> result(n, 0);
        while(!robotPairStack.empty()) {
            // cout<<robotPairStack.top().second.first<<" ";
            result[positionMap[robotPairStack.top().first]] = robotPairStack.top().second.first;
            robotPairStack.pop();
        }
        vector<int> ultimateResult;
        for(auto& ele: result) {
            if(ele) {
                ultimateResult.push_back(ele);
            }
        }
        return ultimateResult;
    }
};
