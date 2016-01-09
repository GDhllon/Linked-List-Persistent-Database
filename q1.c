/*Name: Gary Dhillon 
 * Date: Wednesday, October 15, 2014 
 * Assignment 2*/

#include "a2.h"
#include "a1.h"

int main(){/*Main menu loop*/
    char input;
    char * plateNumber = malloc(sizeof(char)*10);
    int mileage;
    int year=0;
    int month=0;
    int day=0;
    int size=0;
    
    RentalCar * availableList = malloc(sizeof(RentalCar));
    RentalCar * repairList = malloc(sizeof(RentalCar));
    RentedCar * rentalList = malloc(sizeof(RentedCar));
    RentalCar * temp = malloc(sizeof(RentalCar));
    RentedCar * temp2 = malloc(sizeof(RentedCar));
    double totalSum= 0;
    double charge=0;
    FILE * fr;
    FILE * fw;
    
    availableList = NULL;
    repairList = NULL;
    rentalList = NULL;
    
    fr = fopen("CarLists.csv", "rt");
    
    availableList = fileParseAvailableList(availableList, fr);
    repairList = fileParseRepairList(repairList, fr);
    rentalList = fileParseRentalList(rentalList, fr);
    
    fclose(fr);
    
    printf("Welcome to the car rental service inventory system:\n");
    do
    {
        printf("\n\n");
        printf("Please enter the number that corresponds to the option you wish to select from the menu:\n");
        printf("1. Add a new car to the available-for-rent list. \n");
        printf("2. Add a returned car to the available-for-rent list.\n");
        printf("3. Add a returned car to the repair list.\n");
        printf("4. Transfer a car from the repair list to the available-for-rent list.\n");
        printf("5. Rent first available car.\n");
        printf("6. Print all lists. \n");
        printf("7. Quit\n");
        printf("\n");
        input = getchar();
        flush();
        switch(input)
        {
            case '1':
            printf("Please begin by entering the license plate of the vehicle:\n");
            fgets(plateNumber, 200, stdin);
            size = strlen(plateNumber) - 1;
            if(plateNumber[size] == '\n')
            plateNumber[size] = '\0';
            printf("Next, please enter the mileage of the vehicle.\n");
            scanf("%d", &mileage);
            flush();
            if(mileage>0){
                
                temp = findCar(plateNumber, availableList, size);
                if(temp!=NULL){
                    printf("It appears a vehicle with that license plate it already located on the available-for-rent list. \n");
                }
                else if(temp==NULL){
                    temp = newCar(mileage, plateNumber);
                    availableList = insertCarToAvailable(temp, availableList);
                    printf("The vehicle with plate number %s has been moved on to the available-for-rent list. \n", plateNumber);
                }
            }
            else{
                printf("That is an invalid value for the mileage of the vehicle\n");
            }
            break;
            case '2':
            printf("Please begin by entering the license plate of the vehicle:\n");
            fgets(plateNumber, 200, stdin);
            size = strlen(plateNumber) - 1;
            if(plateNumber[size] == '\n')
            plateNumber[size] = '\0';
            printf("Next, please enter the mileage of the vehicle.\n");
            scanf("%d", &mileage);
            flush();
            if(mileage>0){
                
                temp2 = findRent(plateNumber, rentalList, size);
                if(temp2 == NULL){
                    printf("Sorry, that car is not currently listed on the Rented List and thus cannot be returned and put on the available-for-rent list\n");
                }
                else{
                    temp = newCar(mileage, plateNumber);
                    availableList = insertCarToAvailable(temp, availableList);
                    if(mileage - temp2->mileage <=100){
                        charge = 40;
                    }
                    else{
                        charge = 40 + (mileage-temp2->mileage-100)*.15;
                    }
                    totalSum = totalSum + charge;
                    rentalList = removeRental(temp2, rentalList);
                    printf("The vehicle with license plate # %s has been returned and placed back on the available-for-rent list. \n", plateNumber);
                    printf("The client has been charged $%0.2f for the rental.\n", charge);
                }
            }
            else{
                printf("That is not a valid value for the mileage of the vehicle\n");
            }
            break;
            case '3':
            printf("Please begin by entering the license plate of the vehicle:\n");
            fgets(plateNumber, 200, stdin);
            size = strlen(plateNumber) - 1;
            if(plateNumber[size] == '\n')
            plateNumber[size] = '\0';
            printf("Next, please enter the mileage of the vehicle.\n");
            scanf("%d", &mileage);
            flush();
            if(mileage>0){
                temp2 = findRent(plateNumber, rentalList, size);
                if(temp2 == NULL){
                    printf("Sorry, that car is not currently listed on the Rented List and thus cannot be returned and put on the Under Repairs List\n");
                }
                else{
                    temp = newCar(mileage, plateNumber);
                    repairList = insertCarToRepair(temp, repairList);
                    if(mileage - temp2->mileage <=100){
                        charge = 40;
                    }
                    else{
                        charge = 40 + (mileage-temp2->mileage-100)*.15;
                    }
                    totalSum = totalSum + charge;
                    rentalList = removeRental(temp2, rentalList);
                    printf("The vehicle with license plate # %s has been returned and placed on the Under Repair List.\n", plateNumber);
                    printf("The client has been charged $%0.2f for the rental.\n", charge);
                }
            }
            else{
                printf("That is not a valid value for the mileage of the vehicle\n");
            }
            break;
            case '4':
            printf("Please enter the license plate of the vehicle:\n");
            printf("Please begin by entering the license plate of the vehicle:\n");
            fgets(plateNumber, 200, stdin);
            size = strlen(plateNumber) - 1;
            if(plateNumber[size] == '\n')
            plateNumber[size] = '\0';
            temp = findRepair(plateNumber, repairList, size);
            if(temp == NULL){
                printf("Sorry, that car is not currently listed on the Under Repairs List and thus cannot be returned and put on the available-for-rent list\n");
            }
            temp = newCar(temp->mileage, plateNumber);
            availableList = insertCarToAvailable(temp, availableList);
            temp = findRepair(plateNumber, repairList, size);
            repairList = removeRepair(temp, repairList);
            printf("The vehicle with license plate # %s has been moved from the repair list to the available-for-rent list. \n", plateNumber);
            break;
            case '5':
            printf("Please enter the expected return date:\n");
            printf("First enter the year in a 1-2 digit yy format (e.g. 14 for 2014):\n");
            scanf("%d", &year);
            flush();
            printf("Now enter the month in a 1-2 digit mm format (e.g. 12 for December):\n");
            scanf("%d", &month);
            flush();
            printf("Now enter the day in a 1-2 digit dd format (e.g. 30 for the 30th of the month):\n");
            scanf("%d", &day);
            flush();
            if(year > 0 && month>0 && month<13 && day>0 && day<32){
                
                temp = availableList;
                if(temp == NULL){
                    printf("Sorry, there are no vehicles currently listed under the available-for-rent list.\n");
                }
                else{
                    temp2 = newRent(temp->mileage, temp->plateNumber, year, month, day);
                    rentalList = insertCarToRental(temp2, rentalList);
                    temp = findCar(availableList->plateNumber, availableList, size);
                    availableList = removeCar(temp, availableList);
                    printf("The vehicle with license plate # %s has been rented out and will be returned: %d/%d/%d\n", temp2->plateNumber, day, month, year);
                }
            }
            else{
                printf("It seems you have entered an invalid value for either the day, month or year\n");
            }
            break;
            case '6':
            printf("\n\n");
            printf("Cars Available for Rent:\n\n");
            printAvailable(availableList);
            printf("\n\n");
            printf("Cars Currently Rented Out (dd/mm/yy):\n\n");
            printRent(rentalList);
            printf("\n\n");
            printf("Cars Under Repairs:\n\n");
            printRepair(repairList);
            break;
            case '7':
            printf("Quitting.\n");
            fw = fopen("CarLists.csv", "w");
            printToFile(availableList, repairList, rentalList, fw);
            fclose(fw);
            destroyList(availableList, repairList, rentalList);
            printf("Total income from returned rental cars: $%0.2f\n", totalSum);
            break;
            default:
            printf("Invalid menu option, please enter a number from 1 - 7\n");
            break;
        }
    }while(input!='7');
    return 0;
}

