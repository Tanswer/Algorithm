/*
 * @filename:    旋转数组的最小数字.cpp
 * @author:      Tanswer
 * @description:
 */

#include <iostream>
#include <stdexcept>
using namespace std;

int sortInOreder(int* numbers, int index1, int index2)
{
    int res = numbers[index1];
    for(int i = index1+1; i<=index2; i++)
    {
        if(res > numbers[i])
            res = numbers[i];
    }
    return res;
}

int Min(int* numbers, int length)
{
    logic_error ex("Error.");
    if(numbers == NULL || length <= 0)
        throw exception(ex);

    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;

    while(numbers[index1] >= numbers[index2])
    {
        if(index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2)/2;
        
        // 如果下标为index1 index2 indexMid 指向的数字相等
        // 就没办法判断中间的数字是位于前面的子数组中还是后面的子数组中
        // 也就没办法移动两个指针来缩小查找的范围
        if(numbers[index1] == numbers[index2]
                && numbers[indexMid] == numbers[index1])
        {
            return sortInOreder(numbers,index1, index2);
        }

        if(numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if(numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
    }
    return numbers[indexMid];
}


int main()
{
    int nums1[5] = { 1,0,1,1,1 };
    int nums2[5] = { 3,4,5,1,2 };
    int nums3[1] = { 3 };
    int *nums4 = NULL;

    cout << "{1,0,1,1,1} " << Min(nums1,5) << endl;    
    cout << "{3,4,5,1,2} " << Min(nums2,5) << endl;    
    cout << "{3} " << Min(nums3,1) << endl;    
    cout << "NULL " << Min(nums4,1) << endl;    
    
    return 0;
}
