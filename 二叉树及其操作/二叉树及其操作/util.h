#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

template <typename T>
T string2T(string str) 
{
	istringstream in(str);
	T out;
	in >> out;
	return out;
}

template<typename T>
string T2string(T t) 
{
	ostringstream out;
	out << t;
	return out.str();
}

template<typename T,size_t N>
void arry_init(T(&arr)[N], T val) 
{
	for (size_t i = 0; i != N; ++i) 
	{
		arr[i] = val;
	}
}

int max(int a, int b) 
{
	return a > b ? a : b;
}

int min(int a, int b) 
{
	return a < b ? a : b;
}