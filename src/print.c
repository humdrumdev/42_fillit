#include "./fillit.h"

static char *ft_strnew(size_t size)
{
    char *str;

    str = (char *)malloc((size + 1) * sizeof(char));
    if (!str)
        return (NULL);
    size++;
    while (size--)
        str[size] = 0;
    return (str);
}

static char *init_grid(int size)
{
    char *str;
    int x;
    int y;

    if ((str = ft_strnew(size * (size + 1))) == NULL)
        return (NULL);
    y = 0;
    while (y < size)
    {
        x = 0;
        while (x < size)
        {
            str[y * (size + 1) + x] = '.';
            x++;
        }
        str[y * (size + 1) + x] = '\n';
        y++;
    }
    return (str);
}

char *prepare_sol(t_shape *shape, int size)
{
    char *str;
    int x;
    int y;

    if ((str = init_grid(size)) == NULL)
        return (NULL);
    while (shape)
    {
        y = 0;
        while (y < shape->h)
        {
            x = 0;
            while (x < shape->w)
            {
                if (1L & (shape->bin_rep >> (16 * (y + 1) - 1 - x)))
                    str[(shape->y + y) * (size + 1) + (x + shape->x)] = shape->letter;
                x++;
            }
            y++;
        }
        shape = shape->next;
    }
    return (str);
}

void printnclean(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        write(STDOUT_FILENO, &str[i], 1);
        str[i] = 0;
    }
    free(str);
}