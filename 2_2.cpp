#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int lowestOne(int n)
{
	int res = 0;
	while(n)
	{
		n >>= 1;
		res += n;
	}
	return res + 1;
}
int main()
{
	int n = 10;
	int res = 0;
	/*for(int i = 1; i <= n; i++)
	{
		int j = i;
		while(j % 5 == 0)
		{
			res++;
			j /= 5;
		}
	}*/
	/*
	while(n)
	{
		res += n / 5;
		n /= 5;
	}
	*/
	res  = lowestOne(n);
	cout<<res<<endl;
	system("pause");
	return 0;
}