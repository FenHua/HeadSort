#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
//�º����������ͽ�����븴��
template<class T>struct SortUp
{
	//����
	bool operator()(const T&l, const T&r)
	{
		return l < r;
	}
};
template<class T>struct SortDown
{
	//����
	bool operator()(const T&l, const T&r)
	{
		return l>r;
	}
};
//���÷º��������Խ������ĸ����ԣ�Ĭ����������

template<class T, class Compare = SortUp<T>>class HeapSort
{
public:
	void Sort(int a[], int size)
	{
		assert(a);
		//�Ƚ�һ���ѣ��ӵ�����һ��Ҷ�ӽ�㿪ʼ����
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
