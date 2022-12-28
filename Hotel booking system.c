#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

void printWelcome();
void checkLogin();
void showMenu();
void addCustomer();
void deleteCustomer();
void viewRecord();
void searchCustomer();

struct customer_details {
    char room_type[20];
    char room_no[10];
    char name[50];
    char address[50];
    char phn_no[15];
    char email[30];
    char period[5];
    char arrival_date[10];
}serial;

int main() {
    int menu;
    printWelcome();

    checkLogin();

    menu:
    showMenu();
    while(1) {
        menu = getch();
        system("cls");
        switch(menu){
            case '1':
                addCustomer();
                break;
            case '2':
                viewRecord();
                break;
            case '3':
                deleteCustomer();
                break;
            case '4':
                searchCustomer();
                break;
            case '5':

                break;
            case '6':

                break;
            default:
                printf("\n\n\n\n\n\n\t\t\t\t\t    Incorrect Input");
                printf("\n\n\n\t\t\t\t\t      Enter again");
                sleep(1);
                system("cls");
                goto menu;
        }
    }
    return 0;
}

void printWelcome() {
    printf("\n\n\n\n\n");
    printf("\t   .----------------------------------------------------------------------------.\n");
	printf("\t   |                                                                            |\n");
	printf("\t   |  WW              WW EEEEEEE LL      CCCCCCC  OOOOOO  MM        MM EEEEEEE  |\n");
	printf("\t   |   WW            WW  EE      LL      CC      OO    OO MM MM  MM MM EE       |\n");
	printf("\t   |    WW    WW    WW   EEEEE   LL      CC      OO    OO MM   MM   MM EEEEE    |\n");
	printf("\t   |     WW WW  WW WW    EE      LL      CC      OO    OO MM        MM EE       |\n");
	printf("\t   |      WW      WW     EEEEEEE LLLLLLL CCCCCCC  OOOOOO  MM        MM EEEEEEE  |\n");
	printf("\t   |                                                                            |\n");
	printf("\t   '----------------------------------------------------------------------------'\n");
	sleep(1);
	system("cls");
	printf("\n\n\n");
    printf("\t\t\t\t    .---------------------------.\n");
	printf("\t\t\t\t    |                           |\n");
	printf("\t\t\t\t    |      .-------------.      |\n");
	printf("\t\t\t\t    |      | HOTEL ELITE |      |\n");
	printf("\t\t\t\t    |      '-------------'      |\n");
	printf("\t\t\t\t    |                           |\n");
	printf("\t\t\t\t    |                           |\n");
	printf("\t\t\t\t    |     Brought To You By     |\n");
	printf("\t\t\t\t    |                           |\n");
	printf("\t\t\t\t    |   Akram Hossain Apu Khan  |\n");
	printf("\t\t\t\t    |        Kazim Hasan        |\n");
	printf("\t\t\t\t    |        Abrar Faiaz        |\n");
	printf("\t\t\t\t    '---------------------------'\n");
	sleep(2);
	system("cls");
}

void checkLogin() {
    int i;
    char name[100], pass[50], c;
    jump:
    printf("\n\t\t\t\t      _____- Enter Username -_____\n\n\t\t\t\t\t\t");
    gets(name);
    printf("\n\t\t\t\t       _____-Enter Password-_____\n\n\t\t\t\t\t\t");
    gets(pass);

    if(strcmp(name,"user") != 0 && strcmp(pass,"pass") != 0) {
        printf("\n\n\n\t\t\t\t   !!Incorrect Username and Password!!\n\n\n");
        printf("\n\t\t\t\t      Press any key to enter again\n\n\t\t\t\t\t\t   ");
        getch();
        system("cls");
        goto jump;
    }else if(strcmp(name,"user") != 0 && strcmp(pass,"pass") == 0) {
        printf("\n\n\n\t\t\t\t\t !!Incorrect Username!!\n\n\n");
        printf("\n\t\t\t\t      Press any key to enter again\n\n\t\t\t\t\t\t   ");
        getch();
        system("cls");
        goto jump;
    }else if((strcmp(name,"user") == 0 && strcmp(pass,"pass") != 0)) {
        printf("\n\n\n\t\t\t\t\t !!Incorrect Password!!\n\n\n");
        printf("\n\t\t\t\t      Press any key to enter again\n\n\t\t\t\t\t\t   ");
        getch();
        system("cls");
        goto jump;
    }else {
        system("cls");
    }
}

void showMenu() {
    printf("____________________________________________-|MAIN MENU|-___________________________________________\n\n");
    printf("\t\t\t\t_-|Please enter your choice for menu|-_\n\n");
    printf("\n\t\t\t\t\t Enter 1 -> Book a room");
    printf("\n\t\t\t\t\t------------------------");
    printf("\n\t\t\t\t     Enter 2 -> View Customers Record");
    printf("\n\t\t\t\t    ----------------------------------");
    printf("\n\t\t\t       Enter 3 -> Delete a Customer From the Record");
    printf("\n\t\t\t      ----------------------------------------------");
    printf("\n\t\t\t       Enter 4 -> Search a Customer From the Record");
    printf("\n\t\t\t      ----------------------------------------------");
    printf("\n\t\t\t\t    Enter 5 -> Edit a Customer's Data");
    printf("\n\t\t\t\t   -----------------------------------");
    printf("\n\t\t\t\t\t     Enter 6 -> Exit");
    printf("\n\t\t\t\t\t    -----------------\n\t\t\t\t\t\t     ");
}

