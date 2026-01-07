#include <stdio.h>

int main(){
    int choice;
    double num1, num2, result;
    char again;

    do{
        printf("Simple Calculator\n");
        printf("Select Operation: \n");
        printf("1. Addition (+)\n");
        printf("2. Subtractiion (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("Enter your choice (1-4):");
        scanf("%d",&choice);

        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        if (choice == 1){
            result = num1 + num2;
            printf("Result: %.2lf \n", result);
        }else if (choice == 2){
            result = num1  - num2;
            printf("Result: %.2lf \n", result);
        }else if (choice == 3){
            result = num1 * num2;
            printf("Result: %.2lf \n", result);
        }else if (choice == 4){
            if (num2 != 0){
                result = num1/num2;
                printf("Result: %.2lf\n",result);
            }else {
                printf("Error: Division by zero is not allowed!\n");
            }
        }else {
            printf("Invalid choice !\n");
        }
        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &again);
    }while (again == 'y'|| again == 'Y');
    printf("Thank You for using the calculator!\n");

    return 0;
}