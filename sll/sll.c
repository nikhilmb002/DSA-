#include <stdio.h>
#include <stdlib.h>

struct Node {

        int data;
        struct Node *next;
};

void add_begin(struct Node **ptr) {

        struct Node *new = malloc(sizeof(struct Node));
        printf("Enter the data : ");
        scanf("%d", &new->data);
        new -> next = *ptr;
        *ptr = new;
}

void add_end(struct Node **ptr) {

        struct Node *new = malloc(sizeof(struct Node));
        printf("Enter the data : ");
        scanf("%d", &new -> data);
        new -> next = NULL;

        if (*ptr == NULL) {

                *ptr = new;
                return;
        }

        else {

                struct Node *temp = *ptr;

                while (temp -> next != NULL) {

                        temp = temp -> next;
                }

                temp -> next = new;
        }
}

int count(struct Node *ptr) {

        int count = 0;

        while(ptr) {

                ptr = ptr -> next;
                count++;
        }

        return count;
}


void add_at_pos(struct Node **ptr) {

        int pos;
        printf("Enter the pos : ");
        scanf("%d", &pos);

        int max = count(*ptr);

        if (pos <= 0 || pos > max + 1) {

                printf("Give valid pos \n");
                return;
        }

        else {

                struct Node *new = malloc(sizeof(struct Node));

                printf("Enter the data : ");
                scanf("%d", &new -> data);

                if (pos == 1) {

                        new -> next = *ptr;
                        *ptr = new;
                        return;
                }

                struct Node *temp = *ptr;

                for (int i = 1; i < pos - 1; i++)

                        temp = temp -> next;

                new -> next = temp -> next;
                temp -> next = new;
        }
}

void print_node(struct Node *ptr) {

        while(ptr) {

                printf("%d ", ptr -> data);
                ptr = ptr -> next;
        }

        printf("\n");
}

void add_after_value(struct Node **ptr) {

        int value;
        printf("Enter the value : ");
        scanf("%d", &value);


        struct Node *temp = *ptr;
        int pos = 1;

        while (temp && temp -> data != value) {

                temp = temp -> next;
                pos++;
        }

        if (temp == NULL) {

                printf("No node with value %d\n", value);
                return;
        }


        printf("Enter the data to add : ");
        struct Node *new = malloc(sizeof(struct Node));
        scanf("%d", &new -> data);

        new -> next = temp -> next;
        temp -> next = new;
}

void add_before_value(struct Node **ptr) {

        int value;
        printf("Enter the value : ");
        scanf("%d", &value);

        struct Node *temp = *ptr;
        struct Node *prev = NULL;

        while (temp && temp -> data != value) {

                prev = temp;
                temp = temp -> next;
        }

        if (temp == NULL) {

                printf("Node with value %d is not present\n", value);
                return;
        }

        struct Node *new = malloc(sizeof(struct Node));
        printf("Enter the data to add : ");
        scanf("%d", &new -> data);

        if (prev == NULL) {

                new -> next = *ptr;
                *ptr = new;
        }

        else {

                new -> next = temp;;
                prev -> next = new;
        }
}

void add_at_middle(struct Node **ptr) {

        struct Node *fast = *ptr;
        struct Node *slow = *ptr;

        if (*ptr == 0) {

                printf("No nodes\n");
                return;
        }

        while (fast != NULL && fast -> next != NULL) {

                fast = fast -> next -> next;

                if (fast != NULL)

                        slow = slow -> next;
        }

        struct Node *new = malloc(sizeof(struct Node));
        printf("Enter the data : ");
        scanf("%d", &new -> data);

        new -> next = slow -> next;
        slow -> next = new;
}

void delete_from_begin(struct Node **ptr) {

        if (*ptr == NULL) {

                printf("No nodes\n");
                return;
        }

        else {

                struct Node *temp = *ptr;
                *ptr = (*ptr) -> next;
                free(temp);
        }
}

void delete_from_end(struct Node **ptr) {

        struct Node *temp = *ptr;
        struct Node *prev = NULL;

        if (temp == NULL) {

                printf("No node\n");
                return;
        }

        if (temp -> next == NULL) {

                free(temp);
                *ptr = NULL;
                return;
        }

        while (temp -> next != NULL) {

                prev = temp;
                temp = temp -> next;
        }

        prev -> next = NULL;
        free(temp);
}

int main() {

        struct Node *head = NULL;
        int choice;

        printf("1. Add at begin\n2. Add at End\n3. Add at pos\n4. Print\n");
        printf("5. Add after a given value\n");
        printf("6. Add before a given value\n");
        printf("7. Add at Middle\n");
        printf("8. Delete From Begin\n");
        printf("9. Delete From End\n");

        while(1) {

                printf("Enter the choice : ");
                scanf("%d", &choice);

                switch(choice) {

                        case  1 : add_begin(&head); break;
                        case  2 : add_end(&head); break;
                        case  3 : add_at_pos(&head); break;
                        case  4 : print_node(head); break;
                        case  5 : add_after_value(&head); break;
                        case  6 : add_before_value(&head); break;
                        case  7 : add_at_middle(&head); break;
                        case  8 : delete_from_begin(&head); break;
                        case  9 : delete_from_end(&head); break;
                        default : exit(0);
                }
        }
}
