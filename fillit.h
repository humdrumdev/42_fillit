#ifndef FILLIT_H
#define FILLIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

#define MAX_SHAPES 26
#define SHAPE_LEN 20
#define SHAPES_LEN 19
#define USAGE "usage: ./fillit [input_file]\n"
#define USAGE_LEN 29
#define ERROR "error\n"
#define ERROR_LEN 6
#define SQUARE_SHAPE_ID 0x0033
#define MAX_SHAPE_AREA 6
#define MIN_SHAPE_AREA 4

typedef struct s_shape
{
    u_int16_t bin_id;
    u_int64_t bin_rep;
    char h;
    char w;
    char x;
    char y;
    char letter;
    struct s_shape *last_of_kind;
    struct s_shape *next;
} t_shape;

u_int16_t shape_to_bin(char *str);
int ft_shape_index(u_int16_t bin_id);
t_shape *is_valid_shape(char *str, char *c);
t_shape *copy_shape(const t_shape *shape, char *c);

int read_shape(int fd, char *buf, t_shape **first, char *c);
t_shape *read_file(int fd, int *count, char *c);
t_shape *reader(char *fname, int *count);
int get_last_of_kind_n_area(t_shape *head);

char *prepare_sol(t_shape *shape, int size);
void printnclean(char *str);
int solvenprint(t_shape *shape, int count, int exact_size);

void delete_list(t_shape **list);
int sq_root(int num);

#endif