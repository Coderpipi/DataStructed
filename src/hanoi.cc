/**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| FILENAME: hanoi                             
|                                          
| FILETYPE: CPP                          
|                                          
| DESCRIPTION: 求解汉诺塔问题                        
|                                          
| AUTHOR: LBW                            
|                                          
| EMAIL: 2582482991qq.com             
|                                           
| CREATETIME:                           
|                                          
| MODIFYTIME:                           
|                                          
| VERSION: 1.0-SNAPSHOT                
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
#include <cstdio>
#include "hanoi.h"
void Hanoi(int n, char X, char Y, char Z)
{
    if (n == 1)
    {
        printf("\t将第%d个盘片从%c移动到%c\n", n, X, Z);
    }
    else
    {
        Hanoi(n - 1, X, Z, Y);
        printf("\t将第%d个盘片从%c移动到%c\n", n, X, Z);
        Hanoi(n - 1, Y, X, Z);
    }
}