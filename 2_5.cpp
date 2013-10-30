/*
	编程之美 2_5
	最小堆实现
*/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<time.h>

using namespace std;

const char* File = "test.txt";

int Data[10000];
int heap[11];

int prepareData(const char* fileName)
{
	FILE *file = fopen(fileName, "wb+");
	if(!file)
		return 0;	
	int d ;
	for(long i = 0; i<10000; i++)
	{
		d = rand();
		fprintf(file, "%d ", d);
		if( i && i%100 == 0)
		{
			fprintf(file, "%s", "\n");
		}
	}
	fclose(file);
	return 1;
}

int readData(const char *fileName, int *data, int n)
{
	FILE *file = fopen(File, "r");
	if(!file)
		return 0;	
	for(int i = 0; i < n; i++)
	{
		if(fscanf(file, "%d", &data[i]) == 0)
		{
			fclose(file);
			return 0;
		}
	}
	fclose(file);
	return 1;
}
//min heap
void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void siftUp(int *d, int n)
{
	int i = n;
	while(1)
	{
		if(i == 1)
		{
			break;
		}
		if(d[n] < d[i/2])
		{
			swap(d[n] , d[i/2]);
			i /= 2;
			n = i;
		}
		else
		{
			break ;
		}
	}
}

void siftDown(int *d, int n)
{
	int i = 1;
	int p;
	while(1)
	{
		p = i*2;
		if(p > n)
			break;
		if(p+1 <= n)
		{
			if( d[p+1] < d[p])
				p++;
		}
		if(d[i] <= d[p])
			break;
		swap(d[p], d[i]);
		i = p;
	}
}

int findTopK(const char* fileName, int * h, int k)
{
	FILE *file = fopen(fileName, "r");
	if(!file)
		return 0;
	//build min heap
	fscanf(file, "%d", &h[1]);
	for(int i = 2; i <= k; i++)
	{
		if(fscanf(file, "%d", &h[i]) == 0)
		{
			fclose(file);
			return 0;
		}
		siftUp(h, i);
	}
	int tmp;
	while(!feof(file))
	{
		fscanf(file, "%d", &tmp);
		if(tmp <= h[1])
			continue;
		else
		{
			h[1] = tmp;
			siftDown(h, k);
		}
	}
	fclose(file);
	return 1;
}

int main()
{
	srand((unsigned)time(NULL));
	//Test heap
	/*
	int testData[11] = {2,4,56,4,6,1,56,24,13,84,7};
	
	for(int i = 2; i <= 10 ;i++)
	{
		siftUp(testData, i);
	}
	
	*/
	//prepareData(File);

	//readData(File, Data, 10000);
	findTopK(File, heap, 10);
	for(int i = 10; i >=2 ; i--)
	{
		swap(heap[1], heap[i]);
		siftDown(heap, i-1);
	}
	for(int i = 1; i <= 10; i++)
	{
		cout<<heap[i]<<" ";
	}
	system("pause");
	return 0;
}