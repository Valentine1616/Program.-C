#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct book b;
    FILE *fp;

    // Input book details
    printf("Enter book title: ");
    fgets(b.title, sizeof(b.title), stdin);

    printf("Enter book author: ");
    fgets(b.author, sizeof(b.author), stdin);

    printf("Enter book price: ");
    scanf("%f", &b.price);

    // Write to file
    fp = fopen("book.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fprintf(fp, "%s%s%.2f\n", b.title, b.author, b.price);
    fclose(fp);

    // Read from file and display
    fp = fopen("book.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("\nSaved Book Details:\n");

    fgets(b.title, sizeof(b.title), fp);
    fgets(b.author, sizeof(b.author), fp);
    fscanf(fp, "%f", &b.price);

    printf("Title : %s", b.title);
    printf("Author: %s", b.author);
    printf("Price : %.2f\n", b.price);

    fclose(fp);
    return 0;
}
