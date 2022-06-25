class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum=0;
        for(auto v:target) {
            pq.push(v);
            sum+=v;
        }
        
        int largest;
        while(true) {
            largest=pq.top();
            sum -= largest;
            if(largest==1 || sum==1)
                return true;
            if(sum==0 || largest%sum==0 || largest<=sum)
                return false;
            largest=largest%sum;
            pq.pop();
            sum+=largest;
            pq.push(largest);
        }
        return true;
    }
};