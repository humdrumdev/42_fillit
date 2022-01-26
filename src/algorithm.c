#include "fillit.h"

static inline void ft_bzero(void *s, size_t n)
{
    while (n--)
    {
        *((char *)s) = '\0';
        s++;
    }
}

static inline int check_if_shape_fits(t_shape *shape, u_int16_t *grid)
{
    u_int64_t cur_ver_block;
    u_int64_t cur_hor_block;

    cur_ver_block = *(u_int64_t *)(grid + shape->y);
    cur_hor_block = (shape->bin_rep >> shape->x);

    return (!(cur_ver_block & cur_hor_block));
}

static inline void toggle_state_of_shape(t_shape *shape, u_int16_t *grid)
{
    *(u_int64_t *)(grid + shape->y) ^= (shape->bin_rep >> shape->x);
}

// void print_uin16(u_int16_t bin_rep, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (bin_rep & (1 << (15 - i)))
//             write(STDOUT_FILENO, "1", 1);
//         else
//             write(STDOUT_FILENO, "0", 1);
//     }
//     write(STDOUT_FILENO, "\n", 1);
// }

// void print_gr(u_int16_t *grid, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         print_uin16(grid[i], size);
//     }
//     write(STDOUT_FILENO, "\n----------------\n\n", 19);
// }

/*
** solve_grid will return 1 if all the pieces can fit inside the passed [size]
** otherwise it returns 0
** it performs this task by trying to find the right place for each shape.
** it fails once it tried to place the current shape in all its possible positions
** without finding a fiting one
*/

static int solve_grid(t_shape *shape, int size, u_int16_t *grid)
{
    int curr_position;

    curr_position = 0;
    if (shape->last_of_kind)
        curr_position = shape->last_of_kind->x + (shape->last_of_kind->y * size);
    shape->y = (curr_position / size) - 1;
    while (++(shape->y) <= (size - shape->h))
    {
        shape->x = -1;
        if (shape->y == (curr_position / size))
            shape->x = (curr_position % size) - 1;
        while (++(shape->x) <= (size - shape->w))
        {
            if (check_if_shape_fits(shape, grid))
            {
                toggle_state_of_shape(shape, grid);
                if ((shape->next == NULL) || solve_grid(shape->next, size, grid))
                    return (1);
                toggle_state_of_shape(shape, grid);
            }
        }
    }
    return ((shape->x = 0) && (shape->y = 0));
}

int solvenprint(t_shape *shape, int count, int initial_size)
{
    int size;
    int max_size;
    char *sol;
    u_int16_t *grid;

    if ((grid = (u_int16_t *)malloc(16 * sizeof(u_int16_t))) == NULL)
        return (1);
    size = initial_size;
    max_size = sq_root(count * MAX_SHAPE_AREA);
    ft_bzero(grid, sizeof(u_int16_t) * 16);
    while ((size <= max_size) && !solve_grid(shape, size, grid))
    {
        ft_bzero(grid, sizeof(u_int16_t) * 16);
        size++;
    }
    free(grid);
    if (size > max_size)
        return (1);
    if ((sol = prepare_sol(shape, size)) == NULL)
        return (1);
    sol = (printnclean(sol), NULL);
    return (0);
}
