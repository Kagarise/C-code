#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

typedef int Status;
#define OK 1
#define ERROR 0

typedef struct LNode {
    int coe;  // 系数
    int exp;  // 指数
    // 构造函数，初始化节点，赋值
    LNode() : coe(0), exp(0) {}
    LNode(int coe, int exp) : coe(coe), exp(exp) {}
    // 重载 == 用以比较，系数和指数均相同时判定相等
    bool operator==(const LNode& A) const {
        if (coe != A.coe)
            return false;
        if (exp != A.exp)
            return false;
        return true;
    }
} ElemType;

typedef struct node {
    ElemType data;
    node* next;
} LinkNode, *LinkList;

Status creat_LinkList(LinkList& L);                   // 创建链表
void clear_LinkList(LinkList& L);                     // 清空链表
Status push_back(LinkList L, const ElemType x);       // 在链表尾部插入元素
Status push_ascending(LinkList L, const ElemType x);  // 插入链表，使链表保持升序
Status delete_node(LinkList L, ElemType x);  // 删除链表中第一个与x相同的元素
void print_LinkList(LinkList L);             // 输出链表
void print_LinkList_ascending(LinkList L /*, bool op*/);   // 升幂输出链表
void print_LinkList_descending(LinkList L /*, bool op*/);  // 降幂输出链表
void print_Lnode(const ElemType x, const bool op);         // 输出当前节点元素
void copy(LinkList& C, LinkList L);                        // 复制L到C

#endif  // LINKLIST_H_INCLUDED
