#include<stdio.h>
int lsearch(int arr[],int ele,int n)
{
int i;

for(i=0;i<n;i++)
{
     if(arr[i]==ele)
	return i;
}

 return -1;

}
main()
{
int arr[]={1,2,3,5,6,89,98,56,45,458};
int ele,n=sizeof(arr)/sizeof(arr[0]);
printf("%d",n);
printf("enter the searching element:\n");
scanf("%d",&ele);
printf("element postion is %d",lsearch(arr,ele,n));

}
