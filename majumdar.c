#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// functin declaration

// primary function
void menu();
int auth();

// managing projects functions
void manageProject();
void createProject();
void saveProject();
void viewAllProject();
void updateProject();
void deleteProject();

// managing expenses functions
void manageExpense();
void addNewExpense();
void saveExpenseInfo();
void viewAllExpenses();
void updateExpenseInfo();
void deleteExpenseInfo();

// managing feeding history functions
void manageFeedHistory();
void addNewFHistory();
void saveFHistoryInfo();
void viewAllFHistory();
void updateFHistoryInfo();
void deleteFHistoryInfo();

// managing employee functions
void manageEmployee();
void addNewEmployee();
void saveEmployeeInfo();
void viewAllEmployee();
void updateEmployeeInfo();
void deleteEmployeeInfo();

// managing sells functions
void manageSale();
void addNewSell();
void saveSaleInfo();
void viewAllSales();
void updateSellsInfo();
void deleteSellsInfo();

// generate reports functions
void generateReport();
// price estimate calculations
void priceEstimate();

// defining ftructure
struct Projects
{
    int id;
    float estBudget;
    char projectName[50], projectType[10], description[100], startDate[15], endDate[15];
};

// Expense structure
struct Expense
{
    int id, projectId;
    float amount;
    char date[30], productOrService[20], supplierInfo[25];
};

// FeedingHistory structure
struct FeedingHistory
{
    int id, projectId;
    float quantity;
    char date[10], time[10], foodCategory[10];
};

// Employee structure
struct Employee
{
    int id, phoneNumber;
    float salary;
    char name[50], address[50], email[25];
};

// SellsInfo structure
struct SellsInfo
{
    int id, projectId;
    float amount, quantity;
    char productName[20], date[10];
};

// declaring file pointer for CRUD operation
FILE *fileToOperate;

// declaring a structure variable
struct Projects projectInfo;
struct Expense expenseInfo;
struct FeedingHistory fHistoryInfo;
struct Employee employeeInfo;
struct SellsInfo sellsInfo;

// main function of the program
int main()
{

login:
    if (auth() == 0)
    {
        menu();
    }
    else
    {
        printf("Incorrect password\n");
        goto login;
    }

    return 0;
}

// function for main menu
void menu()
{
    system("cls");
    printf("\n\n\n **** Mazumdar's Agro & Frishries Admin Panel. **** \n\t1. Manage Projects  \n\t2. Manage Purchases.\n\t3. Manage Feeding History. \n\t4. Manage Employee \n\t5. Manage Sells \n\t6. Generate Report \n\t7. Price Estimation \n\t0. Exit.");
    printf("\n\nChoose the options what you want to do (1/2/3/4/5/6/7/0): ");

    int userChoice;

    scanf("%d", &userChoice);

menuinput:
    switch (userChoice)
    {
    case 1:
        manageProject();
        break;
    case 2:
        manageExpense();
        break;
    case 3:
        manageFeedHistory();
        break;
    case 4:
        manageEmployee();
        break;
    case 5:
        manageSale();
        break;
    case 6:
        generateReport();
        break;
    case 7:
        priceEstimate();
        break;
    case 0:
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
        break;

    default:
        printf("Invalid choice. Please enter valid choice:");
        goto menuinput;
    }
}

// function to ensure security
int auth()
{
    char fixedPassword[15] = "12345";
    char userPassword[15];
    printf("Enter Password: ");
    fflush(stdin);
    gets(userPassword);

    return strcmp(userPassword, fixedPassword);
}

// Submenu section

void manageProject()
{

    //
    printf("\n\n****** Mazumdar's Agro & Fisheries Admin Panel ******\n");
    printf("1. Create new project\n");
    printf("2. View All Projects\n");
    printf("3. Update your project\n");
    printf("4. Delete your project\n");
    printf("0. Back to Main Menu\n");
    int userChoice;

    // user input
    printf("Choose: ");

subInput:
    fflush(stdin);
    scanf("%d", &userChoice);

    switch (userChoice)
    {
    case 1:
        createProject();
        break;
    case 2:
        viewAllProject();
        break;
    case 3:
        updateProject();
        break;
    case 4:
        deleteProject();
        break;
    case 0:
        menu();
        break;

    default:
        printf("Invalid choice! \nEnter valid choice: ");
        goto subInput;
    }
}

