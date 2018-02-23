/*
 * @filename:    CMyString.cpp
 * @author:      Tanswer
 * @date:        2018年02月23日 13:47:46
 * @description:
 */

#include <iostream>
#include <cstring>
using namespace std;

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator=(const CMyString& str);
private:
    char* m_pData;
};

CMyString& CMyString::operator=(const CMyString& str)
{
    // 检测自我赋值
    if(&str == this)
        return *this;

    delete [] m_pData;  // 释放实例自身已有内存
    m_pData = NULL;
    m_pData = new char [ strlen(str.m_pData) + 1 ]; // 申请空间
    strcpy(m_pData,str.m_pData);    // 复制

    return *this;   // 返回引用，允许连续赋值
}

/* 
 * 考虑异常安全性的解法
 * 如果delete 后 内存不足导致 new char 抛出异常
 *
CMyString& CMyString::operator=(const CMyString& str)
{
    if(this != &str)
    {
        CMyString strTemp(str);
        char *pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }

    return *this;
}
*/
    
CMyString::CMyString(char* pData) // 实现的时候不用写默认值
{
    if(pData == NULL)
    {
        m_pData = new char[1];
        *m_pData = '\0';
    } else {
        m_pData = new char [ strlen(pData)+1 ];
        strcpy(m_pData,pData);    // 复制
    }
}

// 拷贝构造，参数必须为引用
CMyString::CMyString(const CMyString& str)
{
    if(str.m_pData == NULL)
    {
        m_pData = new char[1];
        *m_pData = '\0';
    } else {
       m_pData = new char [ strlen(str.m_pData)+1 ];
       strcpy(m_pData, str.m_pData);
    }
}

CMyString::~CMyString()
{
    if(m_pData != NULL)
    {
        delete [] m_pData;
    }
}

