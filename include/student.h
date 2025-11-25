#ifndef STUDENT_H
#define STUDENT_H

struct studInfo {  
    int idNumber;
    char studentName[50];
    float scores[5];
    float avgPercent;
    char grade;
};

struct studInfo records[MAX_RECORDS];

void insertNEWstudent(); 
void showALLstudents();
void remove_student();
void findStudent();
void modifyStudent();

#endif
