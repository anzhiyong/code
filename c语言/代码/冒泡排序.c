#include <stdio.h>
void bubble_sort(int arr[],int sz)
{
	int i,k;
	for(i=0;i<sz;i++)
	{
		int j=0;
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j])
			{
				k=arr[i];
				arr[i]=arr[j];
				arr[j]=k;
			}
		}
	}
}
int main()
{
	int arr[10] = { 3,1,7,5,8,9,0,2,4,6 };
	int sz=sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,sz);
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
}
