//it is just a test
//learning Git
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
char ID[][10] = 
{
	"abc", "cda", "dehgggv", "abc", "abc",
	"bcd", "abc", "abc", "abc", "abc"
};

char * findID(char (*id)[10], int n)
{
	char *candidate = NULL;
	int times = 0;
	for(int i = 0; i< n; i++)
	{
		if(times == 0)
			candidate = *(id+i);
		else
		{
			if(strcmp(candidate, *(id+i)) == 0)
				times ++;
			else
				times --;
		}
	}
	return candidate;
}

int main()
{
	char * res = findID(ID, 10);
	cout<<res<<endl;
	system("pause");
	return 0;
}