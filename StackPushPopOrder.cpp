/*
 * @filename:    StackPushPopOrder.cpp
 * @author:      Tanswer
 * @date:        2018年02月25日 14:18:06
 * @description:
 */

#include <iostream>
#include <stack>
using namespace std;


bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
    bool bPossible = false;

    if(pPush != NULL && pPop != NULL && nLength != 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;

        stack<int> dataStack;

        // 遍历判断输出序列
        while(pNextPop - pPop < nLength)
        {
            // 
            while(dataStack.empty() || dataStack.top() != *pNextPop)
            {
                // 所有数字都压栈了
                if(pNextPush - pPush == nLength)
                    break;

                dataStack.push(*pNextPush);
                pNextPush++;
            }

            if(dataStack.top() != *pNextPop)
                break;

            dataStack.pop();
            pNextPop++;
        }

        if(dataStack.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}

int main()
{
    int push[5] = {1,2,3,4,5};
    int pop1[5] = {4,5,3,2,1};
    int pop2[5] = {4,3,5,1,2};

    cout << IsPopOrder(push,pop1,5) << endl;
    cout << IsPopOrder(push,pop2,5) << endl;
    return 0;
}
