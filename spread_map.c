#include "cub3d.h"

void        print_points(t_point *point)
{
    static int i = 1;
    if (!point)
        return ;
    //printf("|%d|\n",i);
    i++;
    while (point)
    {
        printf("point->x = %zu\npoint->y = %zu\npoint->val = %c\n\n",
            point->x, point->y, point->val);
        point = point->next;
    }
}

static void     get_neighbor(t_point *neighbor, size_t compass)
{
    if (compass == 1)
        neighbor->y += 1;
    else if (compass == 2)
        neighbor->x += 1;
    else if (compass == 3)
        neighbor->y -= 1;
    else if (compass == 4)
        neighbor->y -= 1;
    else if (compass == 5)
        neighbor->x -= 1;
    else if (compass == 6)
        neighbor->x -= 1;
    else if (compass == 7)
        neighbor->y += 1;
    else if (compass == 8)
        neighbor->y += 1;
}

static int      point_in_map(char **map, size_t x, size_t y)
{
    size_t i; 
    size_t j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (x == i && j == y)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
static int      fill_stack(char **map, t_point *cur_point, t_point **stack, t_point **visited)
{
    t_point     *point;

    cur_point->val = map[cur_point->x][cur_point->y];
    if (!(point = new_point(cur_point->x, cur_point->y, cur_point->val)))
        return (-1);
    if (check_charset(point->val, "012NSWE") == -1)
        return (-1);
    if (point->val != '1')
    {
        if (point->x == (*stack)->x && point->y == (*stack)->y)
        {
            if (!is_point_in_list(*visited, point))
                push_back_point(visited, point);
        }
        else
        {
            if (!is_point_in_list(*stack, point) && !is_point_in_list(*visited, point))
                push_back_point(stack, point);
        }
    }
    return (0);
}

static int      handle_stack(char **map, t_point **visited, t_point **stack)
{
    t_point     *cur_point;
    size_t      compass;

    cur_point = NULL;
    compass = 0;
    if (!(cur_point = new_point((*stack)->x, (*stack)->y, 0)))
        return (-1);
    if (!is_point_in_list(*visited, *stack))
    {
        while (compass <= 8)
        {
            if (compass != 0)
                get_neighbor(cur_point, compass);
            if (!(point_in_map(map, cur_point->x, cur_point->y)))
                return (-1);
            if (fill_stack(map, cur_point, stack, visited) == -1)
                return (-1);
            compass++;
        }
    }
    //free(cur_point);
    //cur_point = NULL;
    return (0);
}

int         spread_map(char **map, t_point *stack, t_point **visited)
{
    //t_point *spread_point;

    while (stack)
    {
        if (handle_stack(map, visited, &stack) == -1)
        {
            clear_points(&stack);
            clear_points(visited);
            return (-1);
        }
        pop_front_point(&stack);
    }
    //count_spread_point();
    //printf("|-----Visited-----|\n");
    //print_points(*visited);
    clear_points(&stack);
    return (0);
}
