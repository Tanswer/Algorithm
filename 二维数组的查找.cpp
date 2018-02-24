/*
 * @filename:    二维数组的查找.cpp
 * @author:      Tanswer
 * @date:        2018年02月23日 17:25:11
 * @description:
 */

#include<iostream>
using namespace std;


/*
 * 从右上角的元素开始判断
 * 如果待查找元素等于该元素，就返回 true
 * 如果待查找元素小于该元素，排除该元素所在行
 * 如果待查找元素大于该元素，派出该元素所在列
 * 直到找到或者范围为空
 * 
 * 二维数组在内存中占据连续空间，从上到小 从左到右存储
 */
bool Find(int* matrix, int rows, int cols, int num)
{
    bool res = false;

    if(matrix != NULL && rows > 0 && cols > 0){
        int row = 0;
        int col = cols - 1;
        while(row < rows && col > 0){
            if(matrix[row*cols + col] == num){
                res = true;
                break;
            }
            else if(matrix[row*cols + col] > num){
                col--;
            }
            else
                row++;
        }
    }
    return res;
}


