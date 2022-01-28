/*This clinic systems is done and has two modes(Admin mode, User mode).
 *
 *The systems asks the user to choose which mode he wants to enter.
 *
 *1- Amin mode:
				*The systems asks the admin to do a sercet thing, which is entering 1234 and press enter.
				*in this mode the admin has 6-options:
				*
				*
				*1.1- Add new patient record:
				*this option allows the adim to enter a new patient basic data such as National_ID, Name, age, and gender
				*note that the ID could be his national ID or any Unique ID which is not starts with 0.
				*if the entered ID will not be able to deal up with him as the program use this ID.
				*The ID must be Unique or a rejection message will be printed.
				*
				*
				*1.2- Edit patient record:
				*this option allows the admin to edit the basic data for a pre-defined patient.
				*the admin asked to enter the patient ID, then ask him to edit his records.
				*If the ID is not existing, a rejection message will be printed.
				*
				*
				*1.3- Reserve a slot with the doctor:
				*this option allows the admin to reserve a slot for the patient with the doctor.
				*only the available slots will be printed.
				*the system asks the admin to enter the ID of the patient, and the available slots.
				*If the ID entered is not exists, a rejection message will be printed.
				*If the slot number was out of range (1->5), a rejection message will be printed.
				*If the slot number entered was already reserved, a rejection message will be printed.
				*If the the entered ID already reserved a slot before, the old slot will be freed, and the new one
						will be reserved if available.
				*
				*
				*1.4- Cancel a rerservation:
				*this option allows the admin to cancel a reservation with the doctor.
				*the system asks the admin to enter the patient ID.
				*if the entered ID is not available, a rejection message will be printed.
				*if the entered ID hadn't reserved a slot yet, an error message will be printed.
				*if a successful cancellation happened, this slot will be freed, and could be reserved later.
				*
				*
				*1.5- print all the available slots:
				*this option allows the admin to view all the available slot.
				*if any of the slots was reserved, a reserved word will be printed besides.
				*if any of the slots was cancelled, an available word will be printed besides. 
				*
				*
				*1.6- back:
				*this option is used to get a step back from the admin mode, in case the admin needs to enter the user mode.
 *
 *
 *
 2-User mode:
				*there is no password in user mode, the options is directly listed.
				*
				*
				*2.1- view patient record:
				*this option allows the user to view his basic data.
				*the system asks the user to enter his ID.
				*If the entered ID is not available, a rejection message will be printed.
				*If the entered ID is right, the system will print his basic data.
				*
				*
				*2.2- view today's reservations:
				*this option allows the user to view all the reservations done.
				*if there are no reservations yet, the system will print an empty space.
 
*/
#include "clinic.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define MODE_UNSELECTED	0
#define MODE_SELECTED	1

extern u8 slots[5];



