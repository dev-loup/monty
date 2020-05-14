#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include "structs.h"

void monty_core(char *line, stack_t **h, stack_t **t, int *mode, unsigned int ln);
int tok_validator(char *line, cmd_t *table);
void m_executer(cmd_t *table);
void push(cmd_t *table);
void pall(cmd_t *table);
void pint(cmd_t *table);
void pop(cmd_t *table);
void swap(cmd_t *table);
void add(cmd_t *table);
void nop(cmd_t *table);
void sub(cmd_t *table);
void divide(cmd_t *table);
void mul(cmd_t *table);
void mod(cmd_t *table);
void pchar(cmd_t *table);
void pstr(cmd_t *table);
void rotl(cmd_t *table);
void rotr(cmd_t *table);
void free_list(stack_t **head);
#endif /*MONTY_H*/
