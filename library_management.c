#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book{
    int id;
    char title[50];
    char author[50];
    int quantity;
};

void addBook();
void viewBooks();
void searchBook();
void issueBook();
void returnBook();

int main(){
    int choice;
    do{
        printf("\n____ LIBRARY MANAGEMENT SYSTEM __________\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}

void addBook() {
    FILE *fp;
    struct Book b;

    fp = fopen("books.dat", "ab");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", b.title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Book added successfully!\n");
}

void viewBooks() {
    FILE *fp;
    struct Book b;

    fp = fopen("books.dat", "rb");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("\nID: %d", b.id);
        printf("\nTitle: %s", b.title);
        printf("\nAuthor: %s", b.author);
        printf("\nQuantity: %d\n", b.quantity);
    }

    fclose(fp);
}
void searchBook() {
    FILE *fp;
    struct Book b;
    int id, found = 0;

    fp = fopen("books.dat", "rb");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found!");
            printf("\nTitle: %s", b.title);
            printf("\nAuthor: %s", b.author);
            printf("\nQuantity: %d\n", b.quantity);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found!\n");

    fclose(fp);
}
void issueBook() {
    FILE *fp;
    struct Book b;
    int id, found = 0;

    fp = fopen("books.dat", "rb+");
    if (fp == NULL) {
        printf("File error.\n");
        return;
    }

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            found = 1;
            if (b.quantity > 0) {
                b.quantity--;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Book issued successfully!\n");
            } else {
                printf("Book out of stock!\n");
            }
            break;
        }
    }

    if (!found)
        printf("Book not found!\n");

    fclose(fp);
}
void returnBook() {
    FILE *fp;
    struct Book b;
    int id, found = 0;

    fp = fopen("books.dat", "rb+");
    if (fp == NULL) {
        printf("File error.\n");
        return;
    }

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            b.quantity++;
            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);
            printf("Book returned successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found!\n");

    fclose(fp);
}
