/*
 * @filename:    替换空格.cpp
 * @author:      Tanswer
 * @description:
 */

#include<iostream>
using namespace std;

/*
 * @string:字符数组
 * @length:总容量
 */
bool ReplaceBlank(char string[], int length)
{
    if(string == NULL || length <=0 )
        return false;

    int oldLength = 0;
    int numOfBlank = 0;
    int i = 0;
    while(string[i] != '\0'){
        oldLength++;
        if(string[i] == ' ')
            numOfBlank++;

        i++;
    }
   
    int newLength = oldLength + numOfBlank * 2;
    if(newLength > length)
        return false;
  
    cout << newLength << "   old  " << oldLength << endl;
    int oldIndex = oldLength;
    int newIndex = newLength;
    while(oldIndex != newIndex){
        if(string[oldIndex] == ' ')
        {
            cout << "lalala" << endl;
            string[newIndex--] = '0';
            string[newIndex--] = '2';
            string[newIndex--] = '%';
        }
        else
        {
            string[newIndex--] = string[oldIndex];
        }
        
        oldIndex--;
    }
    return true;
}

int main()
{
    char str[50] = " we are happy.";
    char *str1 = NULL;
    char str2[20] = "   ";

    ReplaceBlank(str, 50);
    ReplaceBlank(str1, 50);
    
    cout << ReplaceBlank(str2, 20) << endl;;
    
    cout << str << endl;
    cout << str1 << endl;
    cout << str2 << endl;

    return 0;
}
