class MedianFinder {

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // always insert into left size heap
        maxHeap.push(num);
        while(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }

        while(maxHeap.size() > minHeap.size() + 1) {
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }

        while(minHeap.size() > maxHeap.size() + 1) {
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
    }
    
    double findMedian() {
        if(minHeap.size() > maxHeap.size())
            return minHeap.top();
        else if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else 
            return ((minHeap.top() + maxHeap.top())/(2.0));
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */