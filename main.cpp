#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
const int M = 2; //定义 B 树的最小度数
const int KEY_MAX = 2 * M - 1; //键值个数的上限
const int KEY_MIN = M - 1; //键值个数的下限
const int CHILD_MAX = KEY_MAX + 1; //孩子结点个数的上限
const int CHILD_MIN = KEY_MIN + 1; //孩子结点个数的下限
//定义结点
template<class T>
class Node {
public:
    bool isLeaf; //是否为叶子节点
    vector<T> keyValue; //键值容器
    vector<Node*> pChild; //孩子指针容器
    int keyNum; //存储键值的个数
    //构造初始化
    Node() {
        isLeaf = true;
        keyNum = 0;
        keyValue.resize(KEY_MAX);
        pChild.resize(CHILD_MAX);
    }
};
template<class T>
class BTree {
private:
    Node<T> *root; //定义根节点
public:
    //初始化一棵空的 B 树
    BTree();
    //析构释放 B 树
    ~BTree();
    //得到根节点
    Node<T>* getRootNode();
    //查找节点
    bool search(Node<T>* p, T key);
    //释放 B 树空间
    void clearBTree(Node<T>* p);
    //分裂 B 树中的结点
    void splitChild(Node<T>* p, int index);
    //插入关键字
    bool insertKey(T key);
    void insertNonFull(Node<T>* p, T key);
    //合并结点
    void mergeChild(Node<T>* p, int index);
    //找前驱
    T getPredecessor(Node<T>* p);
    //找后继
    T getSuccessor(Node<T>* p);
    //删除结点
    bool deleteKey(T key);
    void recursiveDeleteKey(Node<T>* p, T key);
    //遍历 B 树
    void printBTree(Node<T>* p, int count);
    //输出 B 树最右结点的最右关键字
    void printBTree_right(Node<T>* p);
};
template<class T>
BTree<T>::BTree() {
    root = new Node<T>();
}
template<class T>
BTree<T>::~BTree() {
    clearBTree(root);
}
template<class T>
bool BTree<T>::search(Node<T> *p, T key) {
    int i = 0;
     //查找 key 可能在的位置
    while (i < p->keyNum && key > p->keyValue[i]) {
        ++i;
    }
    //找到了
    if (i < p->keyNum && key == p->keyValue[i]) {
        return true;
    }
    else {
        //叶子结点
        if (p->isLeaf) {
            return false;
        }
        else {
            //递归查找
            return search(p->pChild[i], key);
        }
    }
}
template<class T>
void BTree<T>::clearBTree(Node<T>* p) {
    if (p != NULL) {
        if (!p->isLeaf) {
            for (int i = 0; i <= p->keyNum; ++i) {
                clearBTree(p->pChild[i]);
            }
        }
        delete p;
        p = NULL;
    }
}
template<class T>
void BTree<T>::splitChild(Node<T>* p, int index) {
    //新建分裂后的右子树
    Node<T> *pRight = new Node<T>();
    //分裂后的左子树
    Node<T> *pLeft = p->pChild[index];
    pRight->isLeaf = pLeft->isLeaf;
    pRight->keyNum = KEY_MIN;
    //将左子树中后边的值赋给右子树
    for (int i = 0; i < KEY_MIN; ++i) {
        pRight->keyValue[i] = pLeft->keyValue[i + M];
    }
    //如果左子树不为叶节点，将其孩子对应的孩子赋给右子树
    if (!pLeft->isLeaf) {
        for (int i = 0; i < CHILD_MIN; ++i) {
            pRight->pChild[i] = pLeft->pChild[i + M];
        }
    }
    //更新左子树的键值个数
    pLeft->keyNum = KEY_MIN - 1;
    //将右子树插入到指定位置
    for (int i = p->keyNum; i > index; --i) {
        p->pChild[i + 1] = p->pChild[i];
    }
    p->pChild[index + 1] = pRight;
    //将左子树的最后一个键值插入到父节点
    for (int i = p->keyNum - 1; i >= index; --i) {
        p->keyValue[i + 1] = p->keyValue[i];
    }
    p->keyValue[index] = pLeft->keyValue[M - 1];
    //更新父节点的键值个数
    p->keyNum++;
}
template<class T>
bool BTree<T>::insertKey(T key) {
    //树为空
    if (root->keyNum == KEY_MAX) {
        //新建父节点
        Node<T> *pNew = new Node<T>();
        //根节点变为新父节点的左孩子
        pNew->isLeaf = false;
        pNew->pChild[0] = root;
        root = pNew;
        //分裂原本的根节点
        splitChild(root, 0);
    }
    insertNonFull(root, key);
    return true;
}
template<class T>
void BTree<T>::insertNonFull(Node<T>* p, T key) {
    int i = p->keyNum - 1;
    if (p->isLeaf) { //叶子结点
        while (i >= 0 && key < p->keyValue[i]) {
            p->keyValue[i + 1] = p->keyValue[i];
            --i;
        }
        p->keyValue[i + 1] = key;
        p->keyNum++;
    }
    else { //非叶子结点
        while (i >= 0 && key < p->keyValue[i]) {
            --i;
        }
        ++i;
        if (p->pChild[i]->keyNum == KEY_MAX) { //子节点已满
            splitChild(p, i);
            if (key > p->keyValue[i]) {
                ++i;
            }
        }
        insertNonFull(p->pChild[i], key);
    }
}
template<class T>
void BTree<T>::mergeChild(Node<T>* p, int index) {
    Node<T> *pLeft = p->pChild[index];
    Node<T> *pRight = p->pChild[index + 1];
    //将父节点的键值插入到左子树
    pLeft->keyValue[KEY_MIN] = p->keyValue[index];
    //将右子树的键值全部赋给左子树
    for (int i = 0; i < KEY_MIN; ++i) {
        pLeft->keyValue[i + KEY_MIN + 1] = pRight->keyValue[i];
    }
    //将右子树的孩子全部赋给左子树
    if (!pRight->isLeaf) {
        for (int i = 0; i < CHILD_MIN; ++i) {
            pLeft->pChild[i + KEY_MIN + 1] = pRight->pChild[i];
        }
    }
    //删除父节点的键值和右子树
    for (int i = index; i < p->keyNum - 1; ++i) {
        p->keyValue[i] = p->keyValue[i + 1];
        p->pChild[i + 1] = p->pChild[i + 2];
    }
    //更新父节点的键值个数
    p->keyNum--;
    //释放空间
    delete pRight;
}
template<class T>
T BTree<T>::getPredecessor(Node<T>* p) {
    while (!p->isLeaf) {
        p = p->pChild[p->keyNum];
    }
    return p->keyValue[p->keyNum - 1];
}
template<class T>
T BTree<T>::getSuccessor(Node<T>* p) {
    while (!p->isLeaf) {
        p = p->pChild[0];
    }
    return p->keyValue[0];
}
template<class T>
bool BTree<T>::deleteKey(T key) {
    if (root == NULL) {
        return false;
    }
    else {
        bool isFound = deleteKey(root, key);
        if (root->keyNum == 0) {
            Node<T> *p = root;
            root = root->pChild[0];
            delete p;
        }
        return isFound;
    }
}
template<class T>
void BTree<T>::recursiveDeleteKey(Node<T>* p, T key) {
    int i = 0;
    while (i < p->keyNum && key > p->keyValue[i]) {
        ++i;
    }
    if (i < p->keyNum && key == p->keyValue[i]) {
        //情况 1：待删除关键字在叶子结点中
        if (p->isLeaf) {
            for (int j = i; j < p->keyNum - 1; ++j) {
                p->keyValue[j] = p->keyValue[j + 1];
            }
            p->keyNum--;
        }
        //情况 2：待删除关键字在内部结点中且其子节点均不少于 M
        else if (p->pChild[i]->keyNum >= M) {
            T predecessor = getPredecessor(p->pChild[i]);
            p->keyValue[i] = predecessor;
            recursiveDeleteKey(p->pChild[i], predecessor);
        }
        //情况 3：待删除关键字在内部结点中且其后继结点的子节点均不少于 M
        else if (p->pChild[i + 1]->keyNum >= M) {
            T successor = getSuccessor(p->pChild[i + 1]);
            p->keyValue[i] = successor;
            recursiveDeleteKey(p->pChild[i + 1], successor);
        }
        //情况 4：待删除关键字在内部结点中且其子节点及其后继结点的子节点均小于 M，此时需要合并结点，并递归删除
        else {
            mergeChild(p, i);
            recursiveDeleteKey(p->pChild[i], key);
        }
    }
    else {
        //情况 5：待删除关键字在内部结点中，且其子节点均小于 M，此时需要合并结点，并递归删除
        if (!p->isLeaf && p->pChild[i]->keyNum == M - 1) {
            if (i == p->keyNum || p->pChild[i + 1]->keyNum == M - 1) {
                mergeChild(p, i);
                if (i == p->keyNum) {
                    i--;
                }
            }
            recursiveDeleteKey(p->pChild[i], key);
        }
        //情况 6：待删除关键字不存在于树中
        else if (!p->isLeaf && p->pChild[i]->keyNum > M - 1) {
            recursiveDeleteKey(p->pChild[i], key);
        }
    }
}
template <class T>
void BTree < T >::printBTree_right(Node < T > *p) {
    if (p != NULL)
    {
        int i;
        cout << p->keyValue[p->keyNum - 1] << endl;
        if (!p->isLeaf)
        {
            printBTree_right(p->pChild[p->keyNum]);
        }
    }
}

template <class T>
Node < T > *BTree < T >::getRootNode() {
    return root;
}

int main()
{
    BTree<int>* root = new BTree<int>();
    int data, len;
    cin >> len;
    /*cin >> data;*/
    while (len != 0)
    {
        cin >> data;
        root->insertKey(data);
        len--;
    }
    root->printBTree_right(root->getRootNode());
    return 0;
}