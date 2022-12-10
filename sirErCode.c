#include <stdio.h>
#include <string.h>

// DEFINITION SECTION
void menu();
int authentication();
void projectMenu();
void addNewProject();
void saveProjectInfo();
void viewAllProjectInfo();

// global declaration section
// defining the structure for project info
struct Project
{
    char projectName[50], projectShortDes[100], projectType[30], startDate[15], endDate[15];
    int projectId, estimatedBudget;
};

FILE *filetooperate, *temp_file;
struct Project projectInfo;

int main()
{

    system("cls");
    int choice;
    printf("\n***Mazumdar's Agro & Frisharies***\n");
    printf("let us know; Do you want to login?!!!\n   1. Yes Login\n   2. No\nPlease enter your choice (1/2) : ");
lebel1:
    scanf("%d", &choice);
    if (choice == 1)
    {
    lebel3:
        if (authentication() == 0)
        {
            menu();
        }
        else
        {
            printf("Your password is incorrect. Please Try again.\n");
            goto lebel3;
        }
    }
    else if (choice == 2)
    {
        exit(0);
    }
    else
    {
        printf("\nInvalid Choice. You should enter \"1\" for Login or \"2\" for Exit.\n\nPlease enter your choice again (1/2) : ");
        goto lebel1;
    }
    return 0;
}
void menu()
{
    system("cls");
    int userChoice;
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n    1. Manage Projects.\n");
    printf("    2. Manage Purchases.\n    3. Manage Feeding History.\n    4. Staffs\n");
    printf("    5. Back to Home Page.\n    6. Exit\n");
    printf("Chose the option what you want to do (1/2/3/4/5/6) : ");

lebel2:
    scanf("%d", &userChoice);
    if (userChoice == 1)
    {
        projectMenu();
    }
    else if (userChoice == 2)
    {
    }
    else if (userChoice == 3)
    {
    }
    else if (userChoice == 4)
    {
    }
    else if (userChoice == 5)
    {
    }
    else if (userChoice == 6)
    {
    }
    else
    {
        printf("\nInvalid input. Please enter a valid input : ");
        goto lebel2;
    }
}

void projectMenu()
{
    system("cls");
    char menuChoice;
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");
    printf("A. Create New Project Info\n");
    printf("B. View all project info\n");
    printf("C. Update existing project info\n");
    printf("D.Delete a project info\n");
    printf("E.Back to Main Menu\n");
label4:
    printf("Choose the Option(A/B/C/D/E):");

    // Choose User Input
    fflush(stdin);
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);
    switch (menuChoice)
    {
    case 'A':
        addNewProject();
        break;
    case 'B':
        viewAllProjectInfo();
        break;
    case 'C':
        //
        break;
    case 'D':
        //
        break;
    case 'E':
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto label4;
    }
}
int authentication()
{
    char fixPassword[15] = "12345";
    char userPassword[15];
    printf("\nEnter Password :");
    fflush(stdin);
    gets(userPassword);
    return strcmp(userPassword, fixPassword);
}

void addNewProject()
{
    system("cls");
    struct Project pr;
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");

    printf("\nProvide all necessary information about the project\n\n");
    printf("Please Enter Project Type (Fish/Poultry): ");
    fflush(stdin);
    gets(projectInfo.projectType);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &projectInfo.projectId);
    printf("Please Enter Project Name/Title: ");
    fflush(stdin);
    gets(projectInfo.projectName);
    printf("Please Provide Short Details About Projcet: ");
    fflush(stdin);
    gets(projectInfo.projectShortDes);
    printf("Please Enter Project Start Date: ");
    fflush(stdin);
    gets(projectInfo.startDate);
    printf("Please Enter Project End Date: ");
    fflush(stdin);
    gets(projectInfo.endDate);
    printf("Please Enter the Estimated Budget: ");
    fflush(stdin);
    scanf("%d", &projectInfo.estimatedBudget);

    saveProjectInfo();

add_record:
    printf("\n\t\t\t1.Do You Want To Add Another new Project info?\n\t\t\t0.Project Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        addNewProject();
    }
    else if (choice == 0)
    {
        projectMenu();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record;
    }
}

void saveProjectInfo()
{
    filetooperate = fopen("projectinformation.txt", "a");
    fwrite(&projectInfo, sizeof(struct Project), 1, filetooperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(filetooperate);
}

void viewAllProjectInfo()
{
    system("cls");
    filetooperate = fopen("projectinformation.txt", "r");
    printf("\n*#$All Project Information$#*\n");
    printf(" **Project ID** \t**Project Title** \t**Start Date** \t**End Date**");
    while (fread(&projectInfo, sizeof(struct Project), 1, filetooperate))
    {
        printf("\n%d\t\t%s\t\t%s\t\t%s\n", projectInfo.projectId, projectInfo.projectName, projectInfo.startDate, projectInfo.endDate);
    }
    fclose(filetooperate);

add_record1:
    printf("\n\t\t\t1.Project Menu\n\t\t\t2.Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        projectMenu();
    }
    else if (choice == 2)
    {
        menu();
    }
    else if (choice == 3)
    {
        exit(0);
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record1;
    }
}
