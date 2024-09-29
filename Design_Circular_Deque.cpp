// https://leetcode.com/problems/design-circular-deque/description/?envType=daily-question&envId=2024-09-28
struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class MyCircularDeque {
    int capacity;
    int queueSize;
    Node* head;
    Node* tail;
public:
    MyCircularDeque(int k) {
        capacity = k;
        queueSize = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    bool insertFront(int value) {
        if(queueSize == capacity) return false;
        if(!head) {
            Node* temp = new Node(value);
            head = temp;
            tail = temp;
            queueSize++;
            return true;
        }
        Node* temp = new Node(value);
        temp->next = head;
        head->prev = temp;
        head = temp;
        queueSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(queueSize == capacity) return false;
        if(!tail) {
            Node* temp = new Node(value);
            head = temp;
            tail = temp;
            queueSize++;
            return true;
        }
        Node* temp = new Node(value);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        queueSize++;
        return true;
    }
    
    bool deleteFront() {
        if(queueSize == 0) return false;
        if(head == tail) {
            head = nullptr;
            tail = nullptr;
            queueSize--;
            return true;
        }
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        head->prev = nullptr;
        temp = nullptr;
        queueSize--;
        return true;
    }
    
    bool deleteLast() {
        if(queueSize == 0) return false;
        if(head == tail) {
            head = nullptr;
            tail = nullptr;
            queueSize--;
            return true;
        }
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = nullptr;
        tail->next = nullptr;
        temp = nullptr;
        queueSize--;
        return true;
    }
    
    int getFront() {
        return head ? head->val: -1;
    }
    
    int getRear() {
        return tail ? tail->val: -1;
    }
    
    bool isEmpty() {
        return queueSize==0;
    }
    
    bool isFull() {
        return queueSize==capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
