// 牛客网刷题
#include <iostream>
#include <string.h>
using namespace std;

// 编译运行：g++ .\Question.cpp -o .\Question.exe;.\Question.exe

// 1,================================================================
// int fun(void) {
//     int *p, j, i=10;
//     p = &j;
//     *p = i++;
//     i += sizeof(i) + sizeof(*p) + sizeof(p);
//     return i;
// }

// int main()
// {
//     cout << fun() << endl; // 32位系统输出23 64位系统输出为27

//     return 0;
// }

// 2,================================================================
// int main()
// {
//     char ccString1[]="Is Page Fault??";
//     char ccString2[]="No Page Fault??";
//     strcpy(ccString1,"No"); // 执行strcpy(ccString1,"No"); ，ccString1变为"No\0Page Fault??"，会将字符串的结束符'\0'放入，所以比较时返回false，执行cout << ccString1; 输出时遇到结束符'\0'就结束，只输出“NO”
//     if(strcmp(ccString1,ccString2)==0)
//         cout<<ccString2;
//     else
//         cout<<ccString1;

//     return 0;
// }

// 3,================================================================
// int main() {
//     int a = 1;
//     int b = 2;
//     for (; a < 8; a++) {
//         b += a;
//         a += 2;
//     }
//     printf("%d, %d\n", a, b); // 10, 14 a++不要忘记

//     return 0;
// }

// 4,================================================================
// int main() {
//     int i = 5;
//     int a = (++i)--;
//     cout << "a = " << a << "\t" << "i = " << i << endl; // a = 6   i = 5

//     return 0;
// }

// 5,================================================================
// sizeof()与strlen()
// int main()
// {
// 	char *s = "a+b=20\n";
// 	cout << sizeof(s) << '\n'; // 8 \n的算一个字符，占用两个空间
// 	cout << strlen(s); // 7 \n转意为换行符，所以长度是7

//     return 0;
// } 

// 6,================================================================
// int main()
// {
//     int a[4] = { 0 };
//     for(int i=0;i<4;++i){
//         if(i&1){
//             a[i]=1;
//         }
//         cout << a[i] << "  "; // 0 1 0 1 位运算 0&1=0 1&1=1 2&1=0x10&0x01=0 3&1=0x11&0x01=0x11
//     }

//     return 0;
// }

// 7,================================================================
// 字节对齐
// 对于第一条原则，每个变量相对于结构体的首地址的偏移量必须是对齐参数的整数倍，这句话中的对齐参数是取每个变量自身对齐参数和系统默认对齐参数#pragma pack(n)中较小的一个;
// 对于第二条原则，结构体变量所占空间的大小是对齐参数的整数倍。这句话中的对齐参数有点复杂，它是取结构体中所有变量的对齐参数的最大值和系统默认对齐参数#pragma pack(n)比较，较小者作为对齐参数。
// #pragma pack(2) // 强制2字节对齐
// class A
// {
//     int i;                          // 占4个字节
//     union U                         // union是共享内存空间的，并且union所占的字节数由里面最大元素决定！因此char buff[13]和int i共享内存空间，由于2字节对齐，因此13+1，共占14个字节
//     {
//         char buff[13];
//         int i;
//     }u;
//     void foo(){}                    // 成员函数不占内存空间
//     typedef char* (*f)(void*);      // typedef是类型别名也不占内存空间，如果typedef去掉 就是一个指针 这个时候就要占内存空间 32位机器是4字节，64位机器是8字节
//     enum{red, green, blue} color;   // 对于enum，规定其占一个int的大小，4个字节
// }a;

// int main()
// {
//     cout << sizeof(a) << endl; // 输出22

//     return 0;
// }
// ------------------------------------------------------------------
// 32位系统
// #include <iostream>

// using namespace std;

// struct{
//     char y;
//     int x;
//     int a;
// }s;

// int main()
// {
//     cout << sizeof(s) << endl; // 输出12

