class RecentCounter {
public:
    queue<int> q; //队列
    RecentCounter() {
        //思路：保留最近3000个ping的时间点，每次ping时，将时间点压入队列中，然后判断队列头部元素是否在t-3000的范围内
        //如果不在，则弹出队列头部元素，直到队列头部元素在t-3000的范围内
    }

    int ping(int t) {
        q.push(t);//将时间点压入队列中
        while(q.front()<t-3000){
            //判断队列头部元素是否在t-3000的范围内，如果不在，则弹出队列头部元素，直到队列头部元素在t-3000的范围内
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */