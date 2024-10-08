class MedianFinder {

    priority_queue<int> maxHeap;    //store left
    priority_queue<int, vector<int>, greater<int>> minHeap;    //store right


public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        while((!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top())) {
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }

        if(maxHeap.size() > minHeap.size() + 1) {
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }

        if(minHeap.size() > maxHeap.size() + 1) {
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return (double)(minHeap.top() + maxHeap.top())/2;
        
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();

        return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */