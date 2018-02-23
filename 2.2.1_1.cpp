/*
 * @filename:    2.2.1.cpp
 * @author:      Tanswer
 * @date:        2018年02月23日 13:30:25
 * @description:
 */

#include<iostream>
using namespace std;

class Test{
    
    Test();
    virtual ~Test();

};

int main()
{
    cout << sizeof(Test) << endl;
    

    return 0;
}
