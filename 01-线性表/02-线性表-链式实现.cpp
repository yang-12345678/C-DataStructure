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
LNode * CreateList(LinkList &L, ElemType e) {
    LinkList p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }

    return p;
}

int main() {
    return 0;
}