u32 main(void)
{
	/*an array used only to print the period of each slot*/
	f32 slots_time[10]={2,2.3, 2.3,3 , 3,3.3, 4,4.3, 4.3,5};
	/*admin or user mode*/
	u8 selected_mode = 0, entered_age=0, entered_gender[5]="NONE", entered_name[10]="NONE";
	Admin_Node* admin_head;
	User_Node* user_head;
	/*ID of the user in string form*/
	u8 entered_ID[14]="0";
	/*slot to be reserved for the new patient*/
	u8 entered_slot=0;
	/*password for the admin, it's initially wrong to avoid access by mistake*/
	u32 admin_password = 0;
	/*action needed when in admin mode*/
	u8 admin_action=0,user_action=0;
	/*flag for number of entering a wrong password in admin mode*/
	u8 wrong_password_flag=0;
	/*creating the head of the admin_node*/
	admin_head=LL_Create_Admin_Node(1234);
	user_head=LL_Create_User_Node(entered_ID,entered_name,24,entered_gender);
	
	while(1)
	{
		
		/*check if the password is not entered wrong three times */
		if((wrong_password_flag<2))
		{
			/*to clear the cmd*/
			system("cls");
			printf("press 1 for user mode\n");
			printf("press 0 for admin mode\n");
			printf("please select the Mode: ");
			scanf("%d",&selected_mode);
		}
		/*check if the password is entered three times wrong it doesn't print "press 0 for admin mode"*/
		else
		{
			/*to clear the cmd*/
			system("cls");
			printf("you are blocked from entering the admin mode\n");
			printf("press 1 for user mode\n");
			printf("please select the Mode: ");
			scanf("%d",&selected_mode);
		}
		
		/*check if the mode selected is admin mode, and that the device hadn't been blocked*/
		if((selected_mode==0) && (wrong_password_flag<2) )
		{
			/*to clear the cmd*/
			system("cls");
			printf("You know what to do\n");
			scanf("%d",&admin_password);
			/*check for the admin mode password, and gives only three tries to enter it correctly*/
			while((admin_password!= admin_head->password) && (wrong_password_flag<2) )
			{
				wrong_password_flag++;
				printf("denied access, try again\n");
				scanf("%d",&admin_password);
			}
			/*still in that loop if admin mode selected and the back button is not pressed*/
			while( (admin_password==admin_head->password) && (selected_mode==0))
			{
				/*to clear the cmd*/
				system("cls");
				printf("\n************************************************************\n");
				printf("************press 1 to add new patient record***************\n");
				printf("************press 2 to edit patient record******************\n");
				printf("************press 3 to reserve a slot with the doctor*******\n");
				printf("************press 4 to cancel a reservation with the doctor*\n");
				printf("************press 5 to print all the time slots state*******\n");
				printf("************press 6 to back ********************************\n");
				printf("************************************************************\n");
				printf("\nplease enter your selection: ");
				scanf("%d",&admin_action);
				switch(admin_action)
				{
					case 1:
							/*to clear the cmd*/
							system("cls");
							printf("enter the patient ID: ");
							scanf("%s",entered_ID);
							printf("enter the patient's name: ");
							scanf("%s",entered_name);
							printf("enter the patient's age: ");
							scanf("%d",&entered_age);
							printf("enter the patient's gender: ");
							scanf("%s",entered_gender);
					
							Append_User_Node(user_head,entered_ID,entered_name,entered_age,entered_gender);
							printf("press any key to continue");
							getch();
							break;
							
					case 2:
							/*to clear the cmd*/
							system("cls");
							printf("please enter your ID: ");
							scanf("%s",entered_ID);
							LL_Edit_Patient_Record(user_head,entered_ID);
							printf("press any key to continue");
							getch();
							break;
					case 3:
							/*to clear the cmd*/
							system("cls");
							
							printf("Available slots for reservation:\n");
							
							for(u8 i=0;i<5;i++)
							{
								if(slots[i]==AVAILABLE)
								{
									printf("slot-%d is available.\t",i+1);
									printf("from %.2f ",slots_time[i*2]);
									printf("to %.2f\n",slots_time[(i*2)+1]);
								}
							}
							printf("please enter the slot needed: ");
							scanf("%d",&entered_slot);
							printf("please enter the patient ID: ");
							scanf("%s",entered_ID);
							LL_Reserve_Slot(user_head,entered_ID,entered_slot);
							printf("press any key to continue");
							getch();
							break;
					case 4:
							/*to clear the cmd*/
							system("cls");
							printf("please enter the patient ID: ");
							scanf("%s",entered_ID);
							LL_Cancel_Reservation(user_head,entered_ID);
							printf("press any key to continue");
							getch();
							break;
					case 5:
							/*to clear the cmd*/
							system("cls");
							//(1: 2->2.30) , (2: 2.30->3) , (3: 3->3.30) , (4: 4->4.30) , (5: 4.30->5)
							printf("All slots state:\n");
							for(u8 i=0;i<5;i++)
							{
								if(slots[i]==AVAILABLE)
								{
									printf("slot-%d\t",i+1);
									printf("from %.2f ",slots_time[i*2]);
									printf("to %.2f\t",slots_time[(i*2)+1]);
									printf("AVAILABLE\n");
								}
								if(slots[i]==RESERVED)
								{
									printf("slot-%d\t",i+1);
									printf("from %.2f ",slots_time[i*2]);
									printf("to %.2f\t",slots_time[(i*2)+1]);
									printf("RESERVED\n");
								}
							}
							printf("press any key to continue");
							getch();
							break;
					case 6:
							selected_mode=111;
							break;
					default:							
							printf("undefined selection\n");
							printf("press any key to continue");
							getch();
							break;
				}
				/*it solves a strange bug, as the variable (admin_password) value changes in the next iteration with no reason*/
				admin_password=admin_head->password;
			}
			
		}
		while(selected_mode==1)
		{
			/*to clear the cmd*/
			system("cls");
			printf("press 0 to view patient record\n");
			printf("press 1 to view todays reservations\n");
			printf("press 2 to back\n");
			printf("Enter your selection: ");
			scanf("%d",&user_action);
			
			switch(user_action)
			{
				case 0: 
						/*to clear the cmd*/
						system("cls");
						printf("Please enter your national ID: ");
						scanf("%s",entered_ID);
						/*search for the patient with his ID if not found will return the head node*/
						User_Node* found_node = Search_User_Node(user_head,entered_ID);
						LL_Print_User_Node(found_node);
						printf("press any key to continue");
						getch();
						break;
				case 1:
						LL_View_Reservations(user_head);
						printf("press any key to continue");
						getch();
						break;
				case 2: 
						selected_mode=111;
						break;
				default:
						printf("undefined selection\n");
						printf("press any key to continue");
						getch();
						break;
			}
			
			
		}
		/*number to back button*/
		if( (selected_mode==111) || (selected_mode==0) || (selected_mode==1))
		{
		}
		else
		{
			printf("undefined mode, please enter 0 or 1: \n");
			printf("press any key to continue");
			getch();
		}
	}

	
	
	return 0;
}