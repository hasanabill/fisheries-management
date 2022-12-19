#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// functin declaration
void menu();
int auth();
void submenu();

// functions for managing projects
void manageProject();
void createProject();
void saveProject();
void viewAllProject();
void updateProject();
void deleteProject();

// defining ftructure
struct Projects
{
    int id;
    char projectName[50];
    char projectType[10];
    char description[100];
    char startDate[15];
    char endDate[15];
    int estBudget;
};

// declaring file pointer for CRUD operation
FILE *filetooperate;

// declaring a structure variable
struct Projects projectInfo;

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
        submenu();
        break;
    case 3:
        submenu();
        break;
    case 4:
        submenu();
        break;
    case 5:
        menu();
        break;
    case 0:
        submenu();
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
void submenu()
{
    printf("****** Sub Menu ******\n");
    printf("1. Create new project\n");
    printf("2. View All Projects\n");
    printf("3. Update your project\n");
    printf("4. Delete your project\n");
    int userChoice;
    scanf("%d", &userChoice);

    if (userChoice == 1)
    {
        printf("you choose 1");
    }
    else if (userChoice == 2)
    {
        printf("you choose 2");
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
    filetooperate = fopen("projectinfo.txt", "a");
    fwrite(&projectInfo, sizeof(struct Projects), 1, filetooperate);
    if (fwrite != 0)
    {
        printf("Succesfully saved");
    }
    else
    {
        printf("Something went wrong");
    }
    fclose(filetooperate);
}

void viewAllProject()
{
    system("cls");
    filetooperate = fopen("projectinfo.txt", "r");
    printf("\n*#$All Project Information$#*\n");
    printf(" **Project ID** \t**Project Title** \t**Start Date** \t**End Date**");

    while (fread(&projectInfo, sizeof(struct Projects), 1, filetooperate))
    {
        printf("\n%d\t\t%s\t\t%s\t\t%s\n", projectInfo.id, projectInfo.projectName, projectInfo.startDate, projectInfo.endDate);
    }
    fclose(filetooperate);

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
    filetooperate = fopen("projectInfo.txt", "r+");
    int found = 0;
    while (fread(&projectInfo, sizeof(struct Projects), 1, filetooperate))
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
            fseek(filetooperate, -sizeof(projectInfo), SEEK_CUR);
            fwrite(&projectInfo, sizeof(struct Projects), 1, filetooperate);
            break;
        }
    }

    fclose(filetooperate);
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
    if (choice == 1)
    {
        updateProject();
    }
    else if (choice == 2)
    {
        manageProject();
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
void deleteProject()
{
    FILE *removeFile;

    int pId;
    printf("Enter The project id :");
    fflush(stdin);
    scanf("%d", &pId);

    filetooperate = fopen("projectInfo.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (filetooperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&projectInfo, sizeof(struct Projects), 1, filetooperate))
    {
        if (projectInfo.id != pId)
        {
            fwrite(&projectInfo, sizeof(struct Projects), 1, removeFile);
        }
    }

    fclose(filetooperate);
    fclose(removeFile);

    remove("projectInfo.txt");
    rename("temp.txt", "projectInfo.txt");

    printf("\nProject Info  Successfully Deleted\n");

deleteSub:
    printf("\n\t\t\t1. Do You Want To delete Another  Project info?\n\t\t\t2. Project Menu\n\t\t\t3. Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        deleteProject();
    }
    else if (choice == 2)
    {
        manageProject();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto deleteSub;
    }
}