void createProject()
{
    system("cls");
    struct Projects pr;

    printf("\n\n****** Mazumdar's Agro & Fisheries Admin Panel ******  \n");

    printf("\nProvide all necessary information about the project\n\n");
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &projectInfo.id);
    printf("Please Enter Project Type (Fish/Poultry): ");
    fflush(stdin);
    gets(projectInfo.projectType);
    printf("Please Enter Project Name/Title: ");
    fflush(stdin);
    gets(projectInfo.projectName);
    printf("Please Provide Short Details About Projcet: ");
    fflush(stdin);
    gets(projectInfo.description);
    printf("Please Enter Project Start Date: ");
    fflush(stdin);
    gets(projectInfo.startDate);
    printf("Please Enter Project End Date: ");
    fflush(stdin);
    gets(projectInfo.endDate);
    printf("Please Enter the Estimated Budget: ");
    fflush(stdin);
    scanf("%d", &projectInfo.estBudget);

    saveProject();

add_record:
    printf("\n\t\t\t1.Do You Want To Add nnother new Project info?\n\t\t\t0.Project Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        createProject();
    }
    else if (choice == 0)
    {
        manageProject();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record;
    }
}

void saveProject()
{
    fileToOperate = fopen("projectinfo.txt", "a");
    fwrite(&projectInfo, sizeof(struct Projects), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("Succesfully saved");
    }
    else
    {
        printf("Something went wrong");
    }
    fclose(fileToOperate);
}

void viewAllProject()
{
    system("cls");
    fileToOperate = fopen("projectinfo.txt", "r");
    printf("\n*#$All Project Information$#*\n");
    printf(" **Project ID** \t**Project Title** \t**Start Date** \t**End Date**");

    while (fread(&projectInfo, sizeof(struct Projects), 1, fileToOperate))
    {
        printf("\n%d\t\t%s\t\t%s\t\t%s\n", projectInfo.id, projectInfo.projectName, projectInfo.startDate, projectInfo.endDate);
    }
    fclose(fileToOperate);

add_record1:
    printf("\n\t\t\t1.Project Menu\n\t\t\t2.Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        manageProject();
        break;
    case 2:
        menu();
        break;
    case 3:
        exit(0);
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record1;
        break;
    }
}

