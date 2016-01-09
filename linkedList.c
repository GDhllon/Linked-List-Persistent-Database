/*Name: Gary Dhillon 
 * Date: Wednesday, October 15, 2014 
 * Assignment 2*/

#include "a2.h"

RentalCar* newCar(int mileage, char*plateNumber){/*Malloc and initialize memory for new car node*/
    
    RentalCar * newCar = malloc(sizeof(RentalCar));
    newCar->mileage = mileage;
    newCar->plateNumber = malloc(sizeof(char)*10);
    strcpy(newCar->plateNumber, plateNumber);
    newCar->next = NULL;
    return(newCar);
}

RentedCar * newRent(int mileage, char*plateNumber, int year, int month, int day){/*Malloc and initialize memory for new rented car node*/
    
    RentedCar * newCar = malloc(sizeof(RentedCar));
    newCar->mileage = mileage;
    newCar->plateNumber = malloc(sizeof(char)*10);
    strcpy(newCar->plateNumber,plateNumber);
    newCar->year = year;
    newCar->month = month;
    newCar->day = day;
    newCar->next = NULL;
    return(newCar);
}

RentalCar*insertCarToAvailable(RentalCar*toBeAdded, RentalCar *availableList){/*Insert and sort car node into availableList*/

    if(availableList == NULL)
    {
        toBeAdded->next = availableList;
        return(toBeAdded);
    }
    else if(toBeAdded->mileage < availableList->mileage){
            toBeAdded->next = availableList;
            availableList = toBeAdded;
            return(toBeAdded);
    }
    else{
        RentalCar * temp;
        temp = availableList;
        
        
        while((temp->next!=NULL) && ((temp->next->mileage) < (toBeAdded->mileage))){
            temp = temp->next;
        }
            
        if(temp->mileage == toBeAdded -> mileage){
            toBeAdded -> next = temp->next;
            temp->next = toBeAdded;
        }
            
        else if(temp->next!=NULL)
        {
            toBeAdded->next = temp->next;
            temp->next = toBeAdded;
        }
        else{
            temp->next = toBeAdded;
            toBeAdded->next = NULL;
        }       
        return(availableList);
    }
}


RentalCar*insertCarToRepair(RentalCar*toReturn, RentalCar *repairList){/*Insert and sort car node to repairList*/
    
    if(repairList == NULL)
    {
        toReturn->next = repairList;
        return(toReturn);
    }
    else if(toReturn->mileage < repairList->mileage){
            toReturn->next = repairList;
            repairList = toReturn;
            return(toReturn);
    }
    else{
        RentalCar * temp;
        temp = repairList;
        
        
        while((temp->next!=NULL) && ((temp->next->mileage) < (toReturn->mileage))){
            temp = temp->next;
        }
            
        if(temp->mileage == toReturn -> mileage){
            toReturn -> next = temp->next;
            temp->next = toReturn;
        }
            
        else if(temp->next!=NULL)
        {
            toReturn->next = temp->next;
            temp->next = toReturn;
        }
        else{
            temp->next = toReturn;
            toReturn->next = NULL;
        }       
        return(repairList);
    }
}

RentedCar*insertCarToRental(RentedCar*toRent, RentedCar *rentalList){/*Insert and sort rented car node into rentalList*/
    
    RentedCar * temp;
    temp = rentalList;
    
    if(rentalList== NULL)
    {
        toRent->next = rentalList;
        return(toRent);
    }
    if(toRent->year< rentalList->year){
        toRent->next = rentalList;
        rentalList = toRent;
        return(rentalList);
    }
    else if(toRent->year == rentalList->year){
        if(toRent->month<rentalList->month){
            toRent->next = rentalList;
            rentalList = toRent;
            return(rentalList);
        }
        else if(toRent->month == rentalList->month){
            if(toRent->day<=rentalList->day){
                toRent->next = rentalList;
                rentalList = toRent;
                return(rentalList);
            }
        }
    }
        
    else{
        while(temp->next!=NULL){
                
                if(toRent->year< temp->next->year){
                    toRent->next = temp->next;
                    temp->next = toRent;
                    return(rentalList);
                }
                else if(toRent->year == temp->next->year){
                    if(toRent->month<temp->next->month){
                        toRent->next = temp->next;
                        temp->next = toRent;
                        return(rentalList);
                    }
                    else if(toRent->month == temp->next->month){
                        if(toRent->day<=temp->next->day){
                            toRent->next = temp->next;
                            temp->next = toRent;
                            return(rentalList);
                        }
                        else{
                            temp= temp->next;
                        }
                    }
                    else{
                        temp= temp->next;
                    }
                }
                else{
                    temp= temp->next;
                }
          }
    }
    temp->next = toRent;
    toRent->next = NULL;
    return(rentalList);
}               

RentalCar * removeCar(RentalCar*toRemove, RentalCar*availableList){/*Remove car node from availableList*/
    
    RentalCar * temp;
    temp = availableList;
    
    while(temp!=toRemove){
        temp = temp->next;
    }
    
    if(temp->next!=NULL)
    {
        temp= temp->next;
        free(toRemove->plateNumber);
        free(toRemove);
        
        return(temp);
    }
    else
    {
        free(toRemove->plateNumber);
        free(toRemove);
        return(NULL);
    }
}

RentedCar * removeRental(RentedCar*toRemove, RentedCar*rentalList){/*Remove rented car node from rentalList*/
    
    RentedCar * temp;
    temp = rentalList;
    
    if(toRemove == rentalList){
        rentalList = rentalList->next;
        free(toRemove->plateNumber);
        free(toRemove);
        return(rentalList);
    }
    
    while(temp->next!=toRemove){
        temp = temp->next;
    }
    
    temp->next = temp->next->next;
    free(toRemove->plateNumber);
    free(toRemove);
    return(rentalList);
    
}

RentalCar * removeRepair(RentalCar*toRemove, RentalCar*repairList){/*Remove car node from repairList*/
    
    RentalCar * temp;
    temp = repairList;
    
    if(toRemove == repairList){
        repairList = repairList->next;
        free(toRemove->plateNumber);
        free(toRemove);
        return(repairList);
    }
    
    while(temp->next!=toRemove){
        temp = temp->next;
    }
    
    temp->next = temp->next->next;
    free(toRemove->plateNumber);
    free(toRemove);     
    return(repairList);
}

RentalCar * findCar(char * plateNumber, RentalCar*availableList, int size){/*Find and return pointer to car node in availableList*/
    
    RentalCar * temp;
    int result;
    temp = availableList;
    if(availableList == NULL){
        return NULL;
    }
    
    result = strncmp(plateNumber, temp->plateNumber,size);
    
    if(result == 0){
        return(temp);
    }
    else if(temp->next == NULL){
        return NULL;
    }
    else{
        while(((strncmp(plateNumber, temp->plateNumber,size))!=0) && temp->next!=NULL){
            temp = temp->next;
        }
        
        if(((strncmp(plateNumber, temp->plateNumber,size))!=0))
        {
            return(NULL);
        }
        else{
            return(temp);
        }
    }
}

RentedCar * findRent(char * plateNumber, RentedCar*rentalList, int size){/*Find and return pointer to rental car node in rentalList*/
    
    RentedCar * temp;
    int result;
    if(rentalList == NULL){
        return NULL;
    }
    
    temp = rentalList;
    result = strncmp(plateNumber, temp->plateNumber,size);
    if(result == 0){
        return(temp);
    }
    else if(temp->next == NULL){
        return NULL;
    }
    else{
        while(((strncmp(plateNumber, temp->plateNumber,size))!=0) && temp->next!=NULL){
            temp = temp->next;
        }
        
        if(((strncmp(plateNumber, temp->plateNumber,size))!=0))
        {
            return(NULL);
        }
        else{
            return(temp);
        }
    }
}

RentalCar * findRepair(char * plateNumber, RentalCar*repairList, int size){/*Find and return pointer to car node in repairList*/
    
    RentalCar * temp;
    int result;
    if(repairList == NULL){
        return NULL;
    }
    
    temp = repairList;
    result = strncmp(plateNumber, temp->plateNumber,size);
    
    if(result == 0){
        return(temp);
    }
    else if(temp->next == NULL){
        return NULL;
    }
    else{
        while(((strncmp(plateNumber, temp->plateNumber,size))!=0) && temp->next!=NULL){
            temp = temp->next;
        }
        
        if(((strncmp(plateNumber, temp->plateNumber,size))!=0))
        {
            return(NULL);
        }
        else{
            return(temp);
        }
    }
}

void printAvailable(RentalCar * availableList){/*Print availableList*/
    
    while(availableList!=NULL){
            printf("License Plate: %s \n Mileage: %d \n", availableList -> plateNumber, availableList -> mileage);
        
        availableList = availableList -> next;
    }
}

void printRent(RentedCar* rentalList){/*Print rentalList*/
    
    while(rentalList!=NULL){
        if(rentalList->plateNumber!=NULL){
            printf("License Plate: %s \n Mileage: %d \n Return Date: %d/%d/%d\n\n", rentalList -> plateNumber, rentalList -> mileage, rentalList -> day, rentalList->month, rentalList->year);
        }
        rentalList = rentalList -> next;
    }
}

void printRepair(RentalCar * repairList){/*Print repairList*/
    
    while(repairList!=NULL){
        if(repairList->plateNumber!=NULL){
            printf("License Plate: %s \n Mileage: %d \n", repairList -> plateNumber, repairList -> mileage);
        }
        repairList = repairList -> next;
    }
}

void destroyList(RentalCar * availableList, RentalCar * repairList, RentedCar * rentalList){/*Free all memory allocated for the 3 lists*/
    
    while(availableList!=NULL)
    {
        free(availableList->plateNumber);
        availableList = availableList->next;
    }
    free(availableList);
    
    while(repairList!=NULL)
    {
        free(repairList->plateNumber);
        repairList = repairList->next;
    }
    free(repairList);
    
    while(rentalList!=NULL)
    {
        free(rentalList->plateNumber);
        rentalList = rentalList->next;
    }
    free(rentalList);
}
                    
