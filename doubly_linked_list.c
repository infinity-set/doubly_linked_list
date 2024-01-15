#include <stdio.h>
#include <stdlib.h>

// Define a structure for doubly linked list nodes
typedef struct dub_node
{
    struct dub_node *prev; // Pointer to the previous node
    int num;               // Data of the node
    struct dub_node *next; // Pointer to the next node

} dub_node;

// Function prototypes for adding, deleting, reversing, and printing nodes
void new_list(dub_node *head, int num);
void add_at_end(dub_node *head, int num);
dub_node *add_at_beginning(dub_node *head, int num);
dub_node *insert_at_index(dub_node *head, int index, int num);
void delete_at_end(dub_node *head);
dub_node *delete_at_beginning(dub_node *head);
dub_node *delete_at_index(dub_node *head, int index);
dub_node *delete_list(dub_node *head);
dub_node *reverse_list(dub_node *head);
void print_list(dub_node *head);

// Main function
int main()
{
    // Create the initial node (head) and handle memory allocation error
    dub_node *head = (dub_node *)malloc((sizeof(dub_node)));
    if (head == NULL)
    {
        printf("\n***Not enough memory!***\n");
        exit(1);
    }

    // ADDING NODES
    printf("\nBegin new list.\n\n");
    new_list(head, 17);
    print_list(head);
    printf("\nAdd at the end --> ");
    add_at_end(head, 23);
    print_list(head);
    printf("\nAdd at the beginning --> ");
    head = add_at_beginning(head, 43); // Update head pointer to the beginning
    print_list(head);
    printf("\nInsert at index(s) --> ");
    head = insert_at_index(head, 1, 18);
    head = insert_at_index(head, 1, 54);
    head = insert_at_index(head, 1, 62);
    head = insert_at_index(head, 1, 70);
    print_list(head);

    // REVERSE LIST
    printf("\nReverse the list --> ");
    head = reverse_list(head);
    print_list(head);

    // DELETING NODES
    printf("\nDelete at the beginning --> ");
    head = delete_at_beginning(head);
    print_list(head);
    printf("\nDelete at the end --> ");
    delete_at_end(head);
    print_list(head);
    printf("\nDelete at index[0] --> ");
    head = delete_at_index(head, 0);
    print_list(head);
    printf("\nDelete at index[2] --> ");
    head = delete_at_index(head, 2);
    print_list(head);
    printf("\nDelete Entire List --> ");
    head = delete_list(head);
    print_list(head);

    return 0;
}

// ADDING NODES

// Initialize a new list with a given head and number
void new_list(dub_node *head, int num)
{
    head->prev = NULL;
    head->num = num;
    head->next = NULL;
}

// Add a new node with a given number at the end of the list
void add_at_end(dub_node *head, int num)
{
    dub_node *ptr = (dub_node *)malloc(sizeof(dub_node));
    if (ptr == NULL)
    {
        printf("Not enough memory!\n");
        exit(1);
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    ptr->num = num;
    ptr->next = NULL;
    head->next = ptr;
    ptr->prev = head;
}

// Add a new node with a given number at the beginning of the list
dub_node *add_at_beginning(dub_node *head, int num)
{
    dub_node *new_node = (dub_node *)malloc(sizeof(dub_node));
    if (new_node == NULL)
    {
        printf("Not enough memory!\n");
        exit(1);
    }
    new_node->prev = NULL;
    new_node->num = num;
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    return head;
}

// Insert a new node with a given number at a specified index in the list
dub_node *insert_at_index(dub_node *head, int index, int num)
{
    dub_node *new_node = (dub_node *)malloc(sizeof(dub_node));
    if (new_node == NULL)
    {
        printf("Not enough memory!\n");
        exit(1);
    }
    new_node->num = num;
    dub_node *previous = head;
    dub_node *next = head->next;

    if (index == 0)
    {
        head = add_at_beginning(head, num);
        return head;
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            previous = next;
            next = next->next;
            if (next == NULL)
            {
                add_at_end(head, num);
                return head;
            }
        }
        new_node->next = next;
        new_node->prev = previous;
        previous->next = new_node;
        next->prev = new_node;
    }
    return head;
}

// DELETING NODES

// Delete the first node in the list
dub_node *delete_at_beginning(dub_node *head)
{
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

// Delete the last node in the list
void delete_at_end(dub_node *head)
{
    dub_node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

// Delete the node at a specified index in the list
dub_node *delete_at_index(dub_node *head, int index)
{
    dub_node *ptr = head;
    dub_node *ptr2 = head->next;

    if (index == 0 && ptr2)
    {
        head = delete_at_beginning(head);
    }
    else if (index != 0 && ptr2)
    {
        for (int i = 1; i < index; i++)
        {
            ptr = ptr2;
            ptr2 = ptr->next;
        }
        ptr->next = ptr2->next;
        ptr2->next->prev = ptr;
        free(ptr2);
        ptr2 = NULL;
    }

    return head;
}

// Delete the entire list
dub_node *delete_list(dub_node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
    free(head);
    head = NULL;
    return head;
}

// REVERSE LIST

// Reverse the entire list
dub_node *reverse_list(dub_node *head)
{
    if (head == NULL)
    {
        printf("Cannot reverse an empty list.\n");
        return head;
    }
    dub_node *tmp = head;
    dub_node *tmp2 = head->next;

    tmp->next = NULL;
    tmp->prev = tmp2;

    while (tmp2 != NULL)
    {
        tmp2->prev = tmp2->next;
        tmp2->next = tmp;
        tmp = tmp2;
        tmp2 = tmp2->prev;
    }
    head = tmp;
    return head;
}

// PRINTING NODES

// Print the elements of the list
void print_list(dub_node *head)
{
    if (head == NULL)
    {
        printf("Your list is empty!\n");
        return;
    }
    printf("List: ");
    while (head != NULL)
    {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("\n");
}
