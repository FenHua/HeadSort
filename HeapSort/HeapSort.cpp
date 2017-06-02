// HeapSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "HeapSort.h"

void test()
{
	int array[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	int size = sizeof(array) / sizeof(array[0]);
	//��������
	HeapSort<int, SortUp<int>>hs1;
	hs1.Sort(array, size);
	hs1.Display(array, size);
	//��������
	HeapSort<int, SortDown<int>>hs2;
	hs2.Sort(array, size);
	hs2.Display(array, size);
}
int main()
{
	test();
	system("pause");
	return 0;
}

