#include <stdio.h>
int main() {
    int choice_of_user;
    do {
        printf("\n--- Student Report Card ---\n");
        printf("1. Add New Student\n");
        printf("2. Show All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student Info\n");
        printf("5. Delete Student\n");
        printf("6. Exit Program\n");
        printf("Select option: ");
        scanf("%d", &choice_of_user);

        switch(choice_of_user) {
            case 1: insertNEWstudent(); break;
            case 2: showALLstudents(); break;
            case 3: findStudent(); break;
            case 4: modifyStudent(); break;
            case 5: remove_student(); break;
            case 6: printf("Program ending...\n"); break;
            default: printf("Wrong input, try again.\n");
        }
    } while(choice_of_user != 6);
    
    return 0;
}

