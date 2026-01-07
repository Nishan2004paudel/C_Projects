#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100


void loadTasks(char tasks[][100], int *numTasks){
    FILE *file = fopen("tasks.txt","r");
    if (file == NULL){
        return;
    }
    while (fgets(tasks[*numTasks],100,file)){
        size_t len = strlen(tasks[*numTasks]);
        if(len>0 && tasks[*numTasks][len -1]=='\n'){
            tasks[*numTasks][len -1]='\0';
        }
        (*numTasks)++;
    }
    fclose(file);
}

void saveTasks(char tasks[][100], int numTasks){
    FILE *file = fopen("tasks.txt","w");
    for (int i = 0; i< numTasks; i++){
        fprintf(file, "%s\n", tasks[i]);
    }
    fclose(file);
}

int main(){

    char tasks[MAX_TASKS][MAX_LENGTH];
    int numTasks = 0;
    int choice; 

    loadTasks(tasks, &numTasks);

    do{
        printf("\n--- To-Do List Menu ---\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. View Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                if (numTasks >= MAX_TASKS){
                    printf("Task list is full ! Cannot add more tasks. \n");

                }else{
                    getchar();
                    printf("Enter the task: ");
                    fgets(tasks[numTasks], MAX_LENGTH, stdin);
                    size_t len = strlen(tasks[numTasks]);
                    if(len > 0 && tasks[numTasks][len-1]=='\n'){
                        tasks[numTasks][len-1]='\0';
                    }
                    numTasks++;
                    printf("Task added successfully!\n");
                    saveTasks(tasks, numTasks);
                }
                
                break;

            case 2:
                if (numTasks == 0){
                    printf("No tasks to delete.\n");
                }else{
                    int taskNumber;
                    printf("Enter task number to delete: ");
                    scanf("%d", &taskNumber);

                    if(taskNumber < 1 || taskNumber > numTasks){
                        printf("Invalid task number !\n");
                    }else{
                        for (int i = taskNumber - 1; i < numTasks-1; i++){
                            strcpy(tasks[i],tasks[i+1]);
                        }
                        numTasks--;
                        printf("Task Deleted Successfully\n");
                        saveTasks(tasks, numTasks);
                    }
                }
                
                break;

            case 3:
                if (numTasks == 0){
                    printf("No tasks available. \n");
                }else{
                    printf("\n Your Tasks: \n");
                    for (int i = 0; i< numTasks; i++){
                        printf("%d. %s\n", i+1 , tasks[i]);
                    }
                }
                break;
        }



    }while(choice !=4);
    printf("Exiting To-Do list app. Goodbye!\n");

    return 0;
}