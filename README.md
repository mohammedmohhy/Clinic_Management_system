# Clinic_Management_system
/*This clinic system has two modes(Admin mode, User mode).
 *
 *The system asks the user to choose which mode he wants to enter.
 *
 *1- Amin mode:
				*The system asks the admin to do a sercet thing, which is entering 1234 and press enter.
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
