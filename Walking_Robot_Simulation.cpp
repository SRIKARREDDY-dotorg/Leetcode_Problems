// https://leetcode.com/problems/walking-robot-simulation/?envType=daily-question&envId=2024-09-04
class Solution {
public:
    static const int HASH_MULTIPLIER = 60001;
    int hashCoordinates(int x, int y) {
        return x + 60001*y;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
       // begins with north
       // north + right = east
       // east + right = south
       // south + right = west
       // west + right = north
       // ["N", "E", "S", "W"];
       // (+Y, +X, -Y, -X);
       // going forward in circular array => (i + 1) % 4
       // going backward in circular array => (i - 1 + 4) % 4
       // store the x-coord, y-coord
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // unordered_map<int, vector<int>> x_cords;
        // unordered_map<int, vector<int>> y_cords;

        // for(auto& obstacle: obstacles) {
        //     x_cords[obstacle[0]].push_back(obstacle[1]);
        //     y_cords[obstacle[1]].push_back(obstacle[0]);
        // }

        int dirIndex = 0;
        unordered_set<int> obstacleSet;
        for(int i = 0; i < obstacles.size(); i ++) {
            obstacleSet.insert(hashCoordinates(obstacles[i][0], obstacles[i][1]));
        }
        vector<int> currPos = {0, 0};
        int maxDistanceSquared = 0;
        for(int i = 0; i < commands.size(); i ++) {
            if(commands[i] == -1) {
                dirIndex = (dirIndex+1) % 4;
            } else if(commands[i] == -2) {
                dirIndex = (dirIndex+3) % 4;
            } else {
                vector<int> direction = dir[dirIndex];
                for(int step = 0; step < commands[i]; step++) {
                    int nextX = direction[0] + currPos[0];
                    int nextY = direction[1] + currPos[1];
                    if(obstacleSet.contains(hashCoordinates(nextX, nextY))) {
                        break;
                    }
                    currPos[0] = nextX;
                    currPos[1] = nextY;
                }

                maxDistanceSquared = max(maxDistanceSquared, currPos[0]*currPos[0] + currPos[1]*currPos[1]);
            }
        }
        return maxDistanceSquared;
    }
};
