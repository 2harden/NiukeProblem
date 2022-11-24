#include <iostream>
#include <string>
using namespace std;

// int main()
// {
//     int a = 5 / 10;
//     cout << "a = " << a << endl;  // output: a = 0

//     return 0;
// }

int main()
{
    string str = "abcdefff";
    for (int i = 0; i < str.length(); i++)
    {
        cout << "str[] = " << str[i] << '\t'; // output: str[] = a       str[] = b       str[] = c       str[] = d       str[] = e       str[] = f       str[] = f       str[] = f
    }

    return 0;
}