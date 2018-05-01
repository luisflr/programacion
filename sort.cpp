#include<iostream>
#include "sort1.h"
#include <stdio.h>
#include <time.h>
#define N 10000
using namespace std;

void fill_random(int *a, int n)
{
	for (int i=0;i<N;i++)
	{
		*(a+i)=rand()%n;
	}
}

int main()
{	
	int *A=new int[N];
	sort<int>*array[5]={new insert<int>,new bubble<int>,new shell<int> , new merge<int>,new quick<int>};
	float time;
	for (int n=10; n<=N; n*=10)
	{
		cout<<n;
		fill_random(A,n);
		for(int i=0;i<5;i++)
		{
			time=clock();
			array[i]->type_sort(A,n);
			time=clock()-time;
			cout<<" "<<time;
		}
		cout << endl; 
	}
	
	return 0;
	
}

