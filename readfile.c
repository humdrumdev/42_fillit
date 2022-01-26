#include "./fillit.h"

int read_shape(int fd, char *buf, t_shape **first, char *c)
{
    int status;

    if ((status = read(fd, buf, SHAPE_LEN + 1)) >= SHAPE_LEN)
    {
        if (status == SHAPE_LEN)
        {
            buf[SHAPE_LEN] = '\0';
            if ((*first = is_valid_shape(buf, c)) == NULL)
                return (-1);
            return (((*first)->next = NULL) || 1);
        }
        if (buf[SHAPE_LEN] != '\n')
            return (-1);
        buf[SHAPE_LEN] = '\0';
        if ((*first = is_valid_shape(buf, c)) == NULL)
            return (-1);
        return (0);
    }
    if (status == 0)
        return (((*first) == NULL) || 1);
    return (-1);
}

static inline void *free_clean(int fd, char *buf, t_shape **head)
{
    free(buf);
    close(fd);
    if (*head)
        delete_list(head);
    return (NULL);
}

t_shape *read_file(int fd, int *count, char *c)
{
    t_shape **list;
    t_shape *head;
    char *buf;
    int status;

    if ((buf = malloc((SHAPE_LEN + 2) * sizeof(char))) == NULL)
        return (NULL);
    head = NULL;
    list = &head;
    while (((*count)++ <= MAX_SHAPES) && (status = read_shape(fd, buf, list, c)) < 1)
    {
        if (status == -1)
            return (free_clean(fd, buf, &head));
        list = &((*list)->next);
        (*c)++;
    }
    if (!(*list) && (*count <= MAX_SHAPES + 1))
        (*count)--;
    if (*count > MAX_SHAPES)
        return (free_clean(fd, buf, &head));
    free(buf);
    close(fd);
    return (head);
}

t_shape *reader(char *fname, int *count)
{
    int fd;
    char c;

    *count = 0;
    c = 'A';
    if ((fd = open(fname, O_RDONLY)) < 0)
        return (NULL);
    return (read_file(fd, count, &c));
}