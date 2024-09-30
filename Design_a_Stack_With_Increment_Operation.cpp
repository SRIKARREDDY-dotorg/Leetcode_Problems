// https://leetcode.com/problems/design-a-stack-with-increment-operation/?envType=daily-question&envId=2024-09-30
class CustomStack {
    vector<int> v;
    int size;
public:
    CustomStack(int maxSize) {
        size = maxSize;
        v.clear();
    }
    
    void push(int x) {
        if(size == (int)v.size()) {
            return;
        }
        v.push_back(x);
    }
    
    int pop() {
        if(v.size()>0) {
            int temp = v.back();
            v.pop_back();
            return temp;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k && i < v.size(); i ++) {
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
