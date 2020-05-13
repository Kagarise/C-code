#include "main.h"

/*
 * 能够实现n个多项式计算
 * 更改solve.h中的TOL即可
 */

void solve() {
    LinkList L[TOL + 1];
    // 输入多项式
    for (int i = 1; i <= TOL; i++) {
        creat_LinkList(L[i]);
        tip_polynomial(i, L[i]);
    }
    // 输出输入数据
    for (int i = 1; i <= TOL; i++) {
        tip_outPolynomial(i, L[i]);
        cout << endl;
    }
    // 输入操作符
    char oper;
    tip_operator(oper);
    tip_outOperator(oper);
    // 创建RES链表，记录运算答案
    LinkList CAS, RES;
    creat_LinkList(CAS);
    creat_LinkList(RES);
    // 计算结果
    for (int i = 1; i < TOL; i++) {
        if (i == 1)
            cal_polynomial(L[i], L[i + 1], RES, oper);
        else {
            // 将中间结果复制到CAS中，用于下一次计算
            copy(CAS, RES);
            cal_polynomial(CAS, L[i + 1], RES, oper);
        }
    }
    // 输出结果多项式
    tip_answer();
    print_LinkList(RES);
}

// 提示输入多项式
void tip_polynomial(const int num, LinkList& L) {
    __GREEN__
    cout << "请输入第" << num << "个多项式" << endl;
    cout << "请先输入一个整数n，表示多项式的项数" << endl;
    __WHITE__
    int n;
    cin >> n;
    __GREEN__
    cout << "接着输出" << n << "个多项式(系数 指数)" << endl;
    __WHITE__
    for (int i = 0; i < n; i++) {
        ElemType x;
        cin >> x.coe >> x.exp;
        push_ascending(L, x);
    }
}

// 提示输出输入的多项式
void tip_outPolynomial(const int num, LinkList L) {
    cout << "输入的第" << num << "个多项式的降幂形式为：";
    print_LinkList_descending(L /*, false*/);
    cout << endl;
}

// 提示输入运算符
void tip_operator(char& oper) {
    __GREEN__
    cout << "请输入操作符(+ - *)" << endl;
    __WHITE__
    cin >> oper;
}

// 输出输入的运算符
void tip_outOperator(const char op) {
    cout << "输入的运算符为" << op << endl;
}

// 计算多项式
void cal_polynomial(LinkList A, LinkList B, LinkList& L, const char op) {
    clear_LinkList(L);
    switch (op) {
        case '+':
            AddList(A, B, L);
            break;
        case '-':
            SubList(A, B, L);
            break;
        case '*':
            MulList(A, B, L);
            break;
        default:
            __RED__
            cout << "操作符错误" << endl;
            __WHITE__
            break;
    }
}

// 提示输出结果
void tip_answer() {
    __GREEN__
    cout << "计算结果多项式为：" << endl;
    __WHITE__
}