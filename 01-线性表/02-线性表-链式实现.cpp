#include <iostream>
#include "predefine.h"
using namespace std;

typedef struct LNode {
    ElemType data; // 节点的数据
    struct LNode *next;
} LNode, *LinkList;

// 为了处理方便，在单链表的第一个节点之前增加一个节点--头节点/哨兵节点。
// 否则，有时候需要对第一个节点做特殊操作

/**
 * 初始化空表
 * @param L 单链表
 * @return 状态码
 */
Status InitList(LinkList &L) {
    // 构造一个空的单链表 L
    L = new LNode;
    L->next = NULL;
    return OK;
}

/**
 * 获取值: O(n)
 * @param L 单链表
 * @param i 第几个元素
 * @return 值
 */
ElemType GetElem(LinkList &L, int i) {
    LinkList p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }

    // p 为空，说明遍历到底也没有找到，可能 i > n
    // while 结束最大也只是 j==i,如果 j > i 说明 i<=0
    if (!p || j > i) return ERROR;
    return p->data;
}

/**
 * 按值查找：O(n)
 * @param L 单链表
 * @param e 值
 * @return 找到返回节点的地址值，找不到返回 NULL
 */
LinkList LocateElem(LinkList &L, ElemType e) {
    LinkList p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }

    return p;
}

/**
 * 插入元素: O(n)
 * @param L 单链表
 * @param i 插入位置
 * @param e 插入值
 * @return 状态码
 */
Status ListInsert(LinkList &L, int i, ElemType e) {
    LinkList p = L; // 哨兵是第 0 个节点，插入第一个位置，找到它的前一个结点就是第 0 个节点
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) return ERROR; // j 最多找到 i - 1 位置
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 * 删除元素: O(n)
 * @param L 单链表
 * @param i 删除索引
 * @return 状态码
 */
Status ListDelete(LinkList &L, int i) {
    LinkList p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }

    if (!p->next || j > i - 1) return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}

/**
 * 头插法: O(n)
 * @param L 单链表
 * @param n 插入元素的个数
 */
void CreateList(LinkList &L, int n) {

    for (int i = 0; i < n; ++i) {
        LinkList p = new LNode;
        cout << "请输入要插入的值 " << i + 1 << ": ";
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

// 尾插法需要一个尾指针指向尾节点或找到最后一个节点（成本高）: O(n)

void printList(LinkList L) {
    LinkList p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    LinkList L;
    InitList(L);


    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 4);
    ListInsert(L, 4, 5);
    printList(L);

    ListInsert(L, 3, 3);
    printList(L);

    ElemType elem = GetElem(L, 3);
    cout << elem << endl;

    LinkList n = LocateElem(L, 5);
    cout << n->data << endl;

    ListDelete(L, 3);
    printList(L);

    CreateList(L, 5);
    printList(L);


    return 0;
}
