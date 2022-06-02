/**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| FILENAME: main
|
| FILETYPE: CPP
|
| DESCRIPTION:  主文件,程序都在这里面调用
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
#include <iostream>

#include "sort.h"

using namespace std;

int main(int argc, const char* argv[]) {
  // RecType a[] = {{6, '6'}, {8, '8'}, {7, '7'}, {9, '9'}, {0, '0'},
  //                {1, '1'}, {3, '3'}, {2, '2'}, {4, '4'}, {5, '5'}};
  // QuickSort(a, 0, 9);
  // for (auto i : a) {
  //   cout << i.key << " " << i.data << endl;
  // }
  int n = 1;
  cout << *(&n) << endl;
  return 0;
}