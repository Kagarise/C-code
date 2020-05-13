#ifndef SOLVE_H_INCLUDED
#define SOLVE_H_INCLUDED

#define TOL 2  // 多项式的总数

void solve();
void tip_polynomial(const int num, LinkList& L);    // 提示输入多项式
void tip_outPolynomial(const int num, LinkList L);  // 提示输出输入的多项式
void tip_operator(char& op);                        // 提示输入运算符
void tip_outOperator(const char op);                // 输出输入的运算符
void cal_polynomial(LinkList A, LinkList B, LinkList& L, const char op);  // 计算多项式
void tip_answer();  // 提示输出结果

#endif  // SOLVE_H_INCLUDED