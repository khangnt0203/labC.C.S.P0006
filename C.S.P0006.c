#include <stdio.h>
#include <stdlib.h>
#define max 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void input (int* a, int n)
{
	int i;
	for (i=0; i<n ; i++)
	{
		printf("	Enter element [%d]: ",i);
		scanf("%d",&a[i]);
	}
}
int printAsc (int* a, int n)
{
		int** adds= (int**)calloc(n, sizeof(int*));
	int i,j;
	for (i=0; i<n; i++)
		adds[i]=&a[i];
	int* t;
	for (i=0; i<n-1; i++)
		for (j=n-1; j>i;j--)
			if (*adds[j]<*adds[j-1])
			{
				t=adds[j];
				adds[j]=adds[j-1];
				adds[j-1]=t;
			}
	for (i=0;i<n;i++)
	printf("%d ",*adds[i]);
	free(adds);
}
void printDesc (int* a, int n)
{
	int** adds= (int**)calloc(n, sizeof(int*));
	int i,j;
	for (i=0; i<n; i++)
		adds[i]=&a[i];
	int* t;
	for (i=0; i<n-1; i++)
		for (j=n-1; j>i;j--)
			if (*adds[j]>*adds[j-1])
			{
				t=adds[j];
				adds[j]=adds[j-1];
				adds[j-1]=t;
			}
	for (i=0;i<n;i++)
	printf("%d ",*adds[i]);
	free(adds);
}
int main(int argc, char *argv[]) 
{
	int* a;
	int num;
	a=(int*) calloc (num,sizeof(int));
	printf("Please enter size of array: ");
	do
	{
		scanf("%d",&num);
		
	} while (num<0 || num > max);
	printf("\nEnter the array\n");
	input(a,num);
	printf("\nThe array sorted in ascending: ");
	printAsc(a,num);
	printf("\nThe array sorted in descending: ");
	printDesc(a,num);
	return 0;
}
