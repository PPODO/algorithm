#include <stdio.h>
#include <stdlib.h>
#include "func1.h"
int index = -1;
int size;

com *head;

void print_fig_info(struct Figure *fig) {
	printf("(%d, %d) = %d (%d)\n", fig->row, fig->col, fig->num, fig->rev);
}

struct Figure** create_figure_table(int row, int col) {
	struct Figure** cards = (struct Figure **)malloc(sizeof(struct Figure *)*row);
	int i, j;

	for (i = 0; i < row; i++) {
		cards[i] = (struct Figure *)malloc(sizeof(struct Figure)*col);
	} //동적할당


	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			cards[i][j].row = i;
			cards[i][j].col = j;
			cards[i][j].rev = 0;

		}
	}// num을 제외한 정보 입력
	int *ary = (int *)malloc(sizeof(int)*(row * col));
	for (i = 0; i < row * col; i++) {
		ary[i] = i;          //중복되지 않는 숫자배열 아직 못함
	}
	int k = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			cards[i][j].num = ary[k];
			k++;
		}
	}
	return cards;

}

struct Figure* get_figure(struct Figure** table, int row, int col) {
	return &(table[row][col]);
}

void free_figure_table(struct Figure** table, int row) {
	int i;
	for (i = 0; i < row; i++) {
		free(table[i]);
	}
	free(table);
}

void alloc_memory(int k) {
	size = k;
	head = (com *)malloc(sizeof(com));
	head->node = NULL;
}
com* create(struct Figure *fig) {
	com* new_node = (com *)malloc(sizeof(com));
	new_node->fig = fig;
	new_node->node = NULL;
	return new_node;
}

void mem_insert_fig(struct Figure *fig) {
	if (head->node == NULL || index >= size - 1) {
		head->node = create(fig);
		index++;
	}
	else if (index == size - 1) {
		free_memory();
		head = (com*)malloc(sizeof(com));
		head->node = create(fig);
		index = -1;
	}
	else {
		com* temp = head;
		while (temp->node != NULL) {
			temp = temp->node;
		}
		temp->node = create(fig);
		index++;
	}
}



struct Figure* find_pairable_fig(int num) {
	com* cursor = head->node;
	while (cursor != NULL) {
		if (cursor->fig->num == num) {
			return cursor->fig;
		}
		cursor = cursor->node;
	}
	return NULL;
}

void mem_delete_fig(struct Figure *fig) {
	if (index == -1) return;
	if (head->fig == fig) {
		com* temp = head;
		head = head->node;
		free(temp);
		index--;
	}
	else {
		com *temp = head;
		while (temp->node->fig != fig)
		{
			temp = temp->node;
		}
		com *temp2 = temp->node;
		temp->node = temp->node->node;
		free(temp2);
		index--;
	}
}

void free_memory(void) {
	com *temp = head;

	while (temp != NULL)
	{
		head = head->node;
		free(temp);
		temp = head;
	}
}