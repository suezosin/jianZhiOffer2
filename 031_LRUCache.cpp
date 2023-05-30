//
// Created by 23116 on 2023/05/12.
//
//最近最少使用缓存
class ListNodes { //双向链表结点
public:
    int key; //key
    int value; //value
    ListNodes *prev; //前驱结点
    ListNodes *next; //后继结点
    ListNodes(int key, int value) { //构造函数
        this->key=key; //初始化key
        this->value=value; //初始化value
        prev= nullptr; //初始化前驱结点
        next= nullptr; //初始化后继结点
    }
};
class LRUCache {
public:
    int capacity; //容量
    int size=0; //结点数
    ListNodes *head; //头结点
    ListNodes *tail; //尾结点
    unordered_map<int, ListNodes*> map; //map
    LRUCache(int capacity) {
        this->capacity=capacity; //初始化容量
        map.clear(); //清空map
        head=new ListNodes(-1, -1); //初始化头结点
        tail=new ListNodes(-1, -1); //初始化尾结点
        head->next=tail; //头结点的后继结点是尾结点
        tail->prev=head; //尾结点的前驱结点是头结点
    }

    int get(int key) {
        if(map.find(key)==map.end()) return -1; //如果map中没有key，返回-1
        ListNodes *node=map[key]; //取出map中的key
        moveToHead(node); //将该结点移动到头结点
        return node->value; //返回该结点的value
    }

    void put(int key, int value) {//put结点
        if(map.find(key)!=map.end()){ //如果map中有key
            ListNodes *node=map[key]; //取出map中的key
            node->value=value; //更新该结点的value
            moveToHead(node); //将该结点移动到头结点
        }else{
            ListNodes *node=new ListNodes(key, value); //新建结点
            map[key]=node; //将结点放入map
            addToHead(node); //将结点放入头结点
            size++; //结点数加1
            if(size>capacity){ //如果结点数大于容量
                ListNodes *remove=removeTail(); //删除尾结点
                map.erase(remove->key); //从map中删除该结点
                delete remove; //释放该结点
                size--; //结点数减1
            }
        }

    }

    void moveToHead(ListNodes *n){
        n->prev->next=n->next;
        n->next->prev=n->prev;
        n->next=head->next;
        head->next->prev=n;
        head->next=n;
        n->prev=head;
    }

    void addToHead(ListNodes *n){
        n->next=head->next;
        head->next->prev=n;
        head->next=n;
        n->prev=head;
    }

    ListNodes* removeTail(){
        ListNodes *n=tail->prev;
        n->prev->next=tail;
        tail->prev=n->prev;
        return n;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */