#include "main.h"

void AddList(LinkList A, LinkList B, LinkList& L) {  // 多项式相加
    LinkList la = A->next, lb = B->next;
    while (la && lb) {
        // 如果指数相同
        if (la->data.exp == lb->data.exp) {
            int COE = la->data.coe + lb->data.coe;
            int EXP = la->data.exp;
            push_ascending(L, ElemType(COE, EXP));
            la = la->next;
            lb = lb->next;
        }
        // 将小的元素添加到L中
        else if (la->data.exp < lb->data.exp) {
            push_ascending(L, la->data);
            la = la->next;
        } else {
            push_ascending(L, lb->data);
            lb = lb->next;
        }
    }
    // 将A、B中剩余元素添加到L中
    // 可以直接令L尾指针指向la或lb
    while (la) {
        push_ascending(L, la->data);
        la = la->next;
    }
    while (lb) {
        push_ascending(L, lb->data);
        lb = lb->next;
    }
}
void SubList(LinkList A, LinkList B, LinkList& L) {  // 多项式相减
    LinkList la = A->next, lb = B->next;
    while (la && lb) {
        // 如果指数相同
        if (la->data.exp == lb->data.exp) {
            int COE = la->data.coe - lb->data.coe;
            int EXP = la->data.exp;
            push_ascending(L, ElemType(COE, EXP));
            la = la->next;
            lb = lb->next;
        }
        // 将小的元素添加到L中
        else if (la->data.exp < lb->data.exp) {
            push_ascending(L, la->data);
            la = la->next;
        } else {
            // 相减，系数取负
            push_ascending(L, ElemType(-lb->data.coe, lb->data.exp));
            lb = lb->next;
        }
    }
    // 将A、B中剩余元素添加到L中
    while (la) {
        push_ascending(L, la->data);
        la = la->next;
    }
    while (lb) {
        // 相减，系数取负
        push_ascending(L, ElemType(-lb->data.coe, lb->data.exp));
        lb = lb->next;
    }
}
void MulList(LinkList A, LinkList B, LinkList& L) {  // 多项式相乘
    LinkList la = A->next;
    while (la) {
        LinkList lb = B->next;
        while (lb) {
            // 系数相乘，指数相加
            int COE = la->data.coe * lb->data.coe;
            int EXP = la->data.exp + lb->data.exp;
            push_ascending(L, ElemType(COE, EXP));
            lb = lb->next;
        }
        la = la->next;
    }
}
