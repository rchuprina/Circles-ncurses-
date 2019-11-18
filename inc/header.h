#ifndef HEADER_H
#define HEADER_H

#define PI 3.14159265

#include <ncurses.h>
#include <math.h>
#include <stdlib.h>

typedef struct s_circ
{
    int x;
    int y;
    int r;
    int color;
    struct s_circ *next;
}t_circ;

void add_circ(t_circ **list, int y, int x);
void delete_circ(t_circ **list);
void scene();

#endif
