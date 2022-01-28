#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "std_types.h"

#define RESERVED	0
#define AVAILABLE	1

typedef struct admin_node
{
	u32 password;/*password = 123*/
	struct admin_node* next;
	
}Admin_Node;

typedef struct user_node
{
	u8 ID[14];/*national ID*/
	u8 name[10];
	u8 age;
	u8 gender[6];
	u8 slot;/*(0: head node that will be garbage), (1: 2->2.30) , (2: 2.30->3) , (3: 3->3.30) , (4: 4->4.30) , (5: 4.30->5)*/
	struct user_node* next;
	
}User_Node;


/*create Admin head node sending to it the password */
Admin_Node* LL_Create_Admin_Node(u32 Data);
/*create the User head node*/
User_Node* LL_Create_User_Node(u8 entered_ID[14],u8 entered_name[10],u8 entered_age,u8 entered_gender[6]);


void Append_User_Node(User_Node* head_ptr,u8* entered_ID, u8* entered_name,u8 entered_age,u8* entered_gender);
void LL_Print_User_Node(User_Node* node);
void LL_Edit_Patient_Record(User_Node* head,u8 *entered_ID);
void LL_Reserve_Slot (User_Node* head, u8 *entered_ID,u8 slot_number);
void LL_Cancel_Reservation(User_Node* head, u8 *entered_ID);
void LL_View_Reservations(User_Node* head);

User_Node* Search_User_Node(User_Node* head,u8 *entered_ID);


#endif





