// 简单工程模式(又叫静态工程模式)

#include <iostream>

using namespace std;

class Product
{
public:
    virtual void show() = 0;
};

class Product_A : public Product
{
public:
    void show()
    {
        cout << "Product_A" << endl;
    }
};

class Product_B : public Product
{
public:
    void show()
    {
        cout << "Product_B" << endl;
    }
};

class Factory
{
public:
    Product* Create(int i) // 指针函数: 返回值是指针的函数
    {
        switch (i)
        {
            case 1:
                return new Product_A;
                break;
            case 2:
                return new Product_B;
                break;
            default:
                break;
        }
    }
};

int main()
{
    Factory *factory = new Factory();
    factory->Create(1)->show();
    factory->Create(2)->show();

    return 0;
}