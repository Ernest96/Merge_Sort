#include <stdio.h>

void Merge(int*,int,int*,int,int*);
void Merge_sort(int*,int);
int i,j=0;

int main()
{
	int n,A[40];

	printf("Introdu marimea tabloului:");
	scanf("%d",&n);

	printf("Introdu elementele:");
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);

	printf("\r\n Tabloul nesortat : ");
	for(i=0;i<n;i++)
	printf("%d ",A[i]);

	Merge_sort(A,n);

	printf("Tabloul sortat: ");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);

}


void Merge_sort(int A[],int n)
{
	int mid;
	mid=n/2;
	int left[mid] , right[n-mid];

	if(n<2) return;

	for(i=0;i<mid;i++)
		left[i]=A[i];

	for(i=0;i<n;i++)
		right[i-mid]=A[i];

	Merge_sort(left,mid);
	Merge_sort(right,n-mid);
	Merge(left,mid,right,n-mid,A);

}

void Merge(int L[],int nl,int R[],int nr, int A[] )
{
	i=0;
	j=0;
	int k=0;
	while(i<nl && j<nr)
	{
		if(L[i]<=R[j])
		A[k]=L[i++];

		else
		A[k]=R[j++];

		k++;
	}

	while (i<nl)
		A[k++]=L[i++];
	while(j<nr)
		A[k++]=R[j++];

}