//     return 0;
// }

// 8,================================================================
// 以下程序存在什么问题？ 
// 数组下标越界
// 死循环

// #define MAX 255 
// int main()
// {
//     unsigned char a[MAX],i; // 这个应该是的问题，数组255大小，但是当a[255]就是256个元素，相当于越界了
//     for(i=0;i<=MAX;i++)     // 这个就是字符型的变量大小在0-255之间，所以说i永远不可能大于255的，死循环
                               // 原因在于unsigned char 这个数据类型，它占了 8位，表示范围是 0~255（00000000~11111111，八位）； 当改成256后，虽说看似数组下标没越界，但是当i=255; i++ ；因为 i本身是unsigned char类型，占8位，所以此时i+1变成了100000000 9位，又因为i只能占8位，所以舍掉了最高位，此时的i值又变成00000000了，即就是0；然后就成了死循环了。。。
//     a[i]=i;
// }

// 9,================================================================
// ++与--运算符
// int main()
// {
//     int x = 1, y = -1;
//     // 按位&：位和位相与，数据同为1，则为1，否则为0
//     // 按位 |：位和位相或，数据同为0，则为0，否则为1
//     // x值为1，x--值为0
//     // y值为-1；y++值为0
//     // 0&0为0
//     printf("%d\n", (x-- & ++y)); // 后缀x--，先使用1，再将x-1 前缀++y，现将y+1，再使用y；

//     return 0;
// }

// 10,================================================================
// 下面选项中的程序段，没有编译错误的是（A）
// A. char* sp, s[10]; sp = "Hello";                      // 正确，sp为一个字符型指针，通过赋值获得了“hello”的地址
// B. char* sp, s[10]; s = "Hello";                       // 错误，字符数组赋值，用采用strcpy()函数，strcpy(s,"Hello");
// C. char str1[10] = "computer", str2[10]; str2 = str1;  // 错误，字符数组赋值，用采用strcpy()函数，strcpy(str2,str1);
// D. char mark[]; mark = "PROGRAM";                      // 错误，字符数组未初始化不可省略数组大小，正确应为char mark[]= "PROGRAM";

// 11,================================================================
// 内敛函数

// 在一个函数中，要求通过函数来实现一种不太复杂的功能，并且要求加快执行速度，选用（A）。
// A. 内联函数
// B. 重载函数
// C. 递归调用
// D. 嵌套调用
// 解析：
// C++ 建议内联函数 替换宏函数（消除调用的时间空间开销）
// 使用内联函数的原因：
// 函数调用是有时间和空间开销的：入栈、出栈、跳转等开销。
// 如果函数体代码多，需要较长时间执行，函数调用机制占用的时间可以忽略。
// 但如果函数只有一两条语句，大部分时间都花费在函数调用机制上，开销就不容忽视。

// 宏函数与内联函数的区别：
// 1.宏函数是在预处理期间进行处理，只是简单的文本替换，在编译之前已经替换好了。
// 2.内联函数在编译进行处理，具备普通函数的相应功能 参数检查 类型检查..

// 注意事项：
// 1、函数体不能太庞大，5行以下。
// 2、不能有循环语句。
// 3、不能有复杂的条件判断语句。
// 4、不能对内联函数进行取地址操作， 因为编译完后的程序中不存在函数体。
// 5、内联是一种请求，不一定成功。

// 12,================================================================
// int func(int x) {
//     return 2 == x ? 1 : x + func(x - 2); // ==的优先级高于三目运算符，该表达式等价于 (2 == x) ? 1 : (x + func(x - 2))
// }

// int main()
// {
//     int a = func(10);
//     cout << "a = " << a << endl;

//     return 0;
// }

// 13,================================================================
// 对以下数据结构中data的处理方式描述正确的是(C)
// struct Node
// {
//    int size;
//    char data[0]; // 柔性数组
// };

