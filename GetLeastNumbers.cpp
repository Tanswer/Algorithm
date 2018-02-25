/*
 * @filename:    GetLeastNumbers.cpp
 * @author:      Tanswer
 * @description:
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include "Partition.h"
using namespace std;


// 解法一 O(n)
void GetLeastNumbers_1(int* input, int n, int* output,int k)
{
    if(input == NULL || output == NULL || k > n || k <= 0)
        return ;
        
    int start = 0;
    int end = n-1;

    int index = Partition(input, n,  start, end);

    while(index != k-1)
    {
        if(index > k-1)
        {
            end = index - 1;
            index = Partition(input, n, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }

    for(int i = 0; i<n; i++)
        output[i] = input[i];
}


// 解法二 o(nlogk)
typedef multiset<int, greater<int>> intset;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastNumbers_2(const vector<int>& data, intset& leastNumbers, size_t k)
{
    leastNumbers.clear();

    if(k < 1 || data.size() < k)
        return ;

    vector<int>::const_iterator iter = data.begin();
    for(; iter!=data.end(); iter++)
    {
        if(leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else
        {
            setIterator iterGreatest = leastNumbers.begin();

            if(*iter < *iterGreatest)
            {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}

int main()
{
    vector<int> input = {4,5,1,6,2,7,3,8};
    multiset<int, greater<int> >output;
    GetLeastNumbers_2(input, output, 4);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
