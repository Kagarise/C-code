#include "main.h"

// 创建链表
Status creat_LinkList(LinkList& L) {
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        return ERROR;
    L->next = NULL;
    return OK;
}

// 清空链表
void clear_LinkList(LinkList& L) {
    if (L->next) {
        clear_LinkList(L->next);
        free(L->next);
        L->next = NULL;
    }
}

// 在链表尾部插入元素
Status push_back(LinkList L, const ElemType x) {
    LinkList D;
    while (L->next)
        L = L->next;
    D = (LinkList)malloc(sizeof(LNode));
    if (!D)
        return ERROR;
    D->data = x;
    D->next = NULL;
    L->next = D;
    return OK;
}

// 插入链表，使链表保持升序
Status push_ascending(LinkList L, const ElemType x) {
    while (L->next && x.exp >= L->next->data.exp) {
        // 如果已经含有相同指数，则系数相加
        if (L->next->data.exp == x.exp) {
            L->next->data.coe += x.coe;
            return OK;
        }
        L = L->next;
    }
    // 新指数节点，插入到L的合适位置
    LinkList D = (LinkList)malloc(sizeof(LNode));
    D->data = x;
    D->next = L->next;
    L->next = D;
    return OK;
}

// 删除链表中第一个与x相同的元素
Status delete_node(LinkList L, ElemType x) {
    while (L->next) {
        if (L->next->data == x) {
            // 如果是链表最后一个元素
            if (L->next->next == NULL) {
                free(L->next->next);
                L->next = NULL;
            } else {
                LinkList tmp = L->next->next;
                free(L->next);
                L->next = tmp;
            }
            return OK;
        } else {
            L = L->next;
        }
    }
    return ERROR;
}

/*
 * FOR: print_*
 * op : true   多项式第一项
 * op : false  非多项式第一项
 */

// 输出链表
void print_LinkList(LinkList L) {
    __GREEN__
    cout << "以升幂输出多项式" << endl;
    __WHITE__
    print_LinkList_ascending(L /*, true*/);
    cout << endl;
    __GREEN__
    cout << "以降幂输出多项式" << endl;
    __WHITE__
    print_LinkList_descending(L /*, false*/);
    cout << endl;
}

// 升幂输出链表
void print_LinkList_ascending(LinkList L /*, bool op*/) {
    queue<ElemType> Q;
    while (L->next) {
        if (L->next->data.coe != 0)
            Q.push(L->next->data);
        L = L->next;
    }
    bool op = true;
    while (!Q.empty()) {
        print_Lnode(Q.front(), op);
        op = false;
        Q.pop();
    }
    // if (L) {
    //     print_Lnode(L->data, op);
    //     print_LinkList_ascending(L->next, false);
    // }
}

// 降幂输出链表
void print_LinkList_descending(LinkList L /*, bool op*/) {
    stack<ElemType> S;
    while (L->next) {
        if (L->next->data.coe != 0)
            S.push(L->next->data);
        L = L->next;
    }
    bool op = true;
    while (!S.empty()) {
        print_Lnode(S.top(), op);
        op = false;
        S.pop();
    }
    // if (L) {
    //     if (L->next && L->next->next == NULL)
    //         print_LinkList_descending(L->next, true);
    //     else
    //         print_LinkList_descending(L->next, false);
    //     print_Lnode(L->data, op);
    // }
}

/*
 * 用以格式化输出
 * 例如，将会以如下格式输出多项式：
 * "-3^2 + 4^3 - 5^4"
 * "3^2 + 4^3 - 5^4"
 */

// 输出当前节点元素
void print_Lnode(const ElemType x, const bool op) {
    if (op) {
        if (x.coe < 0)
            cout << "-";
    } else {
        if (x.coe < 0)
            cout << " - ";
        else
            cout << " + ";
    }
    // 控制输出格式
    int COE = abs(x.coe);
    if (x.exp == 0) {
        cout << COE;
    } else if (x.exp == 1) {
        if (COE != 1)
            cout << COE;
        cout << "x";
    } else {
        if (COE != 1)
            cout << COE;
        cout << "x^";
        if (x.exp < 0)
            cout << "(" << x.exp << ")";
        else
            cout << x.exp;
    }
}

// 复制L到C
void copy(LinkList& C, LinkList L) {
    while (L->next) {
        push_ascending(C, L->data);
        L = L->next;
    }
}