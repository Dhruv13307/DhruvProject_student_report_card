#include <stdio.h>
#define MAX_RECORDS 200

void insertNEWstudent() {
    if(student_count >= MAX_RECORDS) {
        printf("Sorry, full student list.\n");
        return;
    }

    struct studInfo newStudent;
    float sumOfScores = 0.0;

    printf("Enter ID number: ");
    scanf("%d", &newStudent.idNumber);

    printf("Enter student name (no spaces): ");
    scanf("%s", newStudent.studentName);

    printf("Enter 5 subject scores:\n");
    for(int i = 0; i < 5; i++) {
        printf("Score for subject %d: ", i + 1);
        scanf("%f", &newStudent.scores[i]);
        sumOfScores += newStudent.scores[i];
    }

    newStudent.avgPercent = sumOfScores / 5.0;

    if(newStudent.avgPercent >= 90) newStudent.grade = 'A';
    else if(newStudent.avgPercent >= 80) newStudent.grade = 'B';
    else if(newStudent.avgPercent >= 70) newStudent.grade = 'C';
    else if(newStudent.avgPercent >= 60) newStudent.grade = 'D';
    else newStudent.grade = 'F';

    records[student_count++] = newStudent;
    printf("Student added!\n");
}

void showALLstudents() {
    if(student_count == 0) {
        printf("No students in list.\n");
        return;
    }

    printf("\nID\tName\t\tPercent\tGrade\n");
    printf("---------------------------------------\n");

    for(int i = 0; i < student_count; i++) {
        struct studInfo s = records[i];
        printf("%d\t%-10s\t%.2f\t%c\n", s.idNumber, s.studentName, s.avgPercent, s.grade);
    }
}


void findStudent() {
    if(student_count == 0) {
        printf("No data to search.\n");
        return;
    }

    int searchId;
    int foundFlag = 0;
    printf("Enter ID to find: ");
    scanf("%d", &searchId);

    for(int i = 0; i < student_count; i++) {
        if(records[i].idNumber == searchId) {
            printf("\nRecord found:\n");
            printf("ID: %d\n", records[i].idNumber);
            printf("Name: %s\n", records[i].studentName);
            printf("Scores: ");
            for(int j = 0; j < 5; j++) {
                printf("%.2f ", records[i].scores[j]);
            }
            printf("\nPercent: %.2f\n", records[i].avgPercent);
            printf("Grade: %c\n", records[i].grade);
            foundFlag = 1;
            break;
        }
    }

    if(!foundFlag) {
        printf("No student with this ID.\n");
    }
}


void modifyStudent() {
    if(student_count == 0) {
        printf("No data to update.\n");
        return;
    }

    int updateId;
    int foundFlag = 0;
    printf("Enter ID to update: ");
    scanf("%d", &updateId);

    for(int i = 0; i < student_count; i++) {
        if(records[i].idNumber == updateId) {
            foundFlag = 1;

            printf("Current name: %s\n", records[i].studentName);
            printf("Change name? (1=yes, 0=no): ");
            int doChange;
            scanf("%d", &doChange);
            if(doChange == 1) {
                printf("New name (no space): ");
                scanf("%s", records[i].studentName);
            }

            float totalScore = 0.0;
            printf("Enter new scores for 5 subjects:\n");
            for(int j = 0; j < 5; j++) {
                printf("Subject %d: ", j + 1);
                scanf("%f", &records[i].scores[j]);
                totalScore += records[i].scores[j];
            }

            records[i].avgPercent = totalScore / 5.0;

            if(records[i].avgPercent >= 90) records[i].grade = 'A';
            else if(records[i].avgPercent >= 80) records[i].grade = 'B';
            else if(records[i].avgPercent >= 70) records[i].grade = 'C';
            else if(records[i].avgPercent >= 60) records[i].grade = 'D';
            else records[i].grade = 'F';

            printf("Student updated.\n");
            break;
        }
    }

    if(!foundFlag) {
        printf("No student found with this ID.\n");
    }
}


void remove_student() {
    if(student_count == 0) {
        printf("No data to delete.\n");
        return;
    }

    int delId;
    int foundFlag = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &delId);

    for(int i = 0; i < student_count; i++) {
        if(records[i].idNumber == delId) {
            foundFlag = 1;
            for(int k = i; k < student_count - 1; k++) {
                records[k] = records[k + 1];  // shift left
            }
            student_count--;
            printf("Student record removed.\n");
            break;
        }
    }

    if(!foundFlag) {
        printf("No student found with this ID.\n");
    }
}
