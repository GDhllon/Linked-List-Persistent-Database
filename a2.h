/*Name: Gary Dhillon 
 * Date: Wednesday, October 15, 2014 
 * Assignment 2*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RentalCar{
    int mileage;
    char * plateNumber;
    struct RentalCar * next;
};

struct RentedCar{
    int mileage;
    char*plateNumber;
    int year;
    int month;
    int day;
    struct RentedCar*next;
};

typedef struct RentedCar RentedCar;
typedef struct RentalCar RentalCar;

RentalCar * newCar(int mileage, char*plateNumber);

RentedCar * newRent(int mileage, char*plateNumber, int year, int month, int day);

RentalCar * insertCarToAvailable(RentalCar * toBeAdded, RentalCar *availableList);

RentalCar * insertCarToRepair(RentalCar*toReturn, RentalCar * repairList);

RentedCar * insertCarToRental(RentedCar*toRent, RentedCar*rentalList);

RentalCar * removeCar(RentalCar*toRemove, RentalCar*avilableList);

RentedCar * removeRental(RentedCar*toRemove, RentedCar*rentalList);

RentalCar * removeRepair(RentalCar*toRemove, RentalCar*repairList);

RentalCar * findCar(char * plateNumber, RentalCar*availableList, int size);

RentedCar * findRent(char * plateNumber, RentedCar*rentalList, int size);

RentalCar* findRepair(char * plateNumber, RentalCar*repairList, int size);

void printAvailable(RentalCar * availableList);

void printRent(RentedCar * rentalList);

void printRepair(RentalCar * repairList);

void flush();

RentalCar * fileParseAvailableList(RentalCar * availableList, FILE * fp);

RentalCar * fileParseRepairList(RentalCar * repairList, FILE * fp);

RentedCar * fileParseRentalList(RentedCar * rentalList, FILE * fp);

RentalCar * availableLineParse(char* inputLine, RentalCar * availableList);

RentalCar * repairLineParse(char* inputLine, RentalCar * repairList);

RentedCar * rentedLineParse(char* inputLine, RentedCar * rentedList);

void printToFile(RentalCar * availableList, RentalCar * repairList, RentedCar * rentalList, FILE * fp);

void destroyList(RentalCar * availableList, RentalCar * repairList, RentedCar * rentalList);



