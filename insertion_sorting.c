
#include<stdio.h>
#define MAX 500
#ifdef inc
 #define x (arr[j]>temp)
#else
 #define x (arr[j]<temp)
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

for(i=1;i<n;i++)
{
temp=arr[i];
j=i-1;
while(j>=0 && x)
{
arr[j+1]=arr[j];j--;
	count++;//break;
}
arr[j+1]=temp;
}


printf("\n");
for(i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
printf("\n%d",count);
}

