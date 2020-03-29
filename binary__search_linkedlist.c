
# include <stdio.h>
# include <stdlib.h>
struct list
{
 int data;
 struct list *next;
};
typedef struct list node;
node *first;

node* middle(node *start,node *end)
{
node *slow_ptr=start;
node *fast_ptr=start;
	
 while (fast_ptr!= end && fast_ptr->next!=end) 
    { 
        fast_ptr = fast_ptr-> next->next; 
        //if (fast_ptr != end) 
        //{ 
            slow_ptr=slow_ptr->next; 
           // fast_ptr=fast_ptr->next; 
        //} 
    } 	
	
return slow_ptr;
}
node* binarySearch(node *head, int data) 
{ 
  node* start = head; 
  node* end = NULL; 
  
    do
    { 
        node* mid =middle(start, end); 
        if (mid == NULL) 
            return NULL; 
   
        
	if (mid->data==data) 
            return mid; 
 
        else if (mid->data<data) 
            start = mid->next; 
        else
            end = mid; 
  
    } while (end == NULL||end!= start); 
    return NULL; 
} 

     
void create(void)
{
	node *temp,*prev=first;
    temp=(node *)(malloc(sizeof(node)));
     printf("\n Enter the data ");
     scanf("%d",&temp->data);
    
    if(first==NULL) 
        {
          first=temp;
	
        }
        else
          {
		while(prev->next!=NULL)
 		{
  			prev=prev->next;
 		}
		prev->next=temp;
		           
          }
    

}

void print(node *temp)
{
 printf("\n The list is \n");
 printf(" -----------\n");
 while(temp!=NULL)
 {
  printf("%d-->",temp->data);
  temp=temp->next;
 }
 printf("Nill");
}


insertafterthenumber()
{
int data;
node *temp,*curr;
temp=(node *)(malloc(sizeof(node)));
printf("\n enter the data :");
  scanf("%d",&temp->data);
   
    printf("\n enter the number insert after the number \n");
     scanf("%d",&data);
	curr=first;   
	while(curr->data!=data)
	    { 
		curr=curr->next;
			if(curr==NULL)
                         {
			   printf("data =%dis not available ",data );
					free(temp);
		          	 	return insertbeforethenumber(first);
         	         }
	     }
	        
	  if(curr->data==data)
         	{
			temp->next=curr->next;
			curr->next=temp;		
		}


}




insertbeforethenumber(node *curr)
{

int data;
node *temp,*prev;
temp=(node *)(malloc(sizeof(node)));
printf("\n enter the data :");

  scanf("%d",&temp->data);
   temp->next=NULL;
	 printf("\n enter the number insert before the number \n");
     scanf("%d",&data);
	prev=first;	
	

   if(first->data==data)//to insert before the 1st node
    {	
	temp->next=first;
	first=temp;
    }
 else
     {	
	while(curr->data!=data)
	    {
		prev=curr;
		curr=curr->next;
	               if(curr==NULL)
                         {
			   printf("data =%dis not available ",data );
					free(temp);
		          	 	return insertbeforethenumber(first);
         	         }
			
	     }

                     if(curr->data==data)
         	       {
                        	temp->next=curr;
			        prev->next=temp;
			}
      }		


}

void delete(node *temp )
 {
   int data;
node *prev,*curr;
   printf("enter the number which u want delet\n");
   scanf("%d",&data);
   if(temp->data==data)
    {
     temp=temp->next;
	first=temp;  
    }

    else
      {
        prev=temp;
        curr=temp->next;
          
		while(curr->data!=data)
                 {  
	           prev=prev->next;
	           curr=curr->next;
			if(curr==NULL)
                         {
			   printf("data =%dis not available ",data );
		          	 	return delete(first);
         	         }
			
                 } 

              if(curr->data==data)
		{	temp=curr;
                      prev->next=curr->next;
			free(temp);
		}                 
      }
}
void update()
{   node *temp;
 int num,data;
	print(first);
     printf("which data u want modify,by which num\n data=");
     scanf("%d",&data); printf("\nnum=");
     scanf("%d",&num);
     temp=first;
     while(temp->data!=data)
	{
	    temp=temp->next;
		if(temp==NULL)
                   {
			printf("data =%dis not available ",data );
         		 update();
         	   }
        }
   temp->data=num;
}

int re_print(node *temp)
{
 if(temp==NULL)
	printf("\nempty\n");
else
	
{
     re_print(temp->next);
     printf("%d-->",temp->data);
}

}
void reverse() 
{ 
node* prev = NULL; 
node* current = first; 
node* next = NULL; 
	while (current!= NULL) 
     { 
	  next = current->next; 
   	  current->next = prev;
   	  prev = current; 
   	  current = next; 
 	 } 
first = prev; 
} 
void main()
{
 int ch=0,data;
 first=NULL;
 printf("\n Linked List creation \n");
 while(1)
{
  printf("choose the option \n1.create\n2.print\n3.insertafterthenumber\n 4.insertbeorethenummber\n5.delete\n");
  printf("6.re_print\n7.update\n8.reverse\n9.exit\n10.binary_search\n");  
	scanf("%d",&ch);
    switch(ch)  
	{
           case 1: create();
       		   print(first);
		   break;
           case 2: print(first);
       	           break;
           case 3: insertafterthenumber();
	           print(first);
	           break;
	   case 4: insertbeforethenumber(first);
	           print(first);
                   break;
	   case 5: print(first);
		   delete(first);
		   print(first);
			break;
	   case 6: re_print(first);
                   break;
	   case 7: update();
		   print(first);
		   break;	
	  case 8: reverse();
			break;;
	  case 9: exit(0);
	  case 10:printf("\nenter the searched data:");scanf("\n%d",&data);
			if(binarySearch(first,data)==NULL)
				printf("data not found\n");
			else
			       printf("data found\n\n");
			break;
	default :printf("wrong option\n");
	
	}
}

}


