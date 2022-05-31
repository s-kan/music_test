#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "linkedlist.h"

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

bool empty() {
	if(_head->next == _tail)	return true;
	else return false;
}

size_t size() {
	Node* ptr;
	ptr = _head->next;
	size_t count=0;
	while(ptr != NULL) {
			ptr = ptr->next;
			count++;
		}
    free(ptr);
	return count;
}

void print() {
	Node* ptr;
	ptr = _head->next;

	while(ptr != NULL) {
		printf("%s ", *(ptr->data));
		ptr = ptr->next;
	}
	free(ptr);
}

void print_file(FILE* stream) {
    Node* ptr;
	ptr = _head->next;

    while(ptr != NULL) {
		frintf(stream, *(ptr->data));
		ptr = ptr->next;
	}
	free(ptr);
}

void clear() {
    Node* ptr;
    ptr = _head->next;
    while(!empty()) {
        _head = ptr->next;
        ptr->next->prev = _head;
        free(ptr);
        ptr = _head->next;
    }
}

Node* append_left(size_t n, char new_data[n]) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(empty()) {
        new_node->data = new_data[n];
        _head->next = new_node;
        new_node->prev = _head;
        new_node->next = _tail;
        _tail->prev = new_node;

        return new_node;
    }
    Node* ptr = _head->next;
    new_node->prev = _haed;
    new_node->next = ptr;
    _haed->next = new_node;
    ptr->prev = new_node;
    new_node->data = new_data;

    return new_node;
}

Node* insert_after(Node* cur_node, Node* new_node) {
    Node* left = _cur_node;
    Node* right = _cur_node->next;

    left->next = new_node;
    new_node->next = right;
    new_node->prev = left;
    right->prev = new_node;

    _cur_node = new_node;
    return _cur_node;
}

Node* append(size_t n, char new_data[n]) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(empty()) {
        _head->next = new_node;
        new_node->prev = _head->next;
        new_node->next = _tail;
        new_node->data = new_data[n];
        _tail->prev = new_node;
        _cur_node = new_node;

        return new_node;
    }

    Node* ptr = _tail->prev;
    new_node->prev = ptr;
    new_node->next = _tail;
    ptr->next = new_node;
    _tail->prev = new_node;
    new_node->data = new_data;
    _cur_node = new_node;

    return new_node;
}

Node* delete_node(Node* _cur_node) {
    Node* cur = (Node*)malloc(sizeof(Node));
    cur = _cur_node;
    Node* left = cur-> prev;
    Node* right = cur->next;

	left->next = right;
	right->prev = left;
	_cur_node = left;

	free(cur);
	return _cur_node;
}

Node* delete_title(char* data) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr = head->next;
    while(ptr!=NULL){
        if(ptr->data == data) {
            Node* cur = (Node*)malloc(sizeof(Node));
            cur = delete_node(ptr);
            return cur
        }
        ptr=ptr->next;
    }
    return _head->next;
}

Node* get_node(size_t index) {
	if(size()<index)    return 0;

	Node* ptr;
	ptr = _head;
	int i;

	for(i=0; i<index; i++)
		ptr = ptr->next;

	return ptr;
}

Node* first() {
    if(empty()) return NULL;
	return _head->next;
}

Node* last() {
    if(empty()) return NULL;
	return _tail->prev;
}

Node* next() {
    if(_cur_node == _tail)  return NULL;
	return _cur_node->next;
}

Node* prev() {
    if(_cur_node == _head) return NULL;
	return _cur_node->prev;
}
