#include "./fillit.h"

static inline void print_one(t_shape *shape)
{
    int i;
    int j;

    if (shape->bin_id == SQUARE_SHAPE_ID)
        write(STDOUT_FILENO, "AA\nAA\n", 6);
    else
    {
        j = 0;
        while (!(shape->bin_id & (1 << (15 - j))))
            j++;
        i = 15;
        while (i >= 0)
        {
            if ((i >= j) && (shape->bin_id & (1 << (i - j))))
                write(STDOUT_FILENO, "A", 1);
            else
                write(STDOUT_FILENO, ".", 1);
            if ((i % 4) == 0)
                write(STDOUT_FILENO, "\n", 1);
            i--;
        }
    }
}

static inline void exit_failure(const char *message, unsigned int message_len)
{
    write(STDOUT_FILENO, message, message_len);
    exit(EXIT_FAILURE);
}

static inline void terminate(t_shape **list, int status)
{
    delete_list(list);
    if (status)
        exit_failure(ERROR, ERROR_LEN);
    exit(status);
}

static inline int get_size(int c, int a)
{
    int s;
    int m;

    m = MAX_SHAPE_AREA * c;
    s = sq_root(MIN_SHAPE_AREA * c);
    if ((c > 4) && ((a - m) >= 0))
        return (s + 1);
    return (s);
}

int main(int ac, char **av)
{
    t_shape *list;
    int count;
    int status;
    int min_size;

    if (ac != 2)
        exit_failure(USAGE, USAGE_LEN);
    if ((list = reader(av[1], &count)) == NULL)
        exit_failure(ERROR, ERROR_LEN);
    status = 0;
    if (list->next == NULL)
        print_one(list);
    else
    {
        min_size = get_size(count, get_last_of_kind_n_area(list));
        status = solvenprint(list, count, min_size);
    }
    terminate(&list, status);
}
