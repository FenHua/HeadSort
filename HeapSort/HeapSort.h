#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
//仿函数解决升序和降序代码复用
template<class T>struct SortUp
{
	//升序
	bool operator()(const T&l, const T&r)
	{
		return l < r;
	}
};
template<class T>struct SortDown
{
	//降序
	bool operator()(const T&l, const T&r)
	{
		return l>r;
	}
};
//利用仿函数的特性解决代码的复用性，默认升序排列

template<class T, class Compare = SortUp<T>>class HeapSort
{
public:
	void Sort(int a[], int size)
	{
		assert(a);
		//先建一个堆，从倒数第一非叶子结点开始调整
		for (int i = (size - 2) / 2; i >= 0; i--)
		{
			_AdjustHeap(a, size, i);
		}
		int end = size - 1;
		while (end > 0)
		{
			swap(a[0], a[end]);
			_AdjustHeap(a, end, 0);
			end--;
		}
	}
	void Display(int a[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
protected:
	void _AdjustHeap(int a[], int size, int root)
	{
		int parent = root;
		int child = 2 * parent + 1;
		while (child < size)
		{
			Compare com;
			if (child + 1 < size && com(a[child], a[child + 1]))
			{
				child++;
			}
			if (com(a[parent], a[child]))
			{
				swap(a[child], a[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}
};
