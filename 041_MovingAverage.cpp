class MovingAverage {
public:
    /** Initialize your data structure here. */
    //思路：用队列来实现，队列的长度为size，每次加入新元素时，判断队列的长度是否超过size，如果超过，则弹出队列头部元素
    //计算队列中所有元素的和，除以队列长度，即为平均值
    queue<int> q; //队列
    int size; //队列的长度
    double sum; //队列中所有元素的和
    MovingAverage(int size) {
        //思路：用队列来实现，队列的长度为size，每次加入新元素时，判断队列的长度是否超过size，如果超过，则弹出队列头部元素
        //计算队列中所有元素的和，除以队列长度，即为平均值
        this->size=size;
        sum=0;
    }

    double next(int val) {
        //思路：用队列来实现，队列的长度为size，每次加入新元素时，判断队列的长度是否超过size，如果超过，则弹出队列头部元素
        //计算队列中所有元素的和，除以队列长度，即为平均值
        if(q.size()==size){
            sum-=q.front();
            q.pop();
        }
        q.push(val);
        sum+=val;
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */