#include <stdio.h>

int main() {
    int marks[100], n, i, j, key;
    int shifts = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter %d student marks:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    /* Insertion Sort */
    for (i = 1; i < n; i++) {
        key = marks[i];
        j = i - 1;

        while (j >= 0 && marks[j] > key) {
            marks[j + 1] = marks[j];
            shifts++;
            j--;
        }

        marks[j + 1] = key;

        printf("After pass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", marks[k]);
        }
        printf("\n");
    }

    printf("\nSorted marks in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }

    printf("\nTotal number of shifts: %d\n", shifts);

    return 0;
}
/*  SAMPLE OUTPUT:
Enter number of students: 5
Enter 5 student marks:
70 45 90 30 60

After pass 1: 45 70 90 30 60
After pass 2: 45 70 90 30 60
After pass 3: 30 45 70 90 60
After pass 4: 30 45 60 70 90

Sorted marks in ascending order:
30 45 60 70 90
Total number of shifts: 6
*/
