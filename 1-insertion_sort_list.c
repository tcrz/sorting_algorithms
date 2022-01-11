#include "sort.h"

/**
* sortedInsert - inserts node at right position
* @head_ref: ref to head
* @newNode: new node
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

/**
* insertion_sort_list - implements insertion sort
* @head_ref: pointer to listint_t head
*/
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
