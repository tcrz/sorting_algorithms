#include "sort.h"

/**
* insertion_sort - simple sorting algorithm that builds the final
* sorted array (or list) one item at a time
* @list: pointer to listint_t doubly-linked list
*/

void sortedInsert(listint_t **head_ref, listint_t *newNode)
{
    listint_t *current;
    if (*head_ref == NULL)
        *head_ref = newNode;

    else if ((*head_ref)->n >= newNode->n)
    {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }

    else
    {
        current = *head_ref;

        while (current->next != NULL &&
               current->next->n < newNode->n)
            current = current->next;

        newNode->next = current->next;
        if (current->next != NULL)
            newNode->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }
    print_list(*head_ref);
}

void insertion_sort_list(listint_t **head_ref)
{
    listint_t *sorted = NULL;

    listint_t *current = *head_ref;
    while (current != NULL)
    {

        listint_t *next = current->next;
        current->prev = current->next = NULL;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}
