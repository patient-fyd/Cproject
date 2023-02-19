#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int num_students = 0;

void add_student() {
    if (num_students >= MAX_STUDENTS) {
        printf("Max number of students reached.\n");
        return;
    }

    Student new_student;
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student GPA: ");
    scanf("%f", &new_student.gpa);

    students[num_students] = new_student;
    num_students++;
}

void delete_student() {
    int student_id;
    printf("Enter ID of student to delete: ");
    scanf("%d", &student_id);

    for (int i = 0; i < num_students; i++) {
        if (students[i].id == student_id) {
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            printf("Student with ID %d deleted.\n", student_id);
            return;
        }
    }

    printf("Student with ID %d not found.\n", student_id);
}

void print_students() {
    printf("ID\tName\tGPA\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

void search_student() {
    int student_id;
    printf("Enter ID of student to search: ");
    scanf("%d", &student_id);

    for (int i = 0; i < num_students; i++) {
        if (students[i].id == student_id) {
            printf("ID\tName\tGPA\n");
            printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }

    printf("Student with ID %d not found.\n", student_id);
}

void save_students() {
    FILE* fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s,%d,%.2f\n", students[i].name, students[i].id, students[i].gpa);
    }

    fclose(fp);
    printf("Students saved.\n");
}

void load_students() {
    FILE* fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No saved students.\n");
        return;
    }

    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        char* name = strtok(line, ",");
        int id = atoi(strtok(NULL, ","));
        float gpa = atof(strtok(NULL, ","));
        Student student = { 0 };
        strcpy(student.name, name);
        student.id = id;
        student.gpa = gpa;
        students[num_students] = student;
        num_students++;
    }

    fclose(fp);
    printf("Students loaded.\n");
}

int main() {
    char input;
    while (1) {
        printf("Enter a command: (a)dd, (d)elete, (p)rint, (s)earch, (sa)ve, (lo)ad, (q)uit: ");
        scanf(" %c", &input);
        switch (input) {
        case 'a':
            add_student();
            break;
        case 'd':
            delete_student();
            break;
        case 'p':
            print_students();
            break;
        case 's':
            search_student();
            break;
        case 'sa':
            save_students();
            break;
        case 'lo':
            load_students();
            break;
        case 'q':
            return 0;
        default:
            printf("Invalid command.\n");
        }
    }
}