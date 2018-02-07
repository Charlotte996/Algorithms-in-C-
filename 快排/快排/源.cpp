#include<iostream>
using namespace std;

void swap(int &a, int &b) 
{
	if (a == b)
		return;
	a = a + b;
	b = a - b;
	a = a - b;
}

void print(int *p, int length) 
{
	for (int i = 0; i < length; i++)
	{
		cout << p[i] << "";
	}
}

int getPartion(int *arry, int high, int low) 
{
	int key = arry[low];
	while (low < high)
	{
		while (low < high && arry[high] >= key)
			high--;
		swap(arry[low], arry[high]);
		while (low < high && arry[low] <= key)
			low++;
		swap(arry[low], arry[high]);
	}
	return low;
}

void quitSort(int *buf, int low, int high) 
{
	if (low < high) 
	{
		int key = getPartion(buf, high, low);

		quitSort(buf, low, key - 1);
		quitSort(buf, key + 1, high);
	}
}

int main() 
{
	int arry[12] = { 23,25,45,78,69,82,47,33,44,2,66,99 };
	int n = sizeof(arry) / sizeof(int);
	cout << "ÅÅÐòÇ°:" << endl;
	for (int i = 0; i < n; i++)
		cout << arry[i] << " ";
	cout << endl;

	cout << "ÅÅÐòºó:" << endl;
	quitSort(arry, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arry[i] << " ";
	cout << endl;
	getchar();

	return 0;
}