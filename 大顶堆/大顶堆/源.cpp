#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void adjust(int arry[], int len, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int maxIdx = index;
	if (left<len && arry[left]>arry[maxIdx])
		maxIdx = left;
	else if (right<len && arry[right]>arry[maxIdx])
		maxIdx = right;
	if (maxIdx != index)                                      // 如果maxIdx的值有更新
	{
		swap(arry[maxIdx], arry[index]);
		adjust(arry, len, maxIdx);                            // 递归调整其他不满足堆性质的部分
	}
}

void heapSort(int arry[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(arry, size, i);                                // 对每一个非叶结点进行堆调整(从最后一个非叶结点开始)
	}
	for (int i = size / 2 - 1; i >= 1; i--) 
	{
		swap(arry[0], arry[i]);                               // 将当前最大的放置到数组末尾
		adjust(arry, i, 0);                                   // 将未完成排序的部分继续进行堆排序
	}
}

int main() 
{
	int arry[8] = { 2,5,8,9,45,12,48,36 };
	heapSort(arry, 8);
	for (auto it : arry)
	{
		cout << it << endl;
	}
	cin.get();
	return 0;
}