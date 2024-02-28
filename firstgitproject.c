
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* root = NULL;

void create_list(int value);
void delete_element(int value);
void list_all_elements();
void delete_list();

int main() {
    int ch;
    int val;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Add an element to the list\n");
        printf("2. Delete an element from the list\n");
        printf("3. List all elements\n");
        printf("4. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &val);
                create_list(val);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                delete_element(val);
                break;
            case 3:
                list_all_elements();
                break;
            case 4:
                delete_list();
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

void create_list(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = value;
    temp->link = NULL;

    if (root == NULL || root->data >= value) {
        temp->link = root;
        root = temp;
    } else {
        struct node* current = root;
        while (current->link != NULL && current->link->data < value) {
            current = current->link;
        }
        temp->link = current->link;
        current->link = temp;
    }
}

void delete_element(int value) {
    struct node* current = root;
    struct node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->link;
    }

    if (current == NULL) {
        printf("Element %d not found in the list\n", value);
        return;
    }

    if (prev == NULL) {
        root = current->link;
    } else {
        prev->link = current->link;
    }

    free(current);
    printf("Deleted element %d\n", value);
}

void list_all_elements() {
    if (root == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct node* current = root;
    printf("Elements in the list: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

void delete_list() {
    struct node* current = root;
    while (current != NULL) {
        struct node* temp = current;
        current = current->link;
        free(temp);
    }
    root = NULL;
    //this is the first project of the nagaraja and the learning staging to the  commit stage so he will learn the coding as soon as possible and will work in the top most company and will start the IT life as soon as possible//
}