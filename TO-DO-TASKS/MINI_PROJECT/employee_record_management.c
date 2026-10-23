#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};
struct Employee emp[MAX];
int cnt = 0;

//READ INTEGER
int readInt(char msg[]) {
    char input[100];
    int value;
    char extra;

    while (1) {
        printf("%s", msg);

        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d %c", &value, &extra) == 1) {
                return value;
            }
        }
        printf("Invalid input. Please enter a number.\n");
    }
}

//READ FLOAT
float readFloat(char msg[]) {
    char input[100];
    float value;
    char extra;

    while (1) {
        printf("%s", msg);

        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%f %c", &value, &extra) == 1) {
                return value;
            }
        }
        printf("Invalid input. Please enter a valid number.\n");
    }
}

//READ STRING 
void readString(char msg[], char value[], int size, int maxLen) {
    while (1) {
        printf("%s", msg);

        if (fgets(value, size, stdin) != NULL) {
            value[strcspn(value, "\n")] = '\0';
            if (strlen(value) == 0) {
                printf("Input cannot be empty.\n");
                continue;
            }
            if (strlen(value) > maxLen) {
                printf("Please enter maximum %d characters.\n",maxLen);
                continue;
            }
            return;
        }
    }
}

//FIND EMPLOYEE BY ID
int findEmployeeById(int id) {
    int i;
    for (i = 0; i < cnt; i++) {
        if (emp[i].id == id) {
            return i;
        }
    }
    return -1;
}

//DISPLAY ONE EMPLOYEE
void displayEmployee(int Index) {
    printf("\n---------------------------------------------\n");
    printf("Employee ID   : %d\n", emp[Index].id);
    printf("Name          : %s\n", emp[Index].name);
    printf("Department    : %s\n", emp[Index].department);
    printf("Salary        : %.2f\n", emp[Index].salary);
    printf("---------------------------------------------\n");
}

//ADD EMPLOYEE
void addEmployee() {
    struct Employee newEmp;
    if (cnt >= MAX) {
        printf("\nMaximum employee limit reached.\n");
        return;
    }
    printf("\n========== ADD EMPLOYEE ==========\n");
    newEmp.id = readInt("Enter Employee ID: ");

    // CHECKS WHEATHER ID ALREADY EXISTS
    if (findEmployeeById(newEmp.id) != -1) {
        printf("\nEmployee ID already exists.\n");
        return;
    }
    
    readString("Enter Employee Name: ",newEmp.name,sizeof(newEmp.name),20);
    
    readString("Enter Department: ",newEmp.department,sizeof(newEmp.department),15);
    newEmp.salary = readFloat("Enter Salary: ");
    emp[cnt] = newEmp;
    cnt++;
    printf("\nEmployee added successfully.\n");
}

// DISPLAY ALL EMPLOYEES
void displayAllemp() {
    int i;
    if (cnt == 0) {
        printf("\nNo employee records found.\n");
        return;
    }
    printf("\n==============================================================\n");
    printf("                    EMPLOYEE RECORDS\n");
    printf("==============================================================\n");
    printf("%-8s %-20s %-15s %-12s\n","ID","Name","Department","Salary");

    printf("--------------------------------------------------------------\n");

    for (i = 0; i < cnt; i++)
    {
        printf("%-8d %-20s %-15s %-12.2f\n",emp[i].id,emp[i].name,emp[i].department,emp[i].salary);
    }

    printf("\n==============================================================\n");
}

