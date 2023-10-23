#include "deck.h"

/**
 * sort_deck - Sorts a 52 card deck
 * @deck: The deck to sort
 *
 * Return: Always 0 (ok)
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	sort_suit(deck);
	sort_val(deck);
}

/**
 * sort_suit - Sorts a 52 card deck by suit
 * @deck: The deck to sort
 */
void sort_suit(deck_node_t **deck)
{
	deck_node_t *forward, *tmp;

	for (forward = (*deck)->next; forward && forward->prev;
			forward = forward->next)
	{
		for (; forward && forward->prev && forward->card->kind <
				forward->prev->card->kind; forward =
				forward->prev)
		{
			tmp = forward->prev;
			swap(deck, tmp, forward);
			forward = forward->next;
		}
	}
}

/**
 * sort_val - Sorts a 52 card deck statically by value
 * @deck: Deck to sort
 */
void sort_val(deck_node_t **deck)
{
	deck_node_t *f, *tmp;

	for (f = (*deck)->next; f && f->prev; f = f->next)
	{
		for (; f && f->prev && vcmp(f->card, f->prev->card) &&
				f->card->kind == f->prev->card->kind;
				f = f->prev)
		{
			tmp = f->prev;
			swap(deck, tmp, f);
			f = f->next;
		}
	}
}

/**
 * swap - Swaps 2 consecutive cards of a doubly linked list
 * Used in the insertion algorithm
 * @deck: Head node for the deck
 * @card1: The first card to swap
 * @card2: The second card to swap
 */
void swap(deck_node_t **deck, deck_node_t *card1, deck_node_t *card2)
{
	deck_node_t *prev, *next;

	prev = card1->prev;
	next = card2->next;

	if (prev != NULL)
		prev->next = card2;
	else
		*deck = card2;

	card1->prev = card2;
	card1->next = next;
	card2->prev = prev;
	card2->next = card1;

	if (next)
		next->prev = card1;
}

/**
 * vcmp - Compares 2 card values
 * @card1: The first card to compare
 * @card2: The second card to compare
 *
 * Return: 1 if less than, 0 if greater or equal to
 */
int vcmp(const card_t *card1, const card_t *card2)
{
	char char1 = card1->value[0], char2 = card2->value[0];
	const char *ord[14] = {"Ac", "1", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Ja", "Qu", "Ki"};
	int idx1 = 0, idx2 = 0, i;

	if ((char1 >= '0' && char1 <= '9') && (char2 >= '1' && char2 <= '9'))
	{
		if (card1->value[1] == '0')
			char1 = '1' + 9;
		if (card2->value[1] == '0')
			char2 = '1' + 9;
		return (char1 < char2);
	}
	else
	{
		for (i = 0; i < 14; i++)
		{
			if (card1->value[0] == ord[i][0] && card1->value[1] == ord[i][1])
				idx1 = i;
			if (card2->value[0] == ord[i][0] && card2->value[1] == ord[i][1])
				idx2 = i;
		}
		return (idx1 < idx2);
	}
}

