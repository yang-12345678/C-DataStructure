#include <iostream>
#include "predefine.h"
using namespace std;

long MAXSIZE = 100;

typedef struct {
    ElemType *elem; // 存储空间的基地址
    int length; // 当前长度
} SqList;

/**
 * 初始化空的顺序表
 * @param L 顺序表的引用
 * @return 状态码
 */
Status InitList(SqList &L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem) exit(OVERFLOW);

    L.length = 0;
    return OK;
}

/**
 * 扩容顺序表
 * @param L
 * @return
 */
Status IncreamentList(SqList &L) {
    SqList tmp = L;

    MAXSIZE = MAXSIZE * (1 + INCREMENT);
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem) exit(OVERFLOW);

    for (int i = 0; i < tmp.length; i++) {
        L.elem[i] = tmp.elem[i];
    }
    L.length = tmp.length;
    cout << "扩容了" << endl;
    return OK;
}

/**
 * 顺序表的取值: O(1)
 * @param L 顺序表
 * @param i 索引
 * @return
 */
ElemType GetElem(SqList L, int i) {
    // 检查 i 是否合理
    if (i < 1 || i > L.length)
        return ERROR;

    return L.elem[i - 1];
}

/**
 * 查找元素: O(n)
 * @param L 顺序表
 * @param e 待查找元素
 * @return e 的索引，否则返回 0
 */
int LocateElem(SqList L, ElemType e) {
    // 返回与 e 相等元素的索引
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e) return i + 1;
    // 没有找到
    return 0;
}

/**
 * 插入元素: O(n)
 * @param L 顺序表
 * @param i 插入第几个位置
 * @param e 插入元素
 * @return 状态码
 */
Status ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) return ERROR; // 不合法

    if (L.length == MAXSIZE) {
        IncreamentList(L);
    }

    for (int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];
    L.elem[i - 1] = e;
    ++L.length;
    return OK;
}

/**
 * 删除元素: O(n)
 * @param L 顺序表
 * @param i 元素索引
 * @return 状态码
 */
Status ListDelete(SqList &L, int i) {
    if (i < 1 || i > L.length) return ERROR;

    for (int j = i; j < L.length; j++)
        L.elem[j - 1] = L.elem[j];
    --L.length;
    return OK;
}

Status ListTraverse(SqList &L) {
    for (int i = 0, j = L.length - 1; i < L.length; i++, j--) {
        if (j - i <= 1) return OK;

        int tmp = L.elem[i];
        L.elem[i] = L.elem[j];
        L.elem[j] = tmp;
    }
    return OK;
}

void printList(SqList L) {
    for (int i = 0; i < L.length; i++)
        cout << L.elem[i] << " ";
    cout << endl;
}

int main() {
    SqList L;
    InitList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 4);
    ListInsert(L, 4, 5);
    printList(L);
    cout << L.length << endl;

    int n = LocateElem(L, 4);
    int elem = GetElem(L, 4);
    cout << n << endl;
    cout << elem << endl;


    ListInsert(L, 3, 3);
    printList(L);
    cout << L.length << endl;

    ListDelete(L, 3);
    printList(L);

    ListInsert(L, 3, 3);
    ListInsert(L, 6, 6);
    printList(L);

    ListTraverse(L);
    printList(L);

    return 0;
}
