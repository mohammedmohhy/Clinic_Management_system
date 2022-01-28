#include "clinic.h"
#include <stdlib.h>
#include <stdio.h>

/*doctor reservation slots, all time slots initially available*/
u8 slots[5]={AVAILABLE,AVAILABLE,AVAILABLE,AVAILABLE,AVAILABLE};


void swap(u32 *x,u32 *y)
{
	u32 temp=0;
	temp = *x;
	*x = *y;
	*y = temp;
	
	
}


/*create the head of the linked list*/
User_Node* LL_Create_User_Node(u8 entered_ID[14],u8 entered_name[10],u8 entered_age,u8 entered_gender[6])
{
	User_Node* head = (User_Node*)malloc(sizeof(User_Node));
	if(head!=NULL)
	{
		for(u8 i=0;i<14;i++)
		{
			head->ID[i] = entered_ID[i];
		}
		for(u8 i=0;i<10;i++)
		{
			head->name[i] = entered_name[i];
		}
		for(u8 i=0;i<6;i++)
		{
			head->gender[i] = entered_gender[i];
		}
		head->age = entered_age;
		head->slot = 0;
		head->next = NULL;
	}
	return head;
}

/*create the head of the linked list*/
Admin_Node* LL_Create_Admin_Node(u32 Data)
{
	Admin_Node* head = (Admin_Node*)malloc(sizeof(Admin_Node));
	if(head!=NULL)
	{
		head->password = Data;
		head->next = NULL;
	}
	return head;
}


/*search for an existed Node by ID, if is not existed returns the head_Node, so check for the return Node ID, if==11111111111111 its not found*/
User_Node* Search_User_Node(User_Node* head,u8 *entered_ID)
{
	User_Node* ptr=head;
	u8 flag_found=0;
	u8 i=0;
	/*this loop ends when the NULL pointer at the end is reached*/
	while( (ptr!=NULL))
	{
		for(i=0;i<14;i++)
		{
			if (ptr->ID[i]==entered_ID[i]&& (i==13))
			{
				flag_found=1;
				break;
			}
			else if(ptr->ID[i]!=entered_ID[i])
			{
				flag_found=0;
				ptr = ptr->next;
				break;
			}
		}
		/*checks if the for loop ended beacuse the Node was found or not, if found break from the while loop too*/
		if(flag_found==1)
		{
			break;
		}
		
	}
	/*checks if the while loop ended because the element was not found, return the head node*/
	if(ptr==NULL)
	{
		
		ptr=head;
	}
	return ptr;
	
}


/*insert a node at the end of the linked list */
void Append_User_Node(User_Node* head_ptr,u8* entered_ID, u8* entered_name,u8 entered_age,u8* entered_gender)
{
	/*check if the entered ID is already exists*/
	User_Node* check_exist = Search_User_Node(head_ptr,entered_ID);
	/*check if the ID entered exists as search function will return the head node if the ID is not exists*/
	if ((head_ptr!=NULL) && ((check_exist->ID[0])=='0') )
	{
		User_Node* new_node = (User_Node*)malloc(sizeof(User_Node));
		User_Node* tail_ptr=head_ptr;
		if(new_node!=NULL)
		{
			/*tail_ptr after this loop will points to the last Node*/
			while ( (tail_ptr->next)!=NULL)
			{
				tail_ptr = tail_ptr->next;
			}
			tail_ptr->next = new_node;

			//for(u8 i=0;(entered_ID[i]!='\n' && i<14);i++)
			for(u8 i=0;i<14;i++)
			{
				new_node->ID[i] = entered_ID[i];
			}
			//for(u8 i=0;(entered_name[i]!='\n' && i<20);i++)
			for(u8 i=0;i<10;i++)
			{
				new_node->name[i] = entered_name[i];
			}
			//for(u8 i=0;(entered_gender[i]!='\n' && i<6);i++)
			for(u8 i=0;i<6;i++)
			{
				new_node->gender[i] = entered_gender[i];
			}
			new_node->age = entered_age;
			new_node->slot = 0;
			new_node->next = NULL;
			
			printf("The new patient was added successfuly\n");
		}
		else
		{
			printf("can't add this patient due to lack of memory\n");
		}
	}
	else
	{
		printf("can't add this patient, the ID already exists\n");
	}
	
}




