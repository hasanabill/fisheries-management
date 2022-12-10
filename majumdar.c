#include <stdio.h>
#include <string.h>

// functin declaration
void menu();
int auth();
void submenu();
void projectMenu();
void addNewProject();
void saveProjectInfo();
void viewAllProjectInfo();

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

void menu()
{
    system("cls");
    printf("\n\n\n **** Mazumdar's Agro & Frishries Admin Panel. **** \n   1. Manage Projects  \n   2. Manage Purchases.\n   2. Manage Feeding History. \n   4. Staffs. \n   5. Back to home page.\n   6. Exit.");
    printf("\n\nChoose the options what you want to do (1/2/3/4/5/6): ");

    int userChoice;

    scanf("%d", &userChoice);

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
        submenu();
        break;
    case 6:
        submenu();
        break;

    default:
        printf("Invalid choice");
    }
}

// function to ensure security
int auth()
{
    char fixedPassword[15] = "12346789";
    char userPassword[15];
    printf("Enter Password: ");
    fflush(stdin);
    gets(userPassword);

    return strcmp(userPassword, fixedPassword);
}

// Submenu section

void manageProject()
{
    printf("****** Sub Menu ******\n");
    printf("1. Create new project\n");
    printf("2. View All Projects\n");
    printf("3. Update your project\n");
    printf("4. Delete your project\n");
    printf("5. Back to Main Menu\n");

    int userChoice;
    scanf("%d", &userChoice);

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

    default:
        printf("Invalid choice");
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

struct manage_project
{
    char code[10];
    char name[30];
    char type[10];
    char description[50];
    char start_date[10];
    char end_date[10];
    float est_budget;
};

struct manage_Expenses
{
    char _id[10];
    char date[30];
    char type[12];
    char product_or_service[50];
    char supplier_info[25];
    float amount;
    char project_id[10];
};

struct feed_history
{
    char project_id[10];
    char date[10];
    char time[10];
    float quantity;
    char food_category[30];
};

struct selling
{
    char _id[10];
    char date[10];
    char buyer[30];
    float quantity;
    float unit_price;
    float total_price;
};

struct employee
{
    char _id[10];
    char name[30];
    char address[50];
    int phone_number;
    char email[25];
    float salary;
};
