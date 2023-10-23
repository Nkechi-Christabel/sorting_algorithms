#include "deck.h"

/**
 * card_value - Get the numerical value of a card's string representation
 * @value: The string representation of the card's value
 *
 * Return: The numerical value of the card
 */
int card_value(const char *value)
{
	if (strcmp(value, "Ace") == 0)
		return (1);

	if (strcmp(value, "Jack") == 0)
		return (11);

	if (strcmp(value, "Queen") == 0)
		return (12);

	if (strcmp(value, "King") == 0)
		return (13);

	return (atoi(value));
}

/**
 * swap_nodes - Swap two adjacent nodes in the deck
 * @node1: The first node to swap
 * @node2: The second node to swap
 */
void swap_nodes(deck_node_t *node1, deck_node_t *node2)
{
	if (node1 == NULL || node2 == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
}

/**
 * sort_deck - Sort the deck of cards by value and then by kind
 * @deck: A double pointer to the deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	int swapped;
	deck_node_t *ptr1, *lptr = NULL;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	do {
		swapped = 0;
		ptr1 = *deck;

		while (ptr1->next != lptr)
		{
			if (card_value(ptr1->card->value) > card_value(ptr1->
				next->card->value) || (card_value(ptr1->card->value)
					== card_value(ptr1->next->card->value) &&
					ptr1->card->kind > ptr1->next->card->kind))
			{
				swap_nodes(ptr1, ptr1->next);

				if (*deck == ptr1)
					*deck = ptr1->prev;

				swapped = 1;
			}
			else
				ptr1 = ptr1->next;
		}

		lptr = ptr1;
	} while (swapped);
}