/*print the given node details */
void LL_Print_User_Node(User_Node* node)
{
	/*check if the node is not found by the searching function as its used before the print function*/
	if(((node->ID[0]!='0') ))
	{
		printf("patient ID is: ");
		for(u8 i=0;((node->ID[i]!='\0')&&(i<14));i++)
		{
			printf("%c",node->ID[i]);
		}
		printf("\npatient name is: ");
		for(u8 i=0;((node->name[i]!='\0')&&(i<10));i++)
		{
			printf("%c",node->name[i]);
		}
		printf("\npatient gender is: ");
		for(u8 i=0;((node->gender[i]!='\0')&&(i<6));i++)
		{
			printf("%c",node->gender[i]);
		}
		printf("\npatient age: %d\n",node->age);
	}
	else
	{
		printf("can't find this patient\n");
	}
	
}


void LL_Edit_Patient_Record(User_Node* head,u8 *entered_ID)
{
	u8 entered_name[10],entered_age,entered_gender[6];
	
	User_Node* ptr_to_Node;
	ptr_to_Node=Search_User_Node(head,entered_ID);
	/*check if the Node is not exist and the head node is returned*/
	if(ptr_to_Node->ID[0] == '0')
	{
		printf("this patient is not registerd\n");
	}
	else
	{
		printf("enter the patient's new age: ");
		scanf("%d",&entered_age);
		printf("enter the patient's new name: ");
		scanf("%s",entered_name);
		printf("enter the patient's new gender: ");
		scanf("%s",entered_gender);
		
		for(u8 i=0;i<10;i++)
		{
			ptr_to_Node->name[i]=entered_name[i];
		}
		for(u8 i=0;i<6;i++)
		{
			ptr_to_Node->gender[i]=entered_gender[i];
		}
		ptr_to_Node->age = entered_age;
		
		printf("The patient record edited successfuly\n");
	}
}



void LL_Reserve_Slot (User_Node* head, u8 *entered_ID,u8 slot_number)
{
	if(slot_number<6 && slot_number>0 && slots[slot_number-1]!=RESERVED)
	{
		User_Node* ptr_to_Node;
		ptr_to_Node=Search_User_Node(head,entered_ID);
		/*check if the Node is not exist and the head node is returned*/
		if(ptr_to_Node->ID[0] == '0')
		{
			printf("this patient is not registerd\n");
		}
		else
		{
			/*check if the patient reserved a slot before to over write the slot and free the old one*/
			if (ptr_to_Node->slot !=0)
			{
				/*free the old reservation*/
				slots[(ptr_to_Node->slot)-1]=AVAILABLE;
				printf("The old slot canceled and the new one reserved instead\n");
			}
			/*attach the new slot with the patient*/
			ptr_to_Node->slot = slot_number;
			/*reserve the new one*/
			slots[slot_number-1]=RESERVED;
			printf("The slot reserved successfuly\n");
		}
	}
	else
	{
		printf("can't reserve this slot\n");
	}
	
}

void LL_Cancel_Reservation(User_Node* head, u8 *entered_ID)
{
	User_Node* ptr_to_Node;
	ptr_to_Node=Search_User_Node(head,entered_ID);
	/*check if the Node is not exist and the head node is returned*/
	if(ptr_to_Node->ID[0] == '0')
	{
		printf("this patient is not registerd\n");
	}
	else
	{
		if(ptr_to_Node->slot !=0)
		{
			/*save the number of reservation slot to be deleted from the slots array*/
			u8 slot_number =ptr_to_Node->slot;
			ptr_to_Node->slot = 0;
			
			slots[slot_number-1]=AVAILABLE;
			printf("The reservation canceled successfuly\n");
		}
		else
		{
			printf("You haven't reserved a slot yet\n");
		}
		
	}
	
	
}


void LL_View_Reservations(User_Node* head)
{
	printf("All reservations for today: \n");
	User_Node* ptr_to_node = head;
	/*skip the head node*/
	if (ptr_to_node->ID[0]=='0')
	{
		ptr_to_node= ptr_to_node->next;
	}
	/*check if the slot is not reserved, it will be 0, so don't print it*/
	while( (ptr_to_node !=NULL) && (ptr_to_node->slot !=0) )
	{
		printf("patient ID: ");
		for(u8 i=0;i<14;i++)
		{
			printf("%c",ptr_to_node->ID[i]);
		}
		printf("\t reserved_slot: %d\t",(ptr_to_node->slot));
		ptr_to_node= ptr_to_node->next;
	}
	
}

