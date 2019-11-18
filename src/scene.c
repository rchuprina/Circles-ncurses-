#include "header.h"

void quit(t_circ **list)
{
    while (*list)
        delete_circ(list);
    endwin();
    exit(0);
}

void print_circ(t_circ **list, int h, int w)
{
    int y = 0;
    int x = 0;

    for (t_circ *p = *list; p; p = p->next)
    {
        attron(COLOR_PAIR(p->color));
        p->r += 1;
        for (int i = 0; i < 360; i++)
        {
            y = p->y + p->r * cos(i);
            x =  2 * (p->x + p->r * sin(i));
            if (p->r > w / 2)
            {
                delete_circ(list);
                break;
            }
            else if (x >= 0 && x < w && y >= 0 && y < h)
                mvprintw(y,x, ".");
        }
    }
}

void scene()
{
    int h = 0;
    int w = 0;
    t_circ *list = NULL;

    getmaxyx(stdscr, h, w);
    while (true)
    {
        clear();
        if (list)
            print_circ(&list, h, w);
        timeout(60);
        MEVENT event;
        switch (getch())
        {
        case 'q':
            quit(&list);
            break;
        case KEY_MOUSE:
            if (getmouse(&event) == OK)
                if (event.bstate)
                    add_circ(&list, event.y, event.x / 2);
            break;
        case 'r':
            add_circ(&list, rand() % h, rand() % w);
            break;
        }
    }
}
