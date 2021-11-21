class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        capacity = k + 1;
        front = 0;
        rear = 0;
        items.assign(capacity, 0);
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        items[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        items[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return items[front];
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return items[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return ((rear + 1) % capacity) == front;
    }

private: 
     int capacity;
     int front;
     int rear;
     vector<int> items;
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