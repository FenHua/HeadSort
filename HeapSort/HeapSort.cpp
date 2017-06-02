// HeapSort.cpp : 定义控制台应用程序的入口点。
//

#include "HeapSort.h"

void test()
{
	int array[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	int size = sizeof(array) / sizeof(array[0]);
	//测试升序
	HeapSort<int, SortUp<int>>hs1;
	hs1.Sort(array, size);
	hs1.Display(array, size);
	//测试升序
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

