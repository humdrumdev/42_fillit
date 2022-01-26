#include "./shapes.h"

int ft_shape_index(u_int16_t bin_id)
{
    int i;

    i = 0;
    while (i <= SHAPES_LEN)
    {
        if (g_shapes[i]->bin_id == bin_id)
            return (i);
        i++;
    }
    return (-1);
}

t_shape *is_valid_shape(char *str, char *c)
{
    u_int16_t bin_id;
    int shape_index;

    bin_id = shape_to_bin(str);
    if (bin_id == 0)
        return (NULL);
    shape_index = ft_shape_index(bin_id);
    if (shape_index == -1)
        return (NULL);
    return (copy_shape(g_shapes[shape_index], c));
}

void delete_list(t_shape **list)
{
    t_shape *head;
    t_shape *tmp;

    head = *list;
    while (head)
    {
        tmp = head->next;
        head->bin_id = 0;
        head->bin_rep = 0;
        head->letter = 0;
        head->h = 0;
        head->w = 0;
        head->last_of_kind = NULL;
        free(head);
        head = tmp;
    }
    *list = NULL;
}

static inline void set_last_of_kind(t_shape *head, t_shape *node)
{
    while (head && (head != node))
    {
        if (head->bin_id == node->bin_id)
        {
            node->last_of_kind = head;
            return;
        }
        head = head->next;
    }
}

int get_last_of_kind_n_area(t_shape *head)
{
    t_shape *node;
    int area;

    node = head->next;
    area = head->h * head->w;
    while (node)
    {
        set_last_of_kind(head, node);
        area += node->h * node->w;
        node = node->next;
    }
    return (area);
}