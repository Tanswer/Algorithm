/*
 * @filename:    FindNumsAppearOnce.cpp
 * @author:      Tanswer
 * @description:
 */

#include<iostream>
using namespace std;


bool IsBit1(int num, unsigned int indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}

unsigned int FindFirstBitIs1(int num)
{
    unsigned int indexBit = 0;

    while(((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
    {
        ++indexBit;
        num = num >> 1;
    }
    return indexBit;
}

void FindNumsAppearOnce(int* data, int length, int* num1, int* num2)
{
    int resultExclusiveOR = 0;
    for(int i=0; i<length; i++)
        resultExclusiveOR ^= data[i];

    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

    *num1 = *num2 = 0;
    for(int i=0; i<length; i++)
    {
        if(IsBit1(data[i],indexOf1))
            *num1 ^= data[i];
        else
            *num2 ^= data[i];
    }
}

int main()
{
    int num1, num2;
    int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };

    FindNumsAppearOnce(data, 8, &num1, &num2);

    cout << num1 << " " << num2 << endl;

    return 0;
}
