#ifndef __SORTS__
#define __SORTS__

#include "library.h"


typedef bool (*tf_Comparer)(void*, void*);
void SortMerge(void** arr, int len, tf_Comparer comp);
void SortBub(void** arr, int len, tf_Comparer comp);
void QuickCombSort(void** arr, int len, tf_Comparer comp);
void QuicklySort(void** arr, int len, tf_Comparer comp);
void QuicklyBubleSort(void** arr, int len, tf_Comparer comp);
bool Check(void** arr, int len, tf_Comparer comp);

#endif // !__SORTS__

