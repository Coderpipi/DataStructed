#ifndef _SEQUENCETABLE_H_
#define _SEQUENCETABLE_H_
#define MAXSIZE 50

using namespace std;
typedef int ElemType; // 定义数据元素的类型
typedef struct        // 定义顺序表结构体
{
    ElemType data[MAXSIZE];
    int length;
} SqList;
// 建立顺序表
void createList(SqList *&, ElemType[], int);
// 初始化线性表
void InitList(SqList *&);
// 销毁线性表
void DestoryList(SqList *&);
// 判断线性表是否为空
bool ListIsEmpty(SqList *&);
// 求线性表的长度
int ListLength(SqList *&);
// 输出线性表
void DispList(SqList *&);
// 求线性表中的某个数据元素值
bool GetElem(SqList *&, int, ElemType &);
// 按元素查找其索引
int LocateElem(SqList *&, ElemType);
// 插入数据元素
bool ListInsert(SqList *&, int, ElemType);
// 删除数据元素
bool ListDelete(SqList *&, int, ElemType &);
// 设计一个算法, 删除书序表中的所有值为x的元素
// 方法1. 使用原空间, 当扫到不是x的元素时插入顺序表中, 用k记录删除的个数,最后长度-k
void delnode1(SqList *&, ElemType);
// 方法2. 遍历顺序表 ,当=x时, k + 1, 当!=x时,将该元素往前移k个位置
void delnode2(SqList *&, ElemType);
// 设计一个高效的算法, 以某一元素为基准, 大于它的元素移动到它后面, 小于它的元素移动到它前面
void partitional(SqList *&);
#endif