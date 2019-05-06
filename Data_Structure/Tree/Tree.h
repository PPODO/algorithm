#pragma once

typedef char TData;

typedef struct _node {
	TData Data;
	_node* left;
	_node* right;
}Node;

void Postordet(Node*);
void Delete(Node*);
void Preordert(Node*);
void Inordert(Node*);
void Postorert(Node*);
Node* Create(TData);