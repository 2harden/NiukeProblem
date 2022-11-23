// 互斥量mutex
// 1.lock(),unlock()
// 2.lock_guard

// 运行代码：cmake ../;make;.\Thread.exe

#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>    // std::mutex
#include <list>
using namespace std;

class A
{
public:
    void ListPush();
    void ListPop();
    bool ListPopMsgProc(int &command);

private:
    list<int> li;
    mutex mut;
};

void A::ListPush()
{
    for (int i = 0; i < 100; i++)
    {
        lock_guard<mutex> lg(mut);
        // mut.lock();
        li.push_back(i);
        // mut.unlock();
    }
    cout << "ListPush() has been called,thread id is: " << this_thread::get_id() << endl;

    return;
}

bool A::ListPopMsgProc(int &command)
{
    lock_guard<mutex> lg(mut);
    // mut.lock();
    if (!li.empty())
    {
        int command = li.front(); // 返回第一个元素，但不检查元素是否存在
        li.pop_front(); // 移除第一个元素，但不返回
        // mut.unlock();

        return true;
    }
    // mut.unlock();

    return false;
}

void A::ListPop()
{
    int command = 0;
    for (int i = 0; i < 100; i++)
    {
        command = ListPopMsgProc(i);
        if (command)
        {
            cout << "ListPop() command is called,command is " << command << endl;
        }
        else
        {

        }
    }
    // mut.unlock();

    return;
}

int main()
{
    A a;
    thread th1(&A::ListPush, &a); // 第二个参数是引用，才能保证线程里用的同一个对象
    thread th2(&A::ListPop, &a);
    th1.join();
    th2.join();

    cout << "main() is end..." << endl;

    return 0;
}