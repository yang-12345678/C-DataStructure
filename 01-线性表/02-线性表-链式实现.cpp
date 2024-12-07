#include <iostream>
#include "predefine.h"
using namespace std;

typedef struct LNode {
  ElemType data;  // 节点的数据
  struct LNode * next;
}LNode, *LinkList;

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

int main() {
  return 0;
}