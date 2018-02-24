/*
 * @filename:    二进制中1的个数.cpp
 * @author:      Tanswer
 * @date:        2018年02月24日 17:22:44
 * @description:
 */

#include<iostream>
using namespace std;

// 会死循环，当输入负数的时候 右移运算符所致
int Solution1(int n)
{
    int count = 0;
    while(n)
    {
        if(n & 1)
            count++;

        n = n >> 1;
    }

    return count;
}

// 避免死循环，循环次数等于整数二进制的位数
int Solution2(int n)
{
    unsigned int flag = 1;
    int count = 0;
    while(flag)
    {
        if(n & flag)
            count++;

        flag = flag << 1;
    }

    return count;
}

// 有几个1就只需要循环几次
// 把一个整数减去1,再和原整数做与运算
// 会把整数最右边一个1变成0
int Solution3(int n)
{
    int count = 0;

    while(n)
    {
        ++count;
        n = n & (n-1);
    }

    return count;
}

int main()
{
    int num;
    cin >> num;
    // cout << Solution1(num) << endl;
    cout << Solution2(num) << endl;
    cout << Solution3(num) << endl;

    return 0;
}
