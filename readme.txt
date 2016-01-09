/*Name: Gary Dhillon 
 * Date: Wednesday, October 15, 2014 
 * Assignment 2*/

*************
Introduction
*************
There are two programs included in this package. The first, q1.c, is a used car rental databse simulation which gives
the user the ability to keep track of cars in three lists: rented, repair, available.

The user can add or remove from any of these lists as well as save the contents for the list in a provided file, from which the 3 lists
will be loaded into the program upon starting it.

The second program, q2.c allows allows the evaluation of postfix operations by creating a stack, through which the operation is read from. 


*************
Compiltation
*************

-Open a terminal window, navigate to the Assignment_2 directory and type "make" (no quotes) then press enter.
-Type "./q1" (no quotes) to begin running the linked list program.
-Type "./q2 (postfix operation)" (no quotes or brackets) to begin running the postfix program.
-For the postfix operation simply type any valid postfix operation after ./q2
e.g. type ./q2 12+53-* to calculate (1+2)*(5-3)

*************
Running
*************

q1.c

-Upon starting the program the lists will be loaded with cars already listed in the data file provided.

-The user will see a menu with 7 options, the user can type and enter '1', '2', '3', '4', '5', '6' or '7' to access any of the listed options (no quotes).

-Entering '1', '2', '3' will prompt the user to enter a license plate (any string of letters and numbers will be accepted as there was no specification as to license plate length) followed by a prompt for mileage.

-Entering 4 will prompt the user for a license plate to move from the repair list to the available-for-rent list.

-For options '2', '3' or '4' if the license plate entered is not found on the list it is meant to be removed from the program will reutrn a print statement stating that the license plate cannot be moved.

-Entering '5' will prompt the user for 3 integers, a 1-2 digit integer for year, month and day respectively. If a 0 value is detected for any of the 3 values or an invalid value (such as 13 for the month value) the program will not rent the vehicle.

-Entering '6' will print the 3 current lists.

- Entering '7' will exit the program which will free memory and print the income generated from the returned vehicles as well as store the list data into the data file provided.

q2.c

-For the postfix operation simply type any valid postfix operation after ./q2
e.g. type ./q2 12+53-* to calculate (1+2)*(5-3).

-Invalid operators will result in the program exiting prematurely without printing a value.

*************
Sample output
*************

q1.c

-With the current values stored in the data file the following will be printed if the user enters '6':

Cars Available for Rent:

License Plate: QWERTY123 
 Mileage: 2000 
License Plate: LICENSEP 1234 
 Mileage: 3000 


Cars Currently Rented Out (dd/mm/yy):

License Plate: JKL 1234 
 Mileage: 400 
 Return Date: 11/11/11

License Plate: ABC1234 
 Mileage: 500 
 Return Date: 12/12/12



Cars Under Repairs:

License Plate: IOP 1234 
 Mileage: 29 
License Plate: RANDOM 1234 
 Mileage: 400 


q2.c

-Entering './q2 42+351-*+' (no quotes) on the command line in the Assignment_2 directory will print value 18.00.