void addCustomer() {
	FILE *f;
	char test;
	f = fopen("customerData.txt", "a+");
	if(f == NULL) {
		printf("\n\n\n\n\n\n\n\n\t\t\t\t     !!Sorry,Something went wrong!!");
		sleep(1);
	}else {
        printf("\n\t\t\t\t\t.------------------------.");
        printf("\n\t\t\t\t\t|Enter Customer's Details|");
        printf("\n\t\t\t\t\t'------------------------'\n");
        printf("\n Enter Room type(AC/NON-AC):");
        gets(serial.room_type);
        fflush(stdin);
        printf("----------------------------");
        printf("\n Enter Room number:");
        gets(serial.room_no);
        fflush(stdin);
        printf("-------------------");
        printf("\n Enter Name:");
        gets(serial.name);
        fflush(stdin);
        printf("------------");
        printf("\n Enter Address:");
        gets(serial.address);
        fflush(stdin);
        printf("---------------");
        printf("\n Enter Phone Number:");
        gets(serial.phn_no);
        fflush(stdin);
        printf("--------------------");
        printf("\n Enter Email:");
        gets(serial.email);
        fflush(stdin);
        printf("-------------");
        printf("\n Enter Period('x'days):");
        gets(serial.period);
        fflush(stdin);
        printf("----------------------");
        printf("\n Enter Arrival date(dd\\mm\\yyyy):");
        gets(serial.arrival_date);
        fflush(stdin);
        printf("----------------------------------");

        fwrite(&serial, sizeof(serial), 1, f);
        fflush(stdin);
        printf("\n\n\t\t\t\t   !!Your Room is successfully booked!!\n");
        fclose(f);
        getch();
	}
	system("cls");
	showMenu();
}

void viewRecord() {
    FILE *f;
    f = fopen("customerData.txt", "r");

    if(f == NULL) {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t   !!Sorry, there are no customers!!");
        sleep(1);
    }else {
        int i = 1;
        while(fread(&serial, sizeof(serial), 1, f) == 1) {
            printf("\n\t\t\t\t\t_-|Customer %d data|-_\n\n",i);
            printf("\n Room type: %s", serial.room_type);
            printf("\n-----------");
            printf("\n Room number: %s", serial.room_no);
            printf("\n-------------");
            printf("\n Name: %s", serial.name);
            printf("\n------");
            printf("\n Address: %s", serial.address);
            printf("\n---------");
            printf("\n Phone Number: %s", serial.phn_no);
            printf("\n--------------");
            printf("\n Email: %s", serial.email);
            printf("\n-------");
            printf("\n Period: %s", serial.period);
            printf("\n--------");
            printf("\n Arrival date: %s", serial.arrival_date);
            printf("\n--------------");
            i++;
        }
        fclose(f);
        getch();
    }
    system("cls");
    showMenu();
}

void deleteCustomer() {
	FILE *f, *t;
	char roomnumber[20];

	f = fopen("customerData.txt", "r");
	t = fopen("temp.txt", "a+");

	if(f == NULL) {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t   !!Sorry, there are no customers!!");
        sleep(1);
    }else if(t == NULL) {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t     !!Sorry,Something went wrong!!");
		sleep(1);
    }else {
        printf("\n\t\t\t\t Enter room number of the customer");
        printf("\n\t\t\t\t ----------------------------------\n\t\t\t\t\t       ");
        gets(roomnumber);
        fflush(stdin);

        while(fread(&serial, sizeof(serial), 1, f)) {
            if(strcmp(serial.room_no,roomnumber) != 0) {
                fwrite(&serial, sizeof(serial), 1, t);
            }
        }
        if(strcmp(serial.room_no,roomnumber) == 0) {
            printf("\n\n\n\n\n\t\t\t     !!The Customer is successfully removed!!");
        }else {
            printf("\n\n\n\n\n\t\t\t\t!!There is no customer in the room!!");
        }
        fclose(f);
        fclose(t);
        remove("customerData.txt");
        rename("temp.txt","customerData.txt");
        getch();
    }
	system("cls");
	showMenu();

}

void searchCustomer() {
    FILE *f;
    char roomnumber[10];
    int foundCustomar = 0;

    f = fopen("customerData.txt", "r+");
    if(f == NULL) {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t   !!Sorry, there are no customers!!");
        sleep(1);
    }else {
        printf("\n\t\t\t\t Enter room number of the customer");
        printf("\n\t\t\t\t ----------------------------------\n\t\t\t\t\t       ");
        gets(roomnumber);
        fflush(stdin);
        system("cls");

        while(fread(&serial, sizeof(serial), 1, f) == 1) {
            if(strcmp(serial.room_no, roomnumber)==0){
                printf("\n\t\t\t\t _-|Searched Customer's details|-_\n");
                printf("\n Room type: %s", serial.room_type);
                printf("\n-----------");
                printf("\n Room number: %s", serial.room_no);
                printf("\n-------------");
                printf("\n Name: %s", serial.name);
                printf("\n------");
                printf("\n Address: %s", serial.address);
                printf("\n---------");
                printf("\n Phone Number: %s", serial.phn_no);
                printf("\n--------------");
                printf("\n Email: %s", serial.email);
                printf("\n-------");
                printf("\n Period: %s", serial.period);
                printf("\n--------");
                printf("\n Arrival date: %s", serial.arrival_date);
                printf("\n--------------");
                foundCustomar = 1;
                break;
            }
        }
        if(foundCustomar == 0) {
            printf("\n\n\n\n\n\n\n\n\t\t\t\t   !!Searched Customer is not found!!");
            printf("\n\n\n\n\t\t\t\t    Enter any key to go back to manu\n\t\t\t\t\t\t   ");
        }
        fclose(f);
        getch();
    }
	system("cls");
	showMenu();
}
