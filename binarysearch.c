#include<stdio.h>
int bsearch(int arr[],int ele,int n1,int n2)
{
int mid=(n1+n2)/2;
if(n1>n2)
   return -1;
if(arr[mid]==ele)
	return mid;
if(arr[mid]<ele)
 	bsearch(arr,ele,mid+1,n2);
else
	bsearch(arr,ele,n1,mid-1);

}


main()
{
int arr[]={1,2,3,5,6,89,98,56,45,458};
int ele,n1=0,n2=sizeof(arr)/sizeof(arr[0]);
printf("%d",n2);
printf("enter the searching element:\n");
scanf("%d",&ele);
printf("element postion is %d",bsearch(arr,ele,n1,n2-1));

}
