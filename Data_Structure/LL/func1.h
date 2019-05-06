#pragma once

struct Figure {
	int row, col;
	int num;
	int rev;

};

typedef struct com {
	struct Figure* fig;
	struct com* node;
} com;

// 1. (1)
void print_fig_info(struct Figure *fig);

// 1. (2)
struct Figure** create_figure_table(int row, int col);
struct Figure* get_figure(struct Figure** table, int row, int col);
void free_figure_table(struct Figure** table, int row);

// 1. (3)
void alloc_memory(int k);
void mem_insert_fig(struct Figure *fig);
struct Figure* find_pairable_fig(int num);
void mem_delete_fig(struct Figure *fig);
void free_memory(void);

com* create(struct Figure *fig);