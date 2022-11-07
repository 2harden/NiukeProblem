// 字节对齐
// 32位系统
#include <iostream>

using namespace std;

struct{
    char y;
    int x;
    int a;
}s;

int main()
{
    cout << sizeof(s) << endl; // 输出8

    return 0;
}