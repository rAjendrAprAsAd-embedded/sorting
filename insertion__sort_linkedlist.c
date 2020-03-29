
# include <stdio.h>
# include <stdlib.h>
struct list
{
 int data;
 struct list *next;
};
typedef struct list node;
node *first;
void print(node *);

void insertion_sort() 
{ 
    // Initialize sorted linked list 
    node *final_list = NULL; 
     node *temp=first;
     node *current =temp; 
    while (current != NULL) 
    { 
       
       node *next = current->next; 
     Insert(&final_list, current); 
     current = next; 
    } 
    first= final_list; 
} 
  
Insert(node** final_list, node* insert) 
{ 
   node* temp; 
    if (*final_list == NULL || (*final_list)->data >= insert->data) 
    { 
        insert->next = *final_list; 
        *final_list = insert; 
    } 
    else
    { 
       temp = *final_list; 
        while (temp->next!=NULL &&  temp->next->data < insert->data) 
        { 
            temp = temp->next; 
        } 
        insert->next = temp->next; 
        temp->next = insert; 
    } 
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
  printf("6.re_print\n7.update\n8.reverse\n9.exit\n10.insertion_sort\n");  
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
	  case 10:insertion_sort();
			break;
	default :printf("wrong option\n");
	
	}
}

}


