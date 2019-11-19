#include "header.h"

void quit(t_circ **list)
{
    while (*list)
        delete_circ(list);
    endwin();
    exit(0);
}

void clear_circ(t_circ *circ, int h, int w)
{
    int y = 0;
    int x = 0;

    for (int i = 0; i < 360; i++)
    {
        y = circ->y + circ->r * cos(i);
        x =  2 * (circ->x + circ->r * sin(i));
        if (x >= 0 && x < w && y >= 0 && y < h)
            mvprintw(y, x, " ");
    }
}

void print_circ(t_circ **list, int h, int w)
{
    if (*list)
    {
        for (t_circ *p = *list; p; p = p->next)
        {
            attron(COLOR_PAIR(p->color));
            clear_circ(p, h, w);
            p->r++;
            for (int i = 0; i < 360; i++)
            {
                int y = p->y + p->r * cos(i);
                int x =  2 * (p->x + p->r * sin(i));
                if (p->r > w / 2)
                {
                    delete_circ(list);
                    break;
                }
                else if (x >= 0 && x < w && y >= 0 && y < h)
                    mvprintw(y, x, ".");
            }
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
        print_circ(&list, h, w);
        timeout(50);
        refresh();
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
            add_circ(&list, rand() % h, (rand() % w) / 2);
            break;
        }
    }
}
