
#include<stdio.h>
#define MAX 500
#ifdef inc
 #define x (arr[j]>arr[min])
#else
 #define x (arr[j]<arr[min])
#endif

main()
{
int arr[MAX];
int min;
int i=0,j,temp,n,count=0;
printf("No.of elements\n");
scanf("%d",&n);
	
	for(i=0;i<n;i++)
         scanf("%d",&arr[i]);
//n=sizeof(&arr)/sizeof(arr[0]);

for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
count++;
  if(x)
     min=j;
}

if(min!=i)
{
    arr[min]=arr[min]+arr[j];
      arr[j]=arr[min]-arr[j];
    arr[min]=arr[min]-arr[j];
}

}
printf("\n");
for(i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
printf("\n%d",count);
}

