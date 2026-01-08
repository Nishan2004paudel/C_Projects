#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
 
struct Student{
    int roll;
    char name[50];
    float marks;
};

void addStudent(struct Student students[], int *count){
    if (*count >= MAX_STUDENTS){
        printf("Student list is full!\n");
        return;
    }
    printf("Enter roll number: ");
    scanf("%d", &students[*count].roll);

    getchar();
    printf("Enter name: ");
    fgets(students[*count].name, 50, stdin);

    printf("Enter marks: ");
    scanf("%f",&students[*count].marks);

    (*count)++;
    printf("Student Added Successfully !\n");

}
void viewStudents(struct Student students[], int count){
    if (count == 0){
        printf("No students found.\n");
        return;
    }
    for (int i = 0; i< count ; i++){
        printf("\n Roll: %d", students[i].roll);
        printf("\n Name: %s", students[i].name);
        printf("Marks: %.2lf\n", students[i].marks);
    }
}

void saveToFile(struct Student students[], int count){
    FILE *file = fopen("students.dat","wb");

    if (file == NULL){
        printf("Error saving file!\n");
        return;
    }

    fwrite(&count, sizeof(int),1,file);
    fwrite(students, sizeof(struct Student), count, file);
}
void loadFromFile(struct Student students[], int *count){
    FILE *file = fopen("students.dat","rb");

    if (file == NULL){
        return;
    }
    fread(count, sizeof(int), 1, file);
    fread(students, sizeof(struct Student), *count,file);

    fclose(file);
}


void searchStudent(struct Student students[], int count){
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    struct Student *ptr = students;
    for (int i = 0; i< count ; i++){
        if (ptr -> roll == roll){
            printf("\n Student Found!");
            printf("\n Roll: %d", ptr->roll);
            printf("\n Name: %s", ptr->name);
            printf("Marks: %2.lf\n", ptr->marks);
            return;
        }
        ptr++;
    }
    printf("Student not found.\n");
}

int main(){
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    loadFromFile(students, &count);

    do{
        printf("Student Record Management System\n");
        printf("1. Add Students\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1: 
                addStudent(students, &count);
                saveToFile(students, count);
                break;
            case 2: 
                viewStudents(students, count);
                 break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting.................\n");
                break;
            default:
                printf("Invalid choice!\n");
                 
        }


    }while (choice !=4);
    return 0;
}