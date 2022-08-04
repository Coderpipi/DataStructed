#include <iostream>
#include "sort.h"

using namespace std;

/**
 * @author lbw <2582482991@qq.com>
 * @date 2022年08月04日15:25:56
 * @version 1.0
 * main 主方法,所有功能都在这里调用
 */
int main(int argc, const char *argv[]) {
    RecType a[] = {{6, '6'},
                   {8, '8'},
                   {7, '7'},
                   {9, '9'},
                   {0, '0'},
                   {1, '1'},
                   {3, '3'},
                   {2, '2'},
                   {4, '4'},
                   {5, '5'}};
    QuickSort(a, 0, 9);
    for (auto i: a) {
        cout << i.key << " " << i.data << endl;
    }
}