// SEARCH EMPLOYEE
void searchEmployee() {
    int choice;
    int id;
    int Index;
    char name[50];
    int found = 0;
    int i;

    if (cnt == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n========== SEARCH EMPLOYEE ==========\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");

    choice = readInt("Enter your choice: ");

    if (choice == 1) {
        id = readInt("Enter Employee ID: ");
        Index = findEmployeeById(id);

        if (Index == -1) {
            printf("\nEmployee not found.\n");
        }
        else {
            printf("\nEmployee found:\n");
            displayEmployee(Index);
        }
    }
    else if (choice == 2) {
        readString("Enter Employee Name: ",name,sizeof(name),49);

        for (i = 0; i < cnt; i++) {
            if (strcmp(emp[i].name, name) == 0) {
                printf("\nEmployee found:\n");
                displayEmployee(i);

                found = 1;
            }
        }

        if (found == 0) {
            printf("\nEmployee not found.\n");
        }
    }
    else {
        printf("\nInvalid choice.\n");
    }
}

// SORT emp(BUBBLE SORT)
void sortemp() {
    int choice;
    int i;
    int j;
    int swap;

    struct Employee temp;

    if (cnt == 0) {
        printf("\nNo employee records available to sort.\n");
        return;
    }

    printf("\n========== SORT emp ==========\n");
    printf("1. Sort by ID\n");
    printf("2. Sort by Name\n");
    printf("3. Sort by Salary\n");

    choice = readInt("Enter your choice: ");

    if (choice < 1 || choice > 3) {
        printf("\nInvalid choice.\n");
        return;
    }

    for (i = 0; i < cnt - 1; i++) {
        swap = 0;

        for (j = 0; j < cnt - i - 1; j++) {
            if (choice == 1) {
                if (emp[j].id > emp[j + 1].id) {
                    swap = 1;
                }
            }
            else if (choice == 2) {
                if (strcmp(emp[j].name,emp[j + 1].name) > 0) {
                    swap = 1;
                }
            }
            else if (choice == 3) {
                if (emp[j].salary > emp[j + 1].salary) {
                    swap = 1;
                }
            }
            if (swap) {
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;

                swap = 0;
            }
        }
    }

    printf("\nemp sorted successfully.\n");

    displayAllemp();
}

// UPDATE EMPLOYESS
void updateEmployee() {
    int id;
    int Index;

    printf("\n========== UPDATE EMPLOYEE ==========\n");

    id = readInt("Enter Employee ID to update: ");
    Index = findEmployeeById(id);
    if (Index == -1) {
        printf("\nEmployee not found.\n");
        return;
    }
    printf("\nCurrent employee details:\n");
    displayEmployee(Index);
    printf("\nEnter new details:\n");

    readString("Enter New Name: ",emp[Index].name,sizeof(emp[Index].name),20);
    readString("Enter New Department: ",emp[Index].department,sizeof(emp[Index].department),15);
    emp[Index].salary =readFloat("Enter New Salary: ");
    printf("\nEmployee updated successfully.\n");
}

// DELETE EMPLOYEE
void deleteEmployee() {
    int id;
    int Index;
    int i;
    printf("\n========== DELETE EMPLOYEE ==========\n");

    id = readInt("Enter Employee ID to delete: ");
    Index = findEmployeeById(id);
    if (Index == -1) {
        printf("\nEmployee not found.\n");
        return;
    }

    for (i = Index; i < cnt - 1; i++) {
        emp[i] = emp[i + 1];
    }
    cnt--;
    printf("\nEmployee deleted successfully.\n");
}

void removeTrailingSpaces(char str[]) {
    int length;
    length = strlen(str);
    while (length > 0 &&(str[length - 1] == ' ' ||str[length - 1] == '\n' ||str[length - 1] == '\r')) {
        str[length - 1] = '\0';
        length--;
    }
}

// SAVE RECORDS
void saveRecords() {
    FILE *file;
    int i;
    file = fopen("emp.txt", "w");
    if (file == NULL) {
        printf("\nError: Could not open emp.txt\n");
        return;
    }

    fprintf(file,"==============================================================\n");
    fprintf(file,"                    EMPLOYEE RECORDS\n");
    fprintf(file,"==============================================================\n\n");
    fprintf(file,"%-8s %-20s %-15s %-12s\n","ID","Name","Department","Salary");

    fprintf(file,"--------------------------------------------------------------\n");

    for (i = 0; i < cnt; i++) {
        fprintf(file,"%-8d %-20s %-15s %-12.2f\n",emp[i].id,emp[i].name,emp[i].department,emp[i].salary);
    }

    fprintf(file,"\n==============================================================\n");
    fclose(file);
    printf("\nRecords saved successfully to emp.txt\n");
}

// LOAD RECORDS 
void loadRecords() {
    FILE *file;
    char line[150];
    file = fopen("emp.txt", "r");

    if (file == NULL) {
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        struct Employee temp;
        char namePart[21];
        char departmentPart[16];
        char salaryPart[30];

        if (line[0] == '=' ||line[0] == '-' ||line[0] == '\n' ||line[0] == '\r') {
            continue;
        }

        if (strncmp(line, "ID", 2) == 0) {
            continue;
        }

        if (sscanf(line,"%d %20c %15c %29s",&temp.id,namePart,departmentPart,salaryPart) == 4) {
            namePart[20] = '\0';
            departmentPart[15] = '\0';

            removeTrailingSpaces(namePart);
            removeTrailingSpaces(departmentPart);

            strcpy(temp.name, namePart);
            strcpy(temp.department, departmentPart);

            temp.salary = atof(salaryPart);

            if (cnt < MAX) {
                emp[cnt] = temp;
                cnt++;
            }
        }
    }
    fclose(file);
}

// MAIN FUNCTION
int main() {
    int choice;
    loadRecords();
    printf("\n====================================================\n");
    printf("        EMPLOYEE RECORD MANAGEMENT SYSTEM\n");
    printf("====================================================\n");

    if (cnt > 0) {
        printf("%d employee record(s) loaded from emp.txt\n",cnt);
    }
    else {
        printf("No previous employee records found.\n");
    }

    while (1) {
        printf("\n==============================================\n");
        printf("       EMPLOYEE RECORD MANAGEMENT SYSTEM\n");
        printf("==============================================\n");
        printf("1. Add Employee\n");
        printf("2. Display All emp\n");
        printf("3. Search Employee\n");
        printf("4. Sort emp\n");
        printf("5. Update Employee\n");
        printf("6. Delete Employee\n");
        printf("7. Save Records\n");
        printf("8. Exit\n");
        printf("==============================================\n");

        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:addEmployee();break;
            case 2:displayAllemp();break;
            case 3:searchEmployee();break;
            case 4:sortemp();break;
            case 5:updateEmployee();break;
            case 6:deleteEmployee();break;
            case 7:saveRecords();break;
            case 8:saveRecords();
            printf("\nThank you for using the system.\n");
            printf("Program terminated successfully.\n");

            return 0;

            default:printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}