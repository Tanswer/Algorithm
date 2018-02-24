
/*
 * @filename:    2.2.1_2.cpp
 * @author:      Tanswer
 * @date:        2018年02月23日 13:40:56
 * @description:
 */

#include<iostream>
using namespace std;

class A
{
public:
    A(int n) { value = n; }
    A(A other) { value = other.value; }
    // error 拷贝构造函数的参数必须是引用

    void Print() { cout << value << endl; }
private:
    int value;
};


int main()
{
    A a = 10;
    A b = a;
    b.Print();

    return 0;
}
