/**
+++++++++++++++++++++++++++++++++++++
| FILENAME: fib.cc                             
|                                          
| FILETYPE: CPP                          
|             
| DESCRIPTION: 求斐波那契数列的第n项
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
+++++++++++++++++++++++++++++++++++++
*/
#include "fib.h"

int fib(int n) {
    if (n == 1 || n == 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}