class kQueues {

  public:
     vector<queue<int>> kq;
    int size;
    
    int maxSize;
  public:
    kQueues(int n, int k) {
        // Initialize your data members
        kq.resize(k);
        size = 0;
        maxSize = n;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        kq[i].push(x);
        size++;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if(!kq[i].empty()) {
            int data = kq[i].front();
            kq[i].pop();
            size--;
            return data;
        }
        
        return -1;
    }

    bool isEmpty(int i) {
        return kq[i].empty();
    }

    bool isFull() {
        return (size == maxSize);
    }
};
