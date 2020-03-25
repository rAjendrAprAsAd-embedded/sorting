/*time complex is (n-1)*(n/2)*/
#include<stdio.h>
#define MAX 500
#ifdef inc
 #define x (arr[j]>arr[j+1])
#else
 #define x (arr[j]<arr[j+1])
#endif

main()
{
int arr[MAX];
int flag;
int i=0,j,temp,n,count=0;
printf("No.of elements\n");
scanf("%d",&n);
	
	for(i=0;i<n;i++)
         scanf("%d",&arr[i]);
//n=sizeof(&arr)/sizeof(arr[0]);

for(i=0;i<n-1;i++)
{
flag=0;
for(j=0;j<n-i-1;j++)
{

count++;
if(x)
  {
    arr[j+1]=arr[j+1]+arr[j];
    arr[j]=arr[j+1]-arr[j];
    arr[j+1]=arr[j+1]-arr[j];
 flag=1;
 }
}

	if(flag==0)
		break;

}
printf("\n");
for(i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
printf("\n%d",count);
}

