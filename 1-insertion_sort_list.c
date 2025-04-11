#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list in ascending order
* using the Insertion Sort algorithm.
*
* @list: Double pointer to the head of the doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;

if (!list || !(*list) || !((*list)->next))
return;

current = (*list)->next;
while (current)
{
temp = current;
current = current->next;

while (temp->prev && temp->n < temp->prev->n)
{
/* Swap nodes */
temp->prev->next = temp->next;
if (temp->next)
temp->next->prev = temp->prev;

temp->next = temp->prev;
temp->prev = temp->next->prev;

if (temp->prev)
temp->prev->next = temp;
else
*list = temp;

temp->next->prev = temp;

/* Print the list after each swap */
print_list(*list);
}
}
}
