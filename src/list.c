#include "header.h"

static t_circ *create_circ(int y, int x)
{
    t_circ *c = (t_circ *)malloc(sizeof(t_circ));

    c->y = y;
    c->x = x;
    c->r = -1;
    c->color = rand() % 7 + 1;
    c->next = NULL;
    return c;
}

void add_circ(t_circ **list, int y, int x)
{
    t_circ *c = create_circ(y, x);

    c->next = *list;
    *list = c;
}

void delete_circ(t_circ **list)
{
     if (*list)
    {
        if ((*list)->next)
        {
            t_circ *p = *list;

            while (p->next->next)
                p = p->next;
            free(p->next);
            p->next = NULL;
        }
        else
        {
            free(*list);
            *list = NULL;
        }
    }
}
