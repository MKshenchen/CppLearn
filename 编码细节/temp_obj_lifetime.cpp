// 关于临时变量及悬垂引用:
// return 语句中绑定到函数返回值的临时量
// 和在函数调用中绑定函数形参的临时量
// 都将在该表达式/返回表达式j结束后被立即销毁
// 如果这俩个表达式赋值给了另外的引用变量
// 那么则为悬垂引用,是不安全的
#include <iostream>
using namespace std;

const string& f(const string& s) {
    return s;
}

int main() {
    auto& res = f("?");
    // 以上代码等同于:
    // auto& res = f(string("?"));
    // 即调用string的构造函数将
    // "?" 这个 const char[2] 字面量
    // 转换成一个string
    // 然后在f()的调用中被返回
    // 直至此句代码执行结束
    // "?" 被释放结束生存周期
    // res 成为悬垂引用
    cout << res << endl;
    cin.get();
    return 0;
}