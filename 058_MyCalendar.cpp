
class MyCalendar {
public:
    //请实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内没有其他安排，则可以存储这个新的日程安排。
    //MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end 时间内增加一个日程安排，
    //注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。
    //当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生重复预订。
    //每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致重复预订，
    //返回 true。否则，返回 false 并且不要将该日程安排添加到日历中。
    //请按照以下步骤调用 MyCalendar 类: MyCalendar cal = new MyCalendar();

    MyCalendar() {

    }
    //c++二叉搜索树

    bool book(int start, int end) {
        //思路：二叉搜索树，找到第一个大于等于start的节点，然后判断是否重叠
        //如果重叠，那么返回false，否则插入节点
        if(root==nullptr){
            root = new TreeNode(start,end);
            return true;
        }
        TreeNode* node = root;
        TreeNode* pre = nullptr;
        while(node!=nullptr){
            pre = node;
            if(node->start>=end){
                node = node->left;
            }else if(node->end<=start){
                node = node->right;
            }else{
                return false;
            }
        }
        if(pre->start>=end){
            pre->left = new TreeNode(start,end);
        }else{
            pre->right = new TreeNode(start,end);
        }
        return true;
    }
private:
    struct TreeNode{
        int start;
        int end;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int s, int e):start(s),end(e),left(nullptr),right(nullptr){}
    };
    TreeNode* root = nullptr;

};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */