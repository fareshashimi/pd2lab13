#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student record
struct Student {
    int student_no;
    char name[50];
    char department[50];
};

// Function to list all student records in the file
void listStudents(FILE *file) {
    struct Student student;
    int record_count = 0;

    // Find the total number of records in the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    record_count = file_size / sizeof(struct Student);

    if (record_count == 0) {
        printf("No records found in the file.\n");
        return;
    }

    // Allocate memory for an array to store the records
    struct Student *student_list = (struct Student *)malloc(record_count * sizeof(struct Student));
    
    if (student_list == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    // Read all records from the file into the array
    fread(student_list, sizeof(struct Student), record_count, file);

    // Display all student records
    printf("List of Student Records:\n");
    for (int i = 0; i < record_count; i++) {
        printf("Student Number: %d\n", student_list[i].student_no);
        printf("Student Name: %s\n", student_list[i].name);
        printf("Student Department: %s\n", student_list[i].department);
        printf("-----------------------\n");
    }

    // Free the allocated memory
    free(student_list);
}

int main() {
    FILE *file;
    int choice;

    // Open the file in binary read mode
    file = fopen("student_info.dat", "rb");

    if (file == NULL) {
        printf("File does not exist or cannot be opened.\n");
        return 1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. List all Student Records\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listStudents(file);
                break;
            case 2:
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
