// Code written by:
//     Divyam Dubey
//     Roll no. 201210016

// LIBRARY MANAGEMENT SYSTEM USING FILE HANDLING IN C

// Headers file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Structure
struct record
{
    int rollno;
    char name[20];
    int bookid;
    char bookname[50];
    char issueDate[15];
    char dueDate[15];
};

// User defined functions
void displayMainMenu();
void displaySubMenu1();
void displaySubMenu2();
void addRecord();
void deleteRecord();
void displaySubMenu3();
void displaySubMenu4();

// Main function
int main()
{
    system("clear");
    displayMainMenu();
    return 0;
}

void displayMainMenu()
{

    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t****************************************\n");
    printf("\t\t\t\t\t\t\t* WELCOME TO LIBRARY MANAGEMENT SYSTEM *\n");
    printf("\t\t\t\t\t\t\t****************************************\n");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t\t---------------MAIN MENU----------------\n");
    printf("\t\t\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t\t\t---1. To Display All The Records--------\n");
    printf("\t\t\t\t\t\t\t---2. To Add/Drop Records---------------\n");
    printf("\t\t\t\t\t\t\t---3. To Search A Book------------------\n");
    printf("\t\t\t\t\t\t\t---4. For Fine Calculation--------------\n");
    printf("\t\t\t\t\t\t\t---5. To Exit---------------------------\n");
    printf("\t\t\t\t\t\t\t----------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t-----> Enter your choice : ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        displaySubMenu1();
        break;
    case 2:
        system("clear");
        displaySubMenu2();
        break;
    case 3:
        system("clear");
        displaySubMenu3();
        break;
    case 4:
        system("clear");
        displaySubMenu4();
        break;
    case 5:
        system("clear");
        exit(0);
        break;
    default:
        system("clear");
        printf("\033[1;31m");
        printf("\t\t\t\t\t\t      INVALID CHOICE !!! Choose from OPTION 1 to 5\n");
        printf("\033[1;0m");
        displayMainMenu();
        break;
    }
}

void displaySubMenu1()
{

    FILE *fptr;
    struct record r;

    fptr = fopen("record.txt", "r");
    if (fptr == NULL)
    {
        system("clear");
        printf("\t\t\t\t\t\t          No Record yet, Please Add a record\n");
        addRecord();
    }
    while (fread(&r, sizeof(struct record), 1, fptr))
    {
        printf("\t\t\tRoll no: %d\n", r.rollno);
        printf("\t\t\tName: %s\n", r.name);
        printf("\t\t\tBook ID: %d\n", r.bookid);
        printf("\t\t\tBook Name: %s\n", r.bookname);
        printf("\t\t\tDate of Issue: %s\n", r.issueDate);
        printf("\t\t\tDue Date: %s\n", r.dueDate);
        printf("\t\t\t===================================\n");
    }
    fclose(fptr);

    char any;
    printf("\n\n\t\t\tPress any key for Main Menu: ");
    getchar();
    scanf("%c", &any);
    system("clear");
    displayMainMenu();
}

void displaySubMenu2()
{
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t---------Add/ Drop Record Menu----------\n");
    printf("\t\t\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t\t\t---1. To Add a Record-------------------\n");
    printf("\t\t\t\t\t\t\t---2. To Drop a Record------------------\n");
    printf("\t\t\t\t\t\t\t---3. To Go Back------------------------\n");
    printf("\t\t\t\t\t\t\t----------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t-----> Enter your choice : ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("clear");
        addRecord();
        break;
    case 2:
        system("clear");
        deleteRecord();
        break;
    case 3:
        system("clear");
        displayMainMenu();
        break;
    default:
        system("clear");
        printf("\033[1;31m");
        printf("\t\t\t\t\t\t      INVALID CHOICE !!! Choose from OPTION 1 to 3\n");
        printf("\033[1;0m");
        displaySubMenu2();
        break;
    }
}

void addRecord()
{
    struct record r;
    FILE *fp;

    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t--------------Add a Record--------------\n");
    printf("\t\t\t\t\t\t\tEnter Student's Roll no.: ");
    scanf("%d", &r.rollno);
    printf("\t\t\t\t\t\t\tEnter Student's Name: ");
    scanf("%s", r.name);
    printf("\t\t\t\t\t\t\tEnter the Book ID: ");
    scanf("%d", &r.bookid);
    printf("\t\t\t\t\t\t\tEnter the Name of Book: ");
    scanf("%s", r.bookname);
    printf("\t\t\t\t\t\t\tEnter the Date of Issue(dd/mm/yyyy): ");
    scanf("%s", r.issueDate);
    printf("\t\t\t\t\t\t\tEnter the Due Date(dd/mm/yyyy): ");
    scanf("%s", r.dueDate);

    fp = fopen("record.txt", "a+");
    fwrite(&r, sizeof(struct record), 1, fp);
    fclose(fp);

    char ch;
error:
    getchar();
    printf("\n\t\t\t\t\t\t\tAdd More Record(Press y for yes and n for no):");
    scanf("%c", &ch);
    switch (ch)
    {
    case 'y':
        system("clear");
        addRecord();
        break;
    case 'n':
        system("clear");
        displaySubMenu2();
        break;

    default:
        printf("\t\t\t\t\t\t\tINVALID CHOICE!!!\n");
        goto error;
        break;
    }
}

void deleteRecord()
{
    FILE *fp1, *fp2;
    struct record r;
    int book_id;

    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t------------Delete a Record------------\n");
    printf("\n\t\t\t\t\t\t\tEnter the Unique ID of the Book : ");
    scanf("%d", &book_id);
    getchar();

    fp1 = fopen("record.txt", "r");
    fp2 = fopen("copy.txt", "a+");

    fp1 = fopen("record.txt", "r");
    if (fp1 == NULL)
    {
        system("clear");
        printf("\t\t\t\t\t\t          No Record yet, Please Add a record\n");
        addRecord();
    }
    while (fread(&r, sizeof(struct record), 1, fp1))
    {
        if (r.bookid != book_id)
        {
            fwrite(&r, sizeof(struct record), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("record.txt");
    rename("copy.txt", "record.txt");

    printf("\n\n\n\t\t\t\t\t\t\t---> Press any key to go back: ");
    getchar();
    system("clear");
    displaySubMenu2();
}

void displaySubMenu3()
{
    struct record r;
    FILE *fp;

    int book_id;

    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t------------Search a Record------------\n");
    printf("\n\t\t\t\t\t\t\tEnter the Unique ID of the Book : ");
    scanf("%d", &book_id);

    fp = fopen("record.txt", "r");
    fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        system("clear");
        printf("\t\t\t\t\t\t          No Record yet, Please Add a record\n");
        addRecord();
    }
    while (fread(&r, sizeof(struct record), 1, fp))
    {
        if (r.bookid == book_id)
        {
            printf("\t\t\t\t\t\t\tRecord Found\n");
            printf("\t\t\t\t\t\t\tRoll no: %d\n", r.rollno);
            printf("\t\t\t\t\t\t\tName: %s\n", r.name);
            printf("\t\t\t\t\t\t\tBook ID: %d\n", r.bookid);
            printf("\t\t\t\t\t\t\tBook Name: %s\n", r.bookname);
            printf("\t\t\t\t\t\t\tDate of Issue: %s\n", r.issueDate);
            printf("\t\t\t\t\t\t\tDue Date: %s\n", r.dueDate);
            printf("\t\t\t\t\t\t\t*************************************\n");
        }
    }
    if (book_id != r.bookid)
    {
        printf("\n\t\t\t\t\t\t\tRecord Not Found!!!\n");
    }
    fclose(fp);
    getchar();
    printf("\n\n\t\t\t\t\t\t\tPress any key to Main Menu: ");
    getchar();
    system("clear");
    displayMainMenu();
}

void displaySubMenu4(){
    int dd1, dd2, mm1, mm2, yyyy1, yyyy2;

    struct tm due_date;
    struct tm current_date;

    time_t due_time, current_time;
    double seconds;
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t------------Fine Calculation-----------\n");

    printf("\t\t\t\t\t\t\tEnter Due Date for Issues Book(dd/mm/yyyy): ");
    scanf("%d/%d/%d", &dd1, &mm1, &yyyy1);
    printf("\t\t\t\t\t\t\tEnter the Date of Submission of Book (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &dd2, &mm2, &yyyy2);

    due_date.tm_hour = 0;
    due_date.tm_min = 0;
    due_date.tm_sec = 0;
    due_date.tm_mon = mm1;
    due_date.tm_mday = dd1;
    due_date.tm_year = yyyy1;

    current_date.tm_hour = 0;
    current_date.tm_min = 0;
    current_date.tm_sec = 0;
    current_date.tm_mon = mm2;
    current_date.tm_mday = dd2;
    current_date.tm_year = yyyy2;

    due_time = mktime(&due_date);
    current_time = mktime(&current_date);
    seconds = difftime(current_time, due_time);
    float day = seconds/86400;
    printf("%g days difference\n", day);

    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t------------Fine Calculation-----------\n");
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t-------------------------------------------\n");
    printf("\t\t\t\t\t\t\tDue Date to Submit Book: %d/%d/%d\n", dd1, mm1, yyyy1);
    printf("\t\t\t\t\t\t\tBook Submitted at Date : %d/%d/%d\n", dd2, mm2, yyyy2);
    if(day <= 0){
    printf("\t\t\t\t\t\t\t===========================================\n");
    printf("\t\t\t\t\t\t\tBook is Submitted Before Due Date\n");
    printf("\t\t\t\t\t\t\tFine                   : Rupess: 0\n");
    printf("\n\n\t\t\t\t\t\t\tPress any key: ");
    getchar();
    getchar();
    system("clear");
    displayMainMenu();
    }else{
    printf("\t\t\t\t\t\t\t===========================================\n");
    printf("\t\t\t\t\t\t\tBook is Submitted %g Days late\n", day);
    printf("\t\t\t\t\t\t\tFine : %gX(4rupees per day) : %g Rupees Only\n", day, day*4);
    printf("\n\n\t\t\t\t\t\t\tPress any key: ");
    getchar();
    getchar();
    system("clear");
    displayMainMenu();

    }
}