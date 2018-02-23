/*
 * @filename:    Singleton_1.cpp
 * @author:      Tanswer
 * @date:        2018年02月23日 15:59:27
 * @description: 只适用于单线程环境
 */

#include<iostream>
using namespace std;

class Singleton
{
public:
    static Singleton* GetInstance()
    {
        if(m_pInstance == NULL)
        {
            m_pInstance = new Singleton();
        }
        return m_pInstance;
    }

private:
    Singleton();
    static Singleton* m_pInstance;
};
