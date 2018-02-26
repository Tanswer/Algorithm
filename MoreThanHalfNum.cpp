/*
 * @filename:    MoreThanHalfNum.cpp
 * @author:      Tanswer
 * @date:        2018年02月25日 21:01:24
 * @description:
 */

#include <iostream>
#include "Partition.h"
using namespace std;

bool g_bInputInvalid = false;

bool CheckMoreThanHalf(int* numbers, int length, int result)
{
    int count = 0;
    for(int i=0; i<length; i++)
    {
        if(numbers[i] == result)
            count++;
    }

    bool isMoreThanHalf = true;
    if(count*2 <= length)
    {
        isMoreThanHalf = false;
    }
    return isMoreThanHalf;
}

// 解法一 利用数组的特点
int MoreThanHalfNum_1(int* numbers, int length)
{
    int result = numbers[0];
    int times = 1;

    for(int i=1; i<length; i++)
    {
        if(times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times++;
        else
            times--;
    }

    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;

    return result;
}


// 解法二
int MoreThanHalfNum_2(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
    {
        g_bInputInvalid = true;
        return 0;
    }

    int start = 0;
    int end = length - 1;
    int middle = length >> 1;

    int index = Partition(numbers, length, start,end);
    while(index != middle)
    {
        if(index > middle)
        {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }

    int result = numbers[middle];
    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;

    return result;
}

int main()
{
    int numbers[9] = {1,2,3,2,2,2,5,4,2};

    cout << MoreThanHalfNum_1(numbers,9) << endl;
    cout << MoreThanHalfNum_2(numbers,9) << endl;

    return 0;
}
