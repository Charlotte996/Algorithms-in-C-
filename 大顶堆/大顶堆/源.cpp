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
	if (maxIdx != index)                                      // ���maxIdx��ֵ�и���
	{
		swap(arry[maxIdx], arry[index]);
		adjust(arry, len, maxIdx);                            // �ݹ������������������ʵĲ���
	}
}

void heapSort(int arry[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(arry, size, i);                                // ��ÿһ����Ҷ�����жѵ���(�����һ����Ҷ��㿪ʼ)
	}
	for (int i = size / 2 - 1; i >= 1; i--) 
	{
		swap(arry[0], arry[i]);                               // ����ǰ���ķ��õ�����ĩβ
		adjust(arry, i, 0);                                   // ��δ�������Ĳ��ּ������ж�����
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