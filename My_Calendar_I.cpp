// https://leetcode.com/problems/my-calendar-i/?envType=daily-question&envId=2024-09-26
class MyCalendar {
public:
    vector<pair<int,int>> v1;
    MyCalendar() {
        v1.clear();
    }
    
    bool book(int start, int end) {
        for(auto& ele: v1) {
            if(start < ele.second && ele.first < end) {
                return false;
            }
        }
        v1.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
