#include <stdio.h>

int main() {
    int n, i, key;
    int employeeID[100];
    int low, high, mid;
    int comparisons = 0;
    int found = 0;

    printf("Enter number of employee IDs: ");
    scanf("%d", &n);

    printf("Enter %d employee IDs in ascending order:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &employeeID[i]);
    }

    printf("Enter employee ID to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        comparisons++;

        if (employeeID[mid] == key) {
            found = 1;
            break;
        } else if (key < employeeID[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (found) {
        printf("\nEmployee ID %d found at position %d.\n", key, mid + 1);
    } else {
        printf("\nEmployee ID %d is not present.\n", key);
    }

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
/*
SAMPLE OUTPUT:
Enter number of employee IDs: 5
Enter 5 employee IDs in ascending order:
101
102                                                                                                     
103                                                                                                     
104                                                                                                     
105                                                                                                     
Enter employee ID to search: 104                                                                        
                                                                                                        
Employee ID 104 found at position 4.                                                                    
Number of comparisons: 2     */
