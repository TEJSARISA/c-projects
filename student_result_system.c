#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int m1, m2, m3;
    int total;
    float avg;
    int rank;
};

int main() {
    struct Student s[100], temp;
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input Phase
    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Marks in 3 subjects: ");
        scanf("%d %d %d", &s[i].m1, &s[i].m2, &s[i].m3);

        // Calculate total and average
        s[i].total = s[i].m1 + s[i].m2 + s[i].m3;
        s[i].avg = s[i].total / 3.0;
    }

    // Sorting (Descending Order - Bubble Sort)
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(s[j].total < s[j + 1].total) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Assign Ranking
    for(i = 0; i < n; i++) {
        s[i].rank = i + 1;
    }

    // Output Phase
    printf("\n========================================\n");
    printf("    STUDENT RESULT PROCESSING SYSTEM    \n");
    printf("========================================\n");
    printf("Roll\tName\tTotal\tAverage\tRank\n");
    printf("----------------------------------------\n");
    
    for(i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%.2f\t%d\n",
               s[i].roll, s[i].name, s[i].total, s[i].avg, s[i].rank);
    }
    
    printf("========================================\n");

    return 0;
}
