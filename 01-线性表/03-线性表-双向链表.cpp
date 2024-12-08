#include <iostream>
#include "predefine.h"
using namespace std;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

// 初始化
Status InitList(DuLinkList &L) {
    L = new DuLNode;
    L->prior = L;
    L->data = 999;
    L->next = L;
    return OK;
}

DuLinkList getElemI(DuLinkList L, int i) {

    DuLinkList p = L;
    int j = 0;

    while (p && j < i) {
        p = p->next;
        j++;
    }

    return p;
}

// 插入
Status ListInsert(DuLinkList &L, int i, ElemType e) {

    DuLinkList p = getElemI(L, i - 1);

    if (!p) return ERROR;
    DuLinkList s = new DuLNode;
    s->data = e;
    s->prior = p;

    s->next = p->next;

    p->next->prior = s;
    p->next = s;

    return OK;
}

Status ListDelete(DuLinkList &L, int i) {
    DuLinkList p = getElemI(L, i - 1);
    if (!p) return ERROR;
    p->next->next->prior = p;
    p->next = p->next->next;
    return OK;
}
void printList(DuLinkList L) {
    DuLinkList p = L->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    DuLinkList L;
    InitList(L);


    ListInsert(L, 1, 2);

    ListInsert(L, 2, 3);
    ListInsert(L, 3, 4);
    printList(L);
    ListDelete(L, 2);
    printList(L);

}
