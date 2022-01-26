#include "./fillit.h"

int linked(char *str, int index)
{
    int cnd;

    if (str[index] == '#')
    {
        if (index == 0)
            return ((str[1] == '#') || (str[5] == '#'));
        if (index == 3)
            return ((str[2] == '#') || (str[8] == '#'));
        if (index == 15)
            return ((str[10] == '#') || (str[16] == '#'));
        if (index == 18)
            return ((str[17] == '#') || (str[13] == '#'));
        if ((index == 5) || (index == 10))
            return ((str[index - 5] == '#') || (str[index + 5] == '#') || (str[index + 1] == '#'));
        if ((index == 8) || (index == 13))
            return ((str[index - 1] == '#') || (str[index - 5] == '#') || (str[index + 5] == '#'));
        if (index < 3)
            return ((str[index - 1] == '#') || (str[index + 1] == '#') || (str[index + 5] == '#'));
        if (index > 15)
            return ((str[index - 1] == '#') || (str[index + 1] == '#') || (str[index - 5] == '#'));
        cnd = (str[index - 1] == '#') || (str[index + 1] == '#');
        return (cnd || (str[index - 5] == '#') || (str[index + 5] == '#'));
    }
    return (1);
}

int check_at_index(char *str, int i, u_int16_t *bin, int *hash_count)
{
    if (((i + 1) % 5) != 0)
    {
        if ((str[i] != '.' && str[i] != '#') || !linked(str, i))
            return (0);
        else
        {
            *bin = (u_int16_t)(2 * (*bin) + (str[i] == '#'));
            if (str[i] == '#')
                (*hash_count)++;
        }
    }
    return (1);
}

u_int16_t shape_to_bin(char *str)
{
    u_int16_t bin;
    int i;
    int last;
    int hash_count;

    if ((str[4] != '\n') || (str[9] != '\n') || (str[14] != '\n') || (str[19] != '\n'))
        return (0);
    bin = 0;
    i = -1;
    last = 19;
    hash_count = 0;
    while (str[++i] && (hash_count < 5))
    {
        if (!check_at_index(str, i, &bin, &hash_count))
            return (0);
        if (str[i] == '#')
            last = i;
    }
    if ((i != SHAPE_LEN) || hash_count != 4)
        return (0);
    return (bin / (u_int16_t)(1 << (15 + (last / 5) - last)));
}

t_shape *copy_shape(const t_shape *shape, char *c)
{
    t_shape *new;

    new = (t_shape *)malloc(sizeof(t_shape));
    if (new)
    {
        new->letter = *c;
        new->bin_rep = shape->bin_rep;
        new->bin_id = shape->bin_id;
        new->h = shape->h;
        new->w = shape->w;
    }
    return (new);
}
