#ifndef _MYSQSTRING_H
#define _MYSQSTRING_H
#define MAX_SIZE 50
typedef struct {
    char data[MAX_SIZE];
    int length;
} SqString;

// 1.生成串
void StrAssign(SqString &, char[]);

// 2.销毁串
void DestoryStr(SqString &);

// 3.串的复制
void StrCpy(SqString, SqString &);

// 4.判断字符串相等
bool Equal(SqString const &, SqString const &);

// 5.求字符串的长度
int Length(SqString const &);

// 6.串的拼接
SqString StrConcat(SqString const &, SqString const &);

// 7.求子串
SqString SubString(SqString const &, int, int);

// 8.子串的插入
SqString InsertStr(SqString const &, int, SqString const &);

// 9.子串的删除
SqString DelString(SqString const &, int, int);

// 10.子串的替换
SqString ReplaceString(SqString const &, int, int, SqString const &);

// 11.输出串
void DispStr(SqString const &);

// 12.比较字符串的大小(按照字典序比较)
int StrCmp(SqString const &, SqString const &);

// 串的匹配算法(Brute-Force)
int BF(SqString, SqString);

// 得到KMP算法中的next数组
void GetNext(SqString, int[]);

// 串的匹配算法(KMP算法)
int KMPIndex(SqString, SqString);

// 得到改进的KMP算法中的nextval数组
void GetNextVal(SqString, int[]);

// 改进的KMP算法
int BetterKMP(SqString, SqString);

#endif