void updateProject()
{
    system("cls");
    printf("\n Update Project Information\n");

    printf("Please enter project id you want to modify: ");
    int pId;
    fflush(stdin);
    scanf("%d", &pId);
    fileToOperate = fopen("projectInfo.txt", "r+");
    int found = 0;
    while (fread(&projectInfo, sizeof(struct Projects), 1, fileToOperate))
    {
        if (projectInfo.id == pId)
        {
            found = 1;
            printf("\nProvide all necessary information about the project\n\n");
            printf("Please Enter Project Type (Fish/Poultry): ");
            fflush(stdin);
            gets(projectInfo.projectType);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &projectInfo.id);
            printf("Please Enter Project Name/Title: ");
            fflush(stdin);
            gets(projectInfo.projectName);
            printf("Please Provide Short Details About Project: ");
            fflush(stdin);
            gets(projectInfo.description);
            printf("Please Enter Project Start Date: ");
            fflush(stdin);
            gets(projectInfo.startDate);
            printf("Please Enter Project End Date: ");
            fflush(stdin);
            gets(projectInfo.endDate);
            printf("Please Enter the Estimated Budget: ");
            fflush(stdin);
            scanf("%f", &projectInfo.estBudget);
            fseek(fileToOperate, -sizeof(projectInfo), SEEK_CUR);
            fwrite(&projectInfo, sizeof(struct Projects), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nProject information updated\n");
    }
    else
    {
        printf("\nProject with the given IID  not found in file\n");
    }

updateSub:
    printf("\n\t\t\t1. Do You Want To Modify Another Project info?\n\t\t\t2. Project Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        updateProject();
        break;
    case 2:
        manageProject();
        break;
    case 3:
        menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto updateSub;
        break;
    }
}

void deleteProject()
{
    FILE *removeFile;

    int pId;
    printf("Enter The project id :");
    fflush(stdin);
    scanf("%d", &pId);

    fileToOperate = fopen("projectInfo.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&projectInfo, sizeof(struct Projects), 1, fileToOperate))
    {
        if (projectInfo.id != pId)
        {
            fwrite(&projectInfo, sizeof(struct Projects), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("projectInfo.txt");
    rename("temp.txt", "projectInfo.txt");

    printf("\nProject Info  Successfully Deleted\n");

deleteSub:
    printf("\n\t\t\t1. Do You Want To delete Another  Project info?\n\t\t\t2. Project Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        deleteProject();
        break;
    case 2:
        manageProject();
        break;
    case 3:
        menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto deleteSub;
        break;
    }
}
// manage projects ends here

// Functions of expense management starts here

// expense menu function
void manageExpense()
{
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n\n");
    printf("1. Add an Expense\n");
    printf("2. View all Expenses\n");
    printf("3. Update existing expense info\n");
    printf("4. Delete a expense\n");
    printf("0. Back to Main Menu\n\n");

expenseMenu:
    printf("Choose the Option(A/B/C/D/E): ");

    // Choose User Input
    fflush(stdin);
    int menuChoice;
    scanf("%d", &menuChoice);

    switch (menuChoice)
    {
    case 1:
        addNewExpense();
        break;
    case 2:
        viewAllExpenses();
        break;
    case 3:
        updateExpenseInfo();
        break;
    case 4:
        deleteExpenseInfo();
        break;
    case 0:
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto expenseMenu;
    }
}

// add new expense info function
void addNewExpense()
{
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n\n");

    printf("\nProvide all necessary information about the expense\n\n");
    printf("Please Enter Expense ID: ");
    fflush(stdin);
    scanf("%d", &expenseInfo.id);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &expenseInfo.projectId);
    printf("Please Enter Product/Service Type: ");
    fflush(stdin);
    gets(expenseInfo.productOrService);
    printf("Please Enter Supplier Info: ");
    fflush(stdin);
    gets(expenseInfo.supplierInfo);
    printf("Please Enter Date: ");
    fflush(stdin);
    gets(expenseInfo.date);
    printf("Please Enter the Amount(BDT): ");
    fflush(stdin);
    scanf("%f", &expenseInfo.amount);

    saveExpenseInfo();

subMenu:
    printf("\n\t\t\t1. Do You Want To Add Another new Expense info?\n\t\t\t2. Expense Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        addNewExpense();
        break;
    case 2:
        manageExpense();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto subMenu;
        break;
    }
}

// save expense info function
void saveExpenseInfo()
{
    fileToOperate = fopen("expenseData.txt", "a");
    fwrite(&expenseInfo, sizeof(struct Expense), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all expenses function
void viewAllExpenses()
{
    system("cls");

    printf("\n\n\t\t\t***** All Expenses List *****\n\n");
    printf(" **Expense ID** \tProject ID** \t**Product/Service** \t**Amount(BDT)** \t**Date**");

    fileToOperate = fopen("expenseData.txt", "r");
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        printf("\n\n\t%d\t\t\t%d\t\t%s\t\t%.2f\t\t\t%s\n", expenseInfo.id, expenseInfo.projectId, expenseInfo.productOrService, expenseInfo.amount, expenseInfo.date);
    }
    fclose(fileToOperate);

viewSub:
    printf("\n\t\t\t1. Expense Menu\n\t\t\t2. Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        manageExpense();
        break;
    case 2:
        menu();
        break;
    case 3:
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto viewSub;
        break;
    }
}

// update expense info function
void updateExpenseInfo()
{
    system("cls");
    printf("\n Update Project Information\n");

    printf("Please enter project id you want to modify: ");
    int eId;
    fflush(stdin);
    scanf("%d", &eId);
    fileToOperate = fopen("expenseData.txt", "r+");
    int found = 0;
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.id == eId)
        {
            found = 1;
            printf("\nProvide all necessary information about the expense\n\n");
            printf("Please Enter Expense ID: ");
            fflush(stdin);
            scanf("%d", &expenseInfo.id);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &expenseInfo.projectId);
            printf("Please Enter Product/Service Type: ");
            fflush(stdin);
            gets(expenseInfo.productOrService);
            printf("Please Enter Supplier Info: ");
            fflush(stdin);
            gets(expenseInfo.supplierInfo);
            printf("Please Enter Date: ");
            fflush(stdin);
            gets(expenseInfo.date);
            printf("Please Enter the Amount(BDT): ");
            fflush(stdin);
            scanf("%f", &expenseInfo.amount);

            fseek(fileToOperate, -sizeof(expenseInfo), SEEK_CUR);
            fwrite(&expenseInfo, sizeof(struct Expense), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nExpense information updated\n");
    }
    else
    {
        printf("\nExpense with the given ID  not found in file\n");
    }

updateSub:
    printf("\n\t\t\t1. Do You Want To Modify Another Expense info?\n\t\t\t2. Expense Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        updateFHistoryInfo();
        break;
    case 2:
        manageFeedHistory();
        break;
    case 3:
        menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto updateSub;
        break;
    }
}

// delete expense info fuction
void deleteExpenseInfo()
{
    FILE *removeFile;

    int pId;
    printf("Enter The Expense Id :");
    fflush(stdin);
    scanf("%d", &pId);

    fileToOperate = fopen("expenseData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.id != pId)
        {
            fwrite(&expenseInfo, sizeof(struct Expense), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("expenseData.txt");
    rename("temp.txt", "expenseData.txt");
    system("cls");
    printf("\nExpense Info  Successfully Deleted\n");

deleteSub:
    printf("\n\t\t\t1. Do You Want To delete Another Expense info?\n\t\t\t2. Expense Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        deleteExpenseInfo();
        break;
    case 2:
        manageExpense();
        break;
    case 3:
        menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto deleteSub;
        break;
    }
}
// functions of expense management ends here

// functions of feeding history management starts here

// fHistory menu function
void manageFeedHistory()
{
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n\n");
    printf("1. Add a Feeding History\n");
    printf("2. View all Feeding History\n");
    printf("3. Update a Feeding History info\n");
    printf("4. Delete a Feeding History\n");
    printf("0. Back to Main Menu\n\n");

feedHistory:
    printf("Choose the Option(1/2/3/4/0): ");

    // Choose User Input
    fflush(stdin);
    int menuChoice;
    scanf("%d", &menuChoice);

    switch (menuChoice)
    {
    case 1:
        addNewFHistory();
        break;
    case 2:
        viewAllFHistory();
        break;
    case 3:
        updateFHistoryInfo();
        break;
    case 4:
        deleteFHistoryInfo();
        break;
    case 5:
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto feedHistory;
    }
}

// add new fHistory info function
void addNewFHistory()
{
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n\n");

    printf("\nProvide all necessary information about the expense\n\n");
    printf("Please Enter Feeding History ID: ");
    fflush(stdin);
    scanf("%d", &fHistoryInfo.id);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &fHistoryInfo.projectId);
    printf("Please Enter Quantity(KG): ");
    fflush(stdin);
    scanf("%f", &fHistoryInfo.quantity);
    printf("Please Enter Food Category: ");
    fflush(stdin);
    gets(fHistoryInfo.foodCategory);
    printf("Please Enter Date: ");
    fflush(stdin);
    gets(fHistoryInfo.date);
    printf("Please Enter Time: ");
    fflush(stdin);
    gets(fHistoryInfo.time);

    saveFHistoryInfo();

subMenu:
    printf("\n\t\t\t1.Do You Want To Add Another new Feeding History info?\n\t\t\t2.Feeding History Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        addNewFHistory();
        break;
    case 2:
        manageFeedHistory();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto subMenu;
        break;
    }
}

// save fHistory info function
void saveFHistoryInfo()
{
    fileToOperate = fopen("fHistoryData.txt", "a");
    fwrite(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all expenses function
void viewAllFHistory()
{
    system("cls");
    printf("\n\n\t\t\t\t\t***** All Feeding History List *****\n\n");
    printf(" **Feeding History ID** \tProject ID** \t**Quantity** \t**Food Category** \t**Date**");

    fileToOperate = fopen("fHistoryData.txt", "r");
    while (fread(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        printf("\n\n\t%d\t\t\t%d\t\t%.2f\t\t\t%s\t\t%s\n", fHistoryInfo.id, fHistoryInfo.projectId, fHistoryInfo.quantity, fHistoryInfo.foodCategory, fHistoryInfo.date);
    }
    fclose(fileToOperate);

viewSub:
    printf("\n\t\t\t1. Feeding History Menu\n\t\t\t2. Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        manageFeedHistory();
        break;
    case 2:
        menu();
        break;
    case 3:
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto viewSub;
        break;
    }
}

// update fHistory info function
void updateFHistoryInfo()
{
    system("cls");
    printf("\n Update Project Information\n");

    printf("Please enter project id you want to modify: ");
    int fhId;
    fflush(stdin);
    scanf("%d", &fhId);
    fileToOperate = fopen("fHistoryData.txt", "r+");
    int found = 0;
    while (fread(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        if (fHistoryInfo.id == fhId)
        {
            found = 1;
            printf("\nProvide all necessary information about the expense\n\n");
            printf("Please Enter Feeding History ID: ");
            fflush(stdin);
            scanf("%d", &fHistoryInfo.id);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &fHistoryInfo.projectId);
            printf("Please Enter Quantity: ");
            fflush(stdin);
            scanf("%f", &fHistoryInfo.quantity);
            printf("Please Enter Food Category: ");
            fflush(stdin);
            gets(fHistoryInfo.foodCategory);
            printf("Please Enter Date: ");
            fflush(stdin);
            gets(fHistoryInfo.date);
            printf("Please Enter Time: ");
            fflush(stdin);
            gets(fHistoryInfo.time);

            fseek(fileToOperate, -sizeof(fHistoryInfo), SEEK_CUR);
            fwrite(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nFeeding History information updated\n");
    }
    else
    {
        printf("\nFeeding History with the given ID  not found in file\n");
    }

updateSub:
    printf("\n\t\t\t1. Do You Want To Modify Another Feeding History info?\n\t\t\t2. Feeding History Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        updateFHistoryInfo();
        break;
    case 2:
        manageFeedHistory();
        break;
    case 3:
        menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto updateSub;
        break;
    }
}

// delete fHistory info fuction
void deleteFHistoryInfo()
{
    FILE *removeFile;

    int fHId;
    printf("Enter The Feeding History Id :");
    fflush(stdin);
    scanf("%d", &fHId);

    fileToOperate = fopen("fHistoryData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        if (fHistoryInfo.id != fHId)
        {
            fwrite(&fHistoryInfo, sizeof(struct FeedingHistory), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("fHistoryData.txt");
    rename("temp.txt", "fHistoryData.txt");
    system("cls");
    printf("\nFeeding History Info  Successfully Deleted\n");

deleteSub:
    printf("\n\t\t\t1. Do You Want To delete Another Feeding History info?\n\t\t\t2. Feeding History Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        deleteFHistoryInfo();
        break;
    case 2:
        manageFeedHistory();
        break;
    case 3:
        menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto deleteSub;
        break;
    }
}
// functions of feeding history management ends here

// functions of employee management starts here

//  employee menu function
void manageEmployee()
{
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n\n");
    printf("1. Add A New Employee\n");
    printf("2. View all Employees\n");
    printf("3. Update An Existing Employee Info\n");
    printf("4. Delete an Employee Info\n");
    printf("0. Back to Main Menu\n\n");

empMenu:
    printf("Choose the Option(1/2/3/4/0): ");

    // Choose User Input
    fflush(stdin);
    int menuChoice;
    scanf("%d", &menuChoice);

    switch (menuChoice)
    {
    case 1:
        addNewEmployee();
        break;
    case 2:
        viewAllEmployee();
        break;
    case 3:
        updateEmployeeInfo();
        break;
    case 4:
        deleteEmployeeInfo();
        break;
    case 0:
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto empMenu;
    }
}

// add new employee info function
void addNewEmployee()
{
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n\n");

    printf("\nProvide all necessary information about the Employee\n\n");
    printf("Please Enter Employee ID: ");
    fflush(stdin);
    scanf("%d", &employeeInfo.id);
    printf("Please Enter Employee Name: ");
    fflush(stdin);
    gets(employeeInfo.name);
    printf("Please Enter Employee Email: ");
    fflush(stdin);
    gets(employeeInfo.email);
    printf("Please Enter Employee Phone-number: ");
    fflush(stdin);
    scanf("%d", &employeeInfo.phoneNumber);
    printf("Please Enter Employee Salary: ");
    fflush(stdin);
    scanf("%f", &employeeInfo.salary);

    saveEmployeeInfo();

subMenu:
    printf("\n\t\t\t1.Do You Want To Add Another new Employee info?\n\t\t\t2.Employee Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        addNewEmployee();
        break;
    case 2:
        manageEmployee();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto subMenu;
        break;
    }
}

// save employee info function
void saveEmployeeInfo()
{
    fileToOperate = fopen("employeeData.txt", "a");
    fwrite(&employeeInfo, sizeof(struct Employee), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all employee function
void viewAllEmployee()
{
    system("cls");

    printf("\n\n\t\t\t***** All Employee List *****\n\n");
    printf(" **Expense ID** \t Name** \t**Phone Number** \t**Email** \t\t**Salary**");

    fileToOperate = fopen("employeeData.txt", "r");
    while (fread(&employeeInfo, sizeof(struct Employee), 1, fileToOperate))
    {
        printf("\n\n\t%d\t\t%s\t\t0%d\t\t%s\t\t%.2f\n", employeeInfo.id, employeeInfo.name, employeeInfo.phoneNumber, employeeInfo.email, employeeInfo.salary);
    }
    fclose(fileToOperate);

viewSub:
    printf("\n\t\t\t1. Employee Menu\n\t\t\t2. Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        manageEmployee();
        break;
    case 2:
        menu();
        break;
    case 3:
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto viewSub;
        break;
    }
}

// update employee info function
void updateEmployeeInfo()
{
    system("cls");
    printf("\n Update Project Information\n");

    int eId;
    printf("Please enter Employee id you want to modify: ");
    fflush(stdin);
    scanf("%d", &eId);
    fileToOperate = fopen("employeeData.txt", "r+");
    int found = 0;
    while (fread(&employeeInfo, sizeof(struct Employee), 1, fileToOperate))
    {
        if (employeeInfo.id == eId)
        {
            found = 1;
            printf("\nProvide all necessary information about the Employee\n\n");
            printf("Please Enter Employee ID: ");
            fflush(stdin);
            scanf("%d", &employeeInfo.id);
            printf("Please Enter Employee Name: ");
            fflush(stdin);
            gets(employeeInfo.name);
            printf("Please Enter Employee Email: ");
            fflush(stdin);
            gets(employeeInfo.email);
            printf("Please Enter Employee Phone-number: ");
            fflush(stdin);
            scanf("%d", &employeeInfo.phoneNumber);
            printf("Please Enter Employee Salary: ");
            fflush(stdin);
            scanf("%f", &employeeInfo.salary);

            fseek(fileToOperate, -sizeof(employeeInfo), SEEK_CUR);
            fwrite(&employeeInfo, sizeof(struct Employee), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nEmployee information updated\n");
    }
    else
    {
        printf("\nEmployee with the given ID  not found in file\n");
    }

updateSub:
    printf("\n\t\t\t1. Do You Want To Modify Another Employee info?\n\t\t\t2. Employee Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        updateEmployeeInfo();
        break;
    case 2:
        manageEmployee();
        break;
    case 3:
        menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto updateSub;
        break;
    }
}

// delete employee info fuction
void deleteEmployeeInfo()
{
    FILE *removeFile;

    int eId;
    printf("Enter The Employee Id :");
    fflush(stdin);
    scanf("%d", &eId);

    fileToOperate = fopen("employeeData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&employeeInfo, sizeof(struct Employee), 1, fileToOperate))
    {
        if (employeeInfo.id != eId)
        {
            fwrite(&employeeInfo, sizeof(struct Employee), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("employeeData.txt");
    rename("temp.txt", "employeeData.txt");
    system("cls");
    printf("\nEmployee Info  Successfully Deleted\n");

deleteSub:
    printf("\n\t\t\t1. Do You Want To delete Another Employee info?\n\t\t\t2. Employee Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        deleteEmployeeInfo();
        break;
    case 2:
        manageEmployee();
        break;
    case 3:
        menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto deleteSub;
        break;
    }
}
// functions of employee management ends here

// functions of sells management start here

//  sells menu function
void manageSale()
{
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n\n");
    printf("1. Add A Selling Info\n");
    printf("2. View All Sells\n");
    printf("3. Update Existing Selling info\n");
    printf("4. Delete A Selling Info\n");
    printf("0. Back to Main Menu\n\n");

returnToSellsMenu:
    printf("Choose the Option(1/2/3/4/0): ");

    // Choose User Input
    fflush(stdin);
    int menuChoice;
    scanf("%d", &menuChoice);

    switch (menuChoice)
    {
    case 1:
        addNewSell();
        break;
    case 2:
        viewAllSales();
        break;
    case 3:
        updateSellsInfo();
        break;
    case 4:
        deleteSellsInfo();
        break;
    case 0:
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToSellsMenu;
    }
}

// add new sells info function
void addNewSell()
{
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n\n");

    printf("\nProvide all necessary information about the Sell\n\n");
    printf("Please Enter Selling Info ID: ");
    fflush(stdin);
    scanf("%d", &sellsInfo.id);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &sellsInfo.projectId);
    printf("Please Enter the Amount(BDT): ");
    fflush(stdin);
    scanf("%f", &sellsInfo.amount);
    printf("Please Enter Product Name: ");
    fflush(stdin);
    gets(sellsInfo.productName);
    printf("Please Enter Quantity: ");
    fflush(stdin);
    scanf("%f", &sellsInfo.quantity);
    printf("Please Enter Date: ");
    fflush(stdin);
    gets(sellsInfo.date);

    saveSaleInfo();

subMenu:
    printf("\n\t\t\t1. Do You Want To Add Another new Selling info?\n\t\t\t2. Sells Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        addNewSell();
        break;
    case 2:
        manageSale();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto subMenu;
        break;
    }
}

// save sells info function
void saveSaleInfo()
{
    fileToOperate = fopen("sellsData.txt", "a");
    fwrite(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// view all sells function
void viewAllSales()
{
    system("cls");

    printf("\n\n\t\t\t***** All Sells List *****\n\n");
    printf(" **Sells ID** \tProduct** \t**Quantity** \t**Amount(BDT)** \t**Date**");

    fileToOperate = fopen("sellsData.txt", "r");
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        printf("\n\n\t%d\t%s\t\t%.2f\t\t%.2f\t\t%s\n", sellsInfo.id, sellsInfo.productName, sellsInfo.quantity, sellsInfo.amount, sellsInfo.date);
    }
    fclose(fileToOperate);

viewSub:
    printf("\n\t\t\t1. Sells Menu\n\t\t\t2. Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        manageSale();
        break;
    case 2:
        menu();
        break;
    case 3:
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto viewSub;
        break;
    }
}

// update sells info function
void updateSellsInfo()
{
    system("cls");
    printf("\n Update Project Information\n");

    int sId;
    printf("Please enter project id you want to modify: ");
    fflush(stdin);
    scanf("%d", &sId);
    fileToOperate = fopen("sellsData.txt", "r+");
    int found = 0;
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.id == sId)
        {
            found = 1;
            printf("\nProvide all necessary information about the Sell\n\n");
            printf("Please Enter Selling Info ID: ");
            fflush(stdin);
            scanf("%d", &sellsInfo.id);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &sellsInfo.projectId);
            printf("Please Enter the Amount(BDT): ");
            fflush(stdin);
            scanf("%f", &sellsInfo.amount);
            printf("Please Enter Product Name: ");
            fflush(stdin);
            gets(sellsInfo.productName);
            printf("Please Enter Quantity: ");
            fflush(stdin);
            scanf("%f", &sellsInfo.quantity);
            printf("Please Enter Date: ");
            fflush(stdin);
            gets(sellsInfo.date);

            fseek(fileToOperate, -sizeof(sellsInfo), SEEK_CUR);
            fwrite(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate);
            break;
        }
    }

    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nSelling Info information updated\n");
    }
    else
    {
        printf("\nSelling Info with the given ID  not found in file\n");
    }

updateSub:
    printf("\n\t\t\t1. Do You Want To Modify Another Selling Info info?\n\t\t\t2. Sells Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        updateSellsInfo();
        break;
    case 2:
        manageSale();
        break;
    case 3:
        menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto updateSub;
        break;
    }

    if (choice == 1)
    {
        updateSellsInfo();
    }
    else if (choice == 2)
    {
        manageSale();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto updateSub;
    }
}

// delete sells info fuction
void deleteSellsInfo()
{
    FILE *removeFile;

    int sId;
    printf("Enter The Selling Info Id :");
    fflush(stdin);
    scanf("%d", &sId);

    fileToOperate = fopen("sellsData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.id != sId)
        {
            fwrite(&sellsInfo, sizeof(struct SellsInfo), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("sellsData.txt");
    rename("temp.txt", "sellsData.txt");
    system("cls");
    printf("\nSelling Info  Successfully Deleted\n");

deleteSub:
    printf("\n\t\t\t1. Do You Want To delete Another Selling info?\n\t\t\t2. Sells Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        deleteSellsInfo();
        break;
    case 2:
        manageSale();
        break;
    case 3:
        menu();
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto deleteSub;
        break;
    }
}
// functions of sells management ends here

// functions of report generation

void generateReport()
{
    system("cls");

    int pId;
    float totalExpenses = 0, totalSells = 0, totalFeed = 0;
    printf("\n\nPlease enter project id you want to Generate Report: ");
    fflush(stdin);
    scanf("%d", &pId);

    printf("\n\n\t\t\t***** Project Report *****\n\n");

    fileToOperate = fopen("expenseData.txt", "r");
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.projectId == pId)
        {
            totalExpenses += expenseInfo.amount;
        }
    }
    fclose(fileToOperate);

    fileToOperate = fopen("sellsData.txt", "r");
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.projectId == pId)
        {
            totalSells += sellsInfo.amount;
        }
    }
    fclose(fileToOperate);

    fileToOperate = fopen("fHistoryData.txt", "r");
    while (fread(&fHistoryInfo, sizeof(struct FeedingHistory), 1, fileToOperate))
    {
        if (fHistoryInfo.projectId == pId)
        {
            totalFeed += fHistoryInfo.quantity;
        }
    }
    fclose(fileToOperate);

    printf("\n\tProject Id : %d\n", pId);
    printf("\n\tProject Total Feed Give : %.2f KG\n", totalFeed);
    printf("\n\tProject Total Sells : %.2f(BDT)\n", totalSells);
    printf("\n\tProject Total Expenses : %.2f(BDT)\n", totalExpenses);
    if (totalSells - totalExpenses > 0)
    {
        printf("\n\tNET Profit : %.2f (BDT)\n", totalSells - totalExpenses);
    }
    else
    {
        printf("\n\tNET Loss : %.2f (BDT)\n", totalExpenses - totalSells);
    }

reportSub:
    printf("\n\t\t\t1. Do You Want To Generate Report For Another Project?\n\t\t\t2. Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        generateReport();
        break;
    case 2:
        menu();
        break;
    case 3:
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto reportSub;
        break;
    }
}

void priceEstimate()
{
    system("cls");

    int pId;
    float percentage;
    char sign;
    float totalExpenses = 0, totalSells = 0;
    float lossOrProfit;

    printf("\n\nPlease enter Project Id you want to estimate price: ");
    fflush(stdin);
    scanf("%d", &pId);

    printf("\nPlease enter the Percentage you to make profit(X%%): ");
    fflush(stdin);
    scanf("%f%c", &percentage, &sign);

    fileToOperate = fopen("expenseData.txt", "r");
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        if (expenseInfo.projectId == pId)
        {
            totalExpenses += expenseInfo.amount;
        }
    }
    fclose(fileToOperate);

    fileToOperate = fopen("sellsData.txt", "r");
    while (fread(&sellsInfo, sizeof(struct SellsInfo), 1, fileToOperate))
    {
        if (sellsInfo.projectId == pId)
        {
            totalSells += sellsInfo.amount;
        }
    }
    fclose(fileToOperate);

    lossOrProfit = (totalExpenses + (totalExpenses * (percentage / 100))) - totalSells;

    printf("\n\n\t\t\t***** Price Estimation *****\n\n");
    printf("\n\tProject Id : %d\n", pId);
    printf("\n\tProject Total Sells Till Now : %.2f(BDT)\n", totalSells);
    printf("\n\tProject Total Expenses Till Now : %.2f(BDT)\n", totalExpenses);

    if (lossOrProfit > 0)
    {
        printf("\n\tTo do a profit of %.2f%% you need to have more %.2f (BDT) sells from this project.\n", percentage, lossOrProfit);
    }
    else
    {
        printf("\n\tThe Project is already in profit of %.2f (BDT)\n\n", lossOrProfit * -1);
    }

reportSub:
    printf("\n\t\t\t1. Do You Want To Estimate Price For Another Project?\n\t\t\t2. Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        priceEstimate();
        break;
    case 2:
        menu();
        break;
    case 3:
        system("cls");
        printf("\n\n\t\t***** Thank You !! *****\n\n");
        exit(0);
        break;

    default:
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto reportSub;
        break;
    }
}