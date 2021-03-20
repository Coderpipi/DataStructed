/**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| FILENAME: mystring
|
| FILETYPE: CPP
|
| DESCRIPTION: 串的各种操作的实现
|
| AUTHOR: LBW
|
| EMAIL: 2582482991@qq.com
|
| CREATETIME: 2021-03-20
|
| MODIFYTIME: 2021-03-20
|
| VERSION: 1.0-SNAPSHOT
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
#include <cstdio>

#include "mysqstring.h"
void StrAssign(SqString &s, char cstr[]) {
  int i = 0;
  for (i = 0; cstr[i] != '\0'; ++i) {
    s.data[i] = cstr[i];
  }
  s.length = i;
}

void Destory(SqString &s) {}

void StrCpy(SqString dst, SqString &src) {
  for (int i = 0; i < src.length; ++i) {
    dst.data[i] = src.data[i];
  }
  dst.length = src.length;
}

bool Equal(SqString const &str1, SqString const &str2) {
  if (str1.length != str2.length) {
    return false;
  }
  for (int i = 0; i < str1.length; ++i) {
    if (str1.data[i] != str2.data[i]) {
      return false;
    }
  }
  return true;
}

int Length(SqString const &s) { return s.length; }

SqString StrConcat(SqString const &str1, SqString const &str2) {
  SqString res;
  res.length = str1.length + str2.length;
  for (int i = 0; i < str1.length; ++i) {
    res.data[i] = str1.data[i];
  }
  for (int i = 0; i < str2.length; ++i) {
    res.data[str1.length + i] = str2.data[i];
  }

  return res;
}

SqString SubString(SqString const &s, int i, int j) {
  SqString str;
  str.length = 0;
  if (i <= 0 || i > s.length || j < 0 || i + j - 1 > s.length) {
    return str;
  }
  for (int k = i - 1; k < i + j - 1; ++k) {
    str.data[k - i + 1] = s.data[k];
  }
  str.length = j;
  return str;
}

SqString InsertStr(SqString const &s1, int i, SqString const &s2) {
  SqString str;
  str.length = 0;
  if (i <= 0 || i > s1.length - 1) {
    return str;
  }
  for (int j = 0; j < i - 1; ++j) {
    str.data[j] = s1.data[j];  // 将s1.data[0, i - 2] 复制到str
  }
  for (int j = 0; j < s2.length; ++j) {
    str.data[i + j - 1] = s2.data[j];  // 将s2.data[0..s2.length - 1]复制到str
  }
  for (int j = i - 1; j < s1.length; ++j) {
    str.data[s2.length + j] = s1.data[j];
  }
  str.length = s1.length + s2.length;
  return str;
}

SqString DelString(SqString const &s, int i, int j) {
  SqString str;
  str.length = 0;
  if (i <= 0 || i > s.length || i + j > s.length + 1) {
    return str;
  }
  for (int k = 0; k < i - 1; ++k) {
    str.data[k] = s.data[k];
  }
  for (int k = i + j - 1; k < s.length; ++k) {
    str.data[k - j] = s.data[k];
  }
  str.length = s.length - j;
  return str;
}

SqString ReplaceString(SqString const &s, int i, int j, SqString const &t) {
  SqString str;
  str.length = 0;
  if (i <= 0 || i > s.length || i + j - 1 > s.length) {
    return str;
  }
  for (int k = 0; k < i - 1; ++k) {
    str.data[k] = s.data[k];
  }
  for (int k = 0; k < t.length; ++k) {
    str.data[i + k - 1] = t.data[k];
  }
  for (int k = i + j - 1; k < s.length; ++k) {
    str.data[t.length + k - j] = s.data[k];
  }
  str.length = s.length - j + t.length;
  return str;
}

void DispStr(SqString const &s) {
  if (s.length > 0) {
    for (int i = 0; i < s.length; ++i) {
      printf("%c", s.data[i]);
    }
    printf("\n");
  }
}

int StrCmp(SqString const &s1, SqString const &s2) {
  int common_len = s1.length <= s2.length ? s1.length : s2.length;
  for (int i = 0; i < common_len; ++i) {
    if (s1.data[i] > s2.data[i]) {
      return 1;
    } else if (s1.data[i] < s2.data[i]) {
      return -1;
    }
  }
  if (s1.length == s2.length) {
    return 0;
  } else if (s1.length > s2.length) {
    return 1;
  }
  return -1;
}