/*Flush input buffer*/
void flush()
{
    while(getchar()!='\n');
}

RentalCar * fileParseAvailableList(RentalCar * availableList, FILE * fr){/*Read line from file for availableList, pass to line parse function for specific list*/
    
    int i = 0;
    char * inputLine = malloc(sizeof(char)*150);
    int result;
    
    /*Line read from file and passed to fileParse*/
    do
    {
        if(fgets(inputLine, 150, fr)!=NULL)
        {
            result = strncmp(inputLine, "$$$$$$$$",8);
            if(result == 0){
                i = -1;
            }
            else{
                availableList = availableLineParse(inputLine, availableList);
            }
        }
        else{
            i = -1;
        }
    }
    while(i!=-1);
    free(inputLine);
    
    return(availableList);
    
}

RentalCar * availableLineParse(char* inputLine, RentalCar * availableList){/*Parse line for availableList*/
    
    char * segment;
    char * inputCopy = malloc(sizeof(char)*150);
    char * plateNumber = malloc(sizeof(char)*10);
    int  mileage;
    RentalCar * temp;
    
    inputCopy = strcpy(inputCopy, inputLine);
    
    /*Line parsed*/
    segment = strtok(inputCopy, ",");
    strcpy(plateNumber, segment);
    segment = strtok(NULL, ",");
    mileage = atoi(segment);
    
    temp = newCar(mileage, plateNumber);
    
    availableList  = insertCarToAvailable(temp, availableList);

    return(availableList);
    
}

RentalCar * fileParseRepairList(RentalCar * repairList, FILE * fr){/*Read line from file for repairList, pass to line parse function for specific list*/
    
    int i = 0;
    char * inputLine = malloc(sizeof(char)*150);
    int result;
    
    /*Line read from file and passed to fileParse*/
    do
    {
        if(fgets(inputLine, 150, fr)!=NULL)
        {
            result = strncmp(inputLine, "$$$$$$$$",8);
            if(result == 0){
                i = -1;
            }
            else{
                repairList = repairLineParse(inputLine, repairList);
            }
        }
        else{
            i = -1;
        }
    }
    while(i!=-1);
    free(inputLine);
    
    return(repairList);
    
}

RentalCar * repairLineParse(char* inputLine, RentalCar * repairList){/*Parse line for repairList*/
    
    char * segment;
    char * inputCopy = malloc(sizeof(char)*150);
    char * plateNumber = malloc(sizeof(char)*10);
    int  mileage;
    RentalCar * temp;
    
    inputCopy = strcpy(inputCopy, inputLine);
    
    /*Line parsed*/
    segment = strtok(inputCopy, ",");
    strcpy(plateNumber, segment);
    segment = strtok(NULL, ",");
    mileage = atoi(segment);
    
    temp = newCar(mileage, plateNumber);
    
    repairList  = insertCarToAvailable(temp, repairList);

    return(repairList);
    
}

RentedCar * fileParseRentalList(RentedCar * rentalList, FILE * fr){/*Read line from file for rentalList, pass to line parse function for specific list*/
    
    int i = 0;
    char * inputLine = malloc(sizeof(char)*150);
    int result;
    
    /*Line read from file and passed to fileParse*/
    do
    {
        if(fgets(inputLine, 150, fr)!=NULL)
        {
            result = strncmp(inputLine, "$$$$$$$$",8);
            if(result == 0){
                i = -1;
            }
            else{
                rentalList = rentedLineParse(inputLine, rentalList);
            }
        }
        else{
            i = -1;
        }
    }
    while(i!=-1);
    free(inputLine);
    
    return(rentalList);
    
}


RentedCar * rentedLineParse(char* inputLine, RentedCar * rentalList){/*Parse line for rentalList*/
    
    char * segment;
    char * inputCopy = malloc(sizeof(char)*150);
    char * plateNumber = malloc(sizeof(char)*10);
    int  mileage, year, month, day;
    RentedCar * temp;
    
    inputCopy = strcpy(inputCopy, inputLine);
    
    /*Line parsed*/
    segment = strtok(inputCopy, ",");
    strcpy(plateNumber, segment);
    segment = strtok(NULL, ",");
    mileage = atoi(segment);
    segment = strtok(NULL, ",");
    year = atoi(segment);
    segment = strtok(NULL, ",");
    month = atoi(segment);
    segment = strtok(NULL, ",");
    day = atoi(segment);
    
    temp = newRent(mileage, plateNumber, year, month, day);
    
    rentalList  = insertCarToRental(temp, rentalList);

    return(rentalList);
    
}

void printToFile(RentalCar * availableList, RentalCar * repairList, RentedCar * rentalList, FILE * fp){/*Write to date file*/
    
    while(availableList!=NULL){
        fprintf(fp, "%s,%d\n", availableList->plateNumber, availableList->mileage);
        availableList = availableList->next;
    }
    fprintf(fp, "$$$$$$$$,000\n");
    
    while(repairList!=NULL){
        fprintf(fp, "%s,%d\n", repairList->plateNumber, repairList->mileage);
        repairList = repairList->next;
    }
    fprintf(fp, "$$$$$$$$,000\n");
    
    while(rentalList!=NULL){
        fprintf(fp, "%s,%d,%d,%d,%d\n", rentalList->plateNumber, rentalList->mileage, rentalList->year, rentalList->month, rentalList->day);
        rentalList = rentalList->next;
    }
    fprintf(fp, "$$$$$$$$,000\n");
}

