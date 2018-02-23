/*
 * @filename:    从尾到头输出链表.cpp
 * @author:      Tanswer
 * @description: 用栈实现
 */

#include <iostream>
#include <stack>
using namespace std;

typedef struct ListNode
{
    int         m_data;
    ListNode*   next;
}ListNode;

ListNode* CreateList()
{
    ListNode* head;
    ListNode* node;
    head = (ListNode*)malloc(sizeof(ListNode));
    head -> m_data = 0;
    head -> next = NULL;
    node = head;

    while(1)
    {
        int data;
        cin >> data;
        if(data != 0)
        {
            ListNode *pNew;
            pNew = (ListNode*)malloc(sizeof(ListNode));
            pNew -> m_data = data;
            pNew -> next = NULL;

            node -> next = pNew;
            node = node -> next;
        }
        else
            break;
    }
    return head -> next; // 无头
}

// 栈实现
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    stack<ListNode*> nodes;
    ListNode *c_node = pHead;
    while(c_node != NULL)
    {
        nodes.push(c_node);
        c_node = c_node -> next;
    }

    while(!nodes.empty())
    {
        c_node = nodes.top();
        cout << c_node -> m_data << '\t';
        nodes.pop();
    }
    cout << endl;
}

// 递归实现  结点很多可能会导致函数调用栈溢出
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if(pHead -> next != NULL)
            PrintListReversingly_Recursively(pHead -> next);
        
        cout << pHead->m_data << '\t';
    }
}

int main()
{
    ListNode* head;
    head = CreateList();

    PrintListReversingly_Iteratively(head);
    PrintListReversingly_Recursively(head);
    return 0;
}