// A. data将会被编译成一个char *类型指针
// B. 全部描述都不正确
// C. 编译器会认为这就是一个长度为0的数组,而且会支持对于数组data的越界访问
// D. 编译器会默认将数组data的长度设置为1

// 解释：
// 1、什么是柔性数组？

// 柔性数组既数组大小待定的数组， C语言中结构体的最后一个元素可以是大小未知的数组，也就是所谓的0长度，所以我们可以用结构体来创建柔性数组。

// 2、柔性数组有什么用途 ？

// 它的主要用途是为了满足需要变长度的结构体，为了解决使用数组时内存的冗余和数组的越界问题。

// 3、用法 ：在一个结构体的最后 ，申明一个长度为空的数组，就可以使得这个结构体是可变长的。对于编译器来说，此时长度为0的数组并不占用空间，因为数组名

// 本身不占空间，它只是一个偏移量， 数组名这个符号本身代 表了一个不可修改的地址常量 （注意：数组名永远都不会是指针！ ），但对于这个数组的大小，我们

// 可以进行动态分配,对于编译器而言，数组名仅仅是一个符号，它不会占用任何空间，它在结构体中，只是代表了一个偏移量，代表一个不可修改的地址常量！

// 对于柔性数组的这个特点，很容易构造出变成结构体，如缓冲区，数据包等等：

// 14,================================================================
// 能用友元函数重载的运算符是（A）？
// A. +
// B. =
// C. []
// D. ->

// 解释：
// C++规定=，[ ]，()，->这四个运算符只能被重载为类的非静态成员函数，其他的可以被友元重载，主要是因为其他的运算符重载函数都会根据参数类型或数目进行精确匹配，这四个不具有这种检查的功能，用友元定义就会出错

// 15,================================================================
// 多态类中的虚函数表建立在（编译阶段）
// 是在编译时创建的的虚函数表，编译器对每个包含虚函数的类创建一个虚函数表(vtable)，在vtable中，放置这个类的虚函数地址。编译器另外还为每个特定类的对象提供了一个虚表指针（即vptr），这个指针指向了对象所属类的虚表。
// 在程序运行时，根据对象的类型去初始化vptr，从而让vptr正确的指向所属类的虚表，从而在调用虚函数时，就能够找到正确的函数

// 16,================================================================

// int main()
// {
//     if('\0' == 0)putchar('X');
//     if('\0' == 0)putchar('Y');
//     if('a' > 'b')putchar('Z');

//     printf("\n");
// }

// 解析：
// ‘\0’是空字符，ASCII码值为0
// 'a' ASCII码值为97
// 'b' ASCII码值为98
// "\0" 表示的是字符串

// 17,================================================================

// class A
// {
// public:
//     A()
//     {
//         printf("1");
//     }
//     A(A &a)
//     {
//         printf("2");
//     }
//     A &operator=(const A &a)
//     {
//         printf("3");
//         return *this;
//     }
// };
// int main()
// {
//     A a;
//     A b = a; // 输出12
// }

// 解析：
// A a,定义一个对象，毫无疑问调用构造函数
// A b=a，这是定义了对象b，且以a对b进行初始化，这个时候需要调用拷贝构造函数。
// 如果写成A a；A b；b=a；则是调用后面重载的赋值函数，这种情况应该输出113。
// 这个题主要考察赋值和初始化的区别。

// 18,================================================================
// 在 gcc 环境下，已知数组 int arr[5]={1,2,3,4,5}; 则 *(*(&arr+1)-1) 的结果为 （5）

// 解析：
// &是取地址符， &arr代表整个数组，它的步长是整个数组所占的字节数， &arr的类型是 int （ * ） [5] ，所以 &arr+1 指向数组 arr 最后一个元素的下一个地址， *(&arr+1)-1 则是指向 arr 最后的元素，所以 *(*(&arr+1)-1) 的值是 5

// 19,================================================================
