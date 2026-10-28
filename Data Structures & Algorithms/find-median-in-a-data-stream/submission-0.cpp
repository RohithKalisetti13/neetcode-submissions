class MedianFinder {
    priority_queue<int> left; //smaller half max heap
    priority_queue<int, vector<int>, greater<int>> right; //larger half min heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(left.empty() || num <= left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
        if(left.size()>right.size()+1){ //odd size
            right.push(left.top());
            left.pop();
        }
        if(right.size()>left.size()){ //even size
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){ //even size
            double median = ((long long)left.top()+right.top())/2.0;
            return median;
        }
        else{
            return left.top(); //odd size
        }
    }
};
