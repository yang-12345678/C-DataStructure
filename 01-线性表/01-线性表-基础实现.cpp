#include "iostream"
using namespace std;

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType *elem; // 存储空间的基地址
    int length; // 当前长度
} SqList;

/**
 * 初始化空的线性表
 * @param L 线性表的引用
 * @return 状态码
 */
Status InitList(SqList &L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem) exit(OVERFLOW);

    L.length = 0;
    return OK;
}

/**
 * 顺序表的取值
 * @param L 顺序表
 * @param i 索引
 * @param e 值
 * @return
 */
Status GetElem(SqList L, int i, ElemType &e) {
    // 检查 i 是否合理
    if (i < 1 || i > L.length)
        return ERROR;

    e = L.elem[i - 1];
    return OK;
}

int main() {
    return 0;
}