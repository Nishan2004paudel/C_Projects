#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account{
    int accountNumber;
    char name[50];
    double balance;
};

int loadaccounts(struct Account accounts[], int *numAccounts){
    FILE *fp = fopen("accounts.dat","rb");
    if(fp==NULL) return 0;
    fread(numAccounts, sizeof(int),1,fp);
    fread(accounts, sizeof(struct Account), *numAccounts,fp);
    fclose(fp);
    return 1;
}

void saveAccounts(struct Account accounts[], int numAccounts){
    FILE *fp = fopen("accounts.dat", "wb");
    fwrite(&numAccounts, sizeof(int),1,fp);
    fwrite(accounts, sizeof(struct Account), numAccounts,fp);
    fclose(fp);
}

int findAccount(struct Account accounts[], int numAccounts, int accNum){
    for (int i = 0; i< numAccounts; i++){
        if (accounts[i].accountNumber == accNum) return i;
    }
    return -1;
}

int main(){

    struct Account accounts[MAX_ACCOUNTS];
    int choice;
    int numAccounts = 0;

    // Load existing accounts from file
    loadaccounts(accounts, &numAccounts);

    do {
        printf("\n ----Bank Management System------\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: {
                if (numAccounts >= MAX_ACCOUNTS){
                    printf("Maximum accounts reached!\n");
                    break;
                }
                struct Account newAcc;
                printf("Enter account number: ");
                scanf("%d", &newAcc.accountNumber);
                getchar();
                printf("Enter customer name: ");
                fgets(newAcc.name, sizeof(newAcc.name), stdin);
                size_t len = strlen(newAcc.name);
                if(len> 0 && newAcc.name[len-1]=='\n') newAcc.name[len-1]='\0';
                newAcc.balance = 0;
                accounts[numAccounts++]=newAcc;
                saveAccounts(accounts, numAccounts);
                printf("Account created successfully!\n");
                break;
            }    
            case 2:{
                int accNum, idx;
                double deposit;
                printf("Enter account number: ");
                scanf("%d", &accNum);
                idx = findAccount(accounts, numAccounts, accNum);
                if (idx == -1){
                    printf("Account not found!\n");
                    break;
                }
                printf("Enter amount to deposit: ");
                scanf("%lf", &deposit);
                accounts[idx].balance += deposit;
                saveAccounts(accounts, numAccounts);
                printf("Deposited Successfully! Current balance: %.2lf\n", accounts[idx].balance);
                 
                break;
            }
            case 3:{
                int accNum, idx;
                double withdraw;
                printf("Enter account number: ");
                scanf("%d", &accNum);
                idx = findAccount(accounts, numAccounts, accNum);
                if (idx== -1){
                    printf("Account not found\n");
                    break;
                }
                printf("Enter amount to withdraw: ");
                scanf("%lf", &withdraw);
                if (withdraw > accounts[idx].balance){
                    printf("Insufficient balance!\n");
                }else{
                    accounts[idx].balance -= withdraw;
                    saveAccounts(accounts, numAccounts);
                    printf("Withdrawal Successfully! Current balance: %.2lf\n", accounts[idx].balance);
                }
                break;
            }

            case 4:{
                int accNum, idx;
                printf("Enter account number: ");
                scanf("%d", &accNum);
                idx = findAccount(accounts, numAccounts, accNum);
                if (idx == -1){
                    printf("Account not found! \n");
                    break;
                }
                printf("Account Number: %d\n", accounts[idx].accountNumber);
                printf("Customer Name: %s\n", accounts[idx].name);
                printf("Balance: %.2lf\n",accounts[idx].balance );
                break;
            }

            case 5: 
                printf("Exiting......................\n");
                break;
            default:
                printf("Invalid choice! Try again. \n");
        }
    }while(choice !=5);

    
    return 0;
}