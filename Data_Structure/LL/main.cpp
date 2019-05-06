#include <stdio.h>
#include <stdlib.h>

#include "func1.h"

/********Example console output*********

=== 1. (1) single Figure structure
* Creating card: (row, col) = (1, 2), number = 7, revealed = 0

* Calling print_fig_info() prints:
(1, 2) = 7 (0)

=== 1. (2) array of Figures
* Card (0, 0): (0, 0) = 1 (0)
* Card (0, 1): (0, 1) = 2 (0)
* Card (0, 2): (0, 2) = 4 (0)
* Card (0, 3): (0, 3) = 6 (0)
* Card (1, 0): (1, 0) = 1 (0)
* Card (1, 1): (1, 1) = 3 (0)
* Card (1, 2): (1, 2) = 6 (0)
* Card (1, 3): (1, 3) = 4 (0)
* Card (2, 0): (2, 0) = 5 (0)
* Card (2, 1): (2, 1) = 3 (0)
* Card (2, 2): (2, 2) = 2 (0)
* Card (2, 3): (2, 3) = 5 (0)

=== 1. (2) & (3) figures memory

* Inserting card (0, 0): (0, 0) = 1 (0)
* Inserting card (0, 1): (0, 1) = 2 (0)
* Inserting card (0, 2): (0, 2) = 4 (0)
* Inserting card (0, 3): (0, 3) = 6 (0)
* Inserting card (1, 0): (1, 0) = 1 (0)

# Cards in memory by card number:
1: (0, 0) = 1 (0)
2: (0, 1) = 2 (0)
3: (not found)
4: (0, 2) = 4 (0)
5: (not found)
6: (0, 3) = 6 (0)

* Inserting card (0, 0): (0, 0) = 1 (0)
* Inserting card (0, 1): (0, 1) = 2 (0)
* Inserting card (0, 2): (0, 2) = 4 (0)
* Inserting card (0, 3): (0, 3) = 6 (0)
* Inserting card (1, 0): (1, 0) = 1 (0)
* Inserting card (1, 1): (1, 1) = 3 (0)
* Inserting card (1, 2): (1, 2) = 6 (0)
* Inserting card (1, 3): (1, 3) = 4 (0)
* Inserting card (2, 0): (2, 0) = 5 (0)
* Inserting card (2, 1): (2, 1) = 3 (0)
* Inserting card (2, 2): (2, 2) = 2 (0)
* Inserting card (2, 3): (2, 3) = 5 (0)

# Cards in memory by card number:
1: (not found)
2: (2, 2) = 2 (0)
3: (2, 1) = 3 (0)
4: (1, 3) = 4 (0)
5: (2, 0) = 5 (0)
6: (not found)

* Removing card (2, 3): (2, 3) = 5 (0)
* Removing card (2, 2): (2, 2) = 2 (0)
* Removing card (2, 1): (2, 1) = 3 (0)
* Removing card (2, 0): (2, 0) = 5 (0)
* Removing card (1, 3): (1, 3) = 4 (0)

# Cards in memory by card number:
1: (not found)
2: (not found)
3: (not found)
4: (not found)
5: (not found)
6: (not found)


=== 1. (2) & (3) free table, memories

****************/

const int FLAG_INSERT = 1;
const int FLAG_REMOVE = 0;


void test_single_fig();
void test_figure_memory(struct Figure** table, int row, int col, int keep);

void show_cards_in_table(struct Figure **table, int row, int col);
void insert_remove_cards(struct Figure **table, int row, int col, int idx, int flag);
void show_cards_in_memory_by_num(int row, int col);


int main() {
	int row = 3, col = 4;
	int keep = 5;

	struct Figure **table;

	printf("=== 1. (1) single Figure structure\n");
	test_single_fig();

	printf("\n");


	printf("=== 1. (2) array of Figures\n");
	srand(5);	// fix random seed for test purpose

	table = create_figure_table(row, col);
	show_cards_in_table(table, row, col);
	printf("\n");


	printf("=== 1. (2) & (3) figures memory\n");
	// NOTE assume (row, col) = (3, 4), keep last 5 figures

	alloc_memory(keep);
	printf("\n");
	
	test_figure_memory(table, row, col, keep);
	printf("\n");

	/*
	printf("=== 1. (2) & (3) free table, memories\n");
	free_memory();
	free_figure_table(table, row);
	printf("\n");*/
}


void test_single_fig() {
	int row = 1, col = 2;
	int num = 7;
	int revealed = 0;

	printf("* Creating card: (row, col) = (%d, %d), number = %d, revealed = %d\n\n", row, col, num, revealed);
	struct Figure fig;

	// TODO change names of member variables to match your structure definition
	fig.row = row;
	fig.col = col;
	fig.num = num;
	fig.rev = revealed;

	printf("* Calling print_fig_info() prints:\n");
	print_fig_info(&fig);
}


void show_cards_in_table(struct Figure **table, int row, int col) {
	int r, c;
	struct Figure *card;

	for (r = 0; r < row; r++)
		for (c = 0; c < col; c++) {
			card = get_figure(table, r, c);

			printf("* Card (%d, %d): ", r, c);
			print_fig_info(card);
		}
}


void test_figure_memory(struct Figure** table, int row, int col, int keep) {
	int i;

	// insert first five cards
	for (i = 0; i < 5; i++)
		insert_remove_cards(table, row, col, i, FLAG_INSERT);
	printf("\n");

	// find cards for each figure; only up to 5 cards have to exist
	show_cards_in_memory_by_num(row, col);
	printf("\n");


	// insert every cards --> only last 5 cards exist in memory
	// (1, 3), (2, 0), (2, 1), (2, 2), (2, 3)
	for (i = 0; i < row * col; i++)
		insert_remove_cards(table, row, col, i, FLAG_INSERT);
	printf("\n");

	// find cards for each figure; only up to 5 cards have to exist
	show_cards_in_memory_by_num(row, col);
	printf("\n");


	// remove last 5 cards
	for (i = row * col - 1; i > row * col - 1 - keep; i--) {
		insert_remove_cards(table, row, col, i, FLAG_REMOVE);
	}
	printf("\n");

	// find cards once more; this time no card exists in memory
	show_cards_in_memory_by_num(row, col);
	printf("\n");
}


void insert_remove_cards(struct Figure **table, int row, int col, int idx, int flag) {
	int r, c;
	struct Figure *card;

	r = idx / col;
	c = idx % col;

	card = get_figure(table, r, c);

	if (flag == FLAG_INSERT)
		printf("* Inserting card (%d, %d): ", r, c);
	else if (flag == FLAG_REMOVE)
		printf("* Removing card (%d, %d): ", r, c);
	print_fig_info(card);

	if (flag == FLAG_INSERT)
		mem_insert_fig(card);
	if (flag == FLAG_REMOVE)
		mem_delete_fig(card);
}


void show_cards_in_memory_by_num(int row, int col) {
	int i;
	struct Figure *found;

	printf("# Cards in memory by card number:\n");
	for (i = 0; i < (row * col) / 2; i++) {
		found = find_pairable_fig(i);
		printf("%d: ", i + 1);
		if (found != NULL)
			print_fig_info(found);
		else
			printf("(not found)\n");
	}
}