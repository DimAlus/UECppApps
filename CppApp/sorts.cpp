#include "sorts.h"


/// <summary>
/// Insert sort
/// </summary>
/// <param name="arr">Source array</param>
/// <param name="helper">Destination array</param>
/// <param name="len">Size array</param>
/// <param name="comp">Compare function</param>
void SortMerge_(void** arr, void** helper, int len, tf_Comparer comp, int numb = 0) {
	if (len <= 1) {
		if (numb % 2)
			helper[0] = arr[0];
		return;
	}
	if (len == 2) {
		if (numb % 2) {
			if (comp(arr[0], arr[1])) { helper[0] = arr[0]; helper[1] = arr[1]; }//*/*(unsigned long long*)helper = *(unsigned long long*)arr;
			else { helper[0] = arr[1]; helper[1] = arr[0]; }
		}
		else if (!comp(arr[0], arr[1])) {
			void* v = arr[0];
			arr[0] = arr[1];
			arr[1] = v;
		}
		return;
	}

	int l1 = len / 2, l2 = len - l1;
	SortMerge_(arr, helper, l1, comp, numb + 1);
	SortMerge_(arr + l1, helper + l1, l2, comp, numb + 1);

	void** aFrom = numb % 2 ? arr : helper;
	void** aTo = numb % 2 ? helper : arr;

	int i, j, k;
	for (i = 0, j = l1, k = 0; i < l1 && j < len; k++) {
		if (comp(aFrom[i], aFrom[j]))
			aTo[k] = aFrom[i++];
		else
			aTo[k] = aFrom[j++];
	}
	while (i < l1) aTo[k++] = aFrom[i++];
	while (j < len) aTo[k++] = aFrom[j++];

}
void SortMerge(void** arr, int len, tf_Comparer comp) {
	if (len <= 1) return;
	void** helper = new void* [len];
	SortMerge_(arr, helper, len, comp);
	if (len < 3)
		for (int i = 0; i < len; i++)
			arr[i] = helper[i];
	delete[] helper;
}

void Swap(void** a, void** b) {
	void* c = *a;
	*a = *b;
	*b = c;
}
void SortBub(void** arr, int len, tf_Comparer comp) {
	for (int i = 0, swaps = 1; i < len && swaps > 0; i++) {
		swaps = 0;
		for (int j = 0; j < len - i - 1; j++)
			if (!comp(arr[j], arr[j + 1])) {
				swaps++;
				Swap(&arr[j], &arr[j + 1]);
			}
	}
}

void QuickCombSort(void** arr, int len, tf_Comparer comp) {
	if (len <= 1) return;
	if (len <= 32) {
		SortBub(arr, len, comp);
		return;
	}
	int i = 0, j = len - 1;
	void* el = arr[j];
	while (i < j) {
		while (comp(arr[i], arr[j]) && i < j) i++;
		if (i < j) Swap(&arr[i], &arr[j]);
		while (comp(arr[i], arr[j]) && i < j) j--;
		if (i < j) Swap(&arr[i], &arr[j]);
	}

	if (i > 1) QuickCombSort(arr, i, comp);
	if (i < len - 1) QuickCombSort(arr + i + 1, len - i - 1, comp);
}

void quicksort(void** l, void** r, tf_Comparer comp) {
	if (r - l <= 1) return;
	void* z = *(l + (r - l) / 2);
	void** ll = l, ** rr = r - 1;
	while (ll <= rr) {
		while (!comp(z, *ll)) ll++;
		while (!comp(*rr, z)) rr--;
		if (ll <= rr) {
			Swap(ll, rr);
			ll++;
			rr--;
		}
	}
	if (l < rr) quicksort(l, rr + 1, comp);
	if (ll < r) quicksort(ll, r, comp);
}
void quickbubsort(void** l, void** r, tf_Comparer comp) {
	if (r - l <= 32) {
		SortBub(l, r - l, comp);
		return;
	}
	void* z = *(l + (r - l) / 2);
	void** ll = l, ** rr = r - 1;
	while (ll <= rr) {
		while (!comp(z, *ll)) ll++;
		while (!comp(*rr, z)) rr--;
		if (ll <= rr) {
			Swap(ll, rr);
			ll++;
			rr--;
		}
	}
	if (l < rr) quicksort(l, rr + 1, comp);
	if (ll < r) quicksort(ll, r, comp);
}
void QuicklySort(void** arr, int len, tf_Comparer comp) {
	quicksort(arr, arr + len, comp);
}
void QuicklyBubleSort(void** arr, int len, tf_Comparer comp) {
	quickbubsort(arr, arr + len, comp);
}

void QuickSort(void** arr, int len, tf_Comparer comp) {
	if (len <= 1) return;

	int i = 0, j = len - 1;
	void* el = arr[j];
	while (i < j) {
		while (comp(arr[i], arr[j]) && i < j) i++;
		if (i < j) Swap(&arr[i], &arr[j]);
		while (comp(arr[i], arr[j]) && i < j) j--;
		if (i < j) Swap(&arr[i], &arr[j]);
	}

	if (i > 1) QuickSort(arr, i, comp);
	if (i < len - 1) QuickSort(arr + i + 1, len - i - 1, comp);
}

bool Check(void** arr, int len, tf_Comparer comp) {
	for (int i = 0; i < len - 1; i++)
		if (!comp(arr[i], arr[i + 1]))
			return false;
	return true;
}

