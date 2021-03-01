#include "cub3d.h"

void        print_points(t_point *point)
{
    static int i = 1;
    if (!point)
        return ;
    printf("|%d|\n",i);
    i++;
    while (point)
    {
        printf("point->x = %zu\npoint->y = %zu\npoint->val = %c\n\n",
            point->x, point->y, point->val);
        point = point->next;
    }
}

static int      check_neighbors(char **map, t_point *neighbor, t_point **stack, t_point **visited)
{
    neighbor->val = map[neighbor->x][neighbor->y];
    printf("point->x = %zu\npoint->y = %zu\npoint->val = %c\n\n",
            neighbor->x, neighbor->y, neighbor->val);
    if (check_charset(neighbor->val, "012") == -1)
        return (-1);
    if (is_point_in_list(visited, neighbor) == 1)
        return (0);
    if (neighbor->val != '1')
        *stack = addfront_point(*stack, neighbor);
    //print_points(*stack);
    return (0);
}

static int      add_neighbors(char **map, t_point **visited, t_point **stack)
{
    t_point *neighbors;

    neighbors = NULL;
    if (is_point_in_list(visited, *stack) != 1)
    {
        if (!(neighbors = new_point((*stack)->x + 1, (*stack)->y, 0)))
            return (-1);
        if (check_neighbors(map, neighbors, stack, visited) == -1)
            return (-1);
        if (!(neighbors = new_point((*stack)->x - 1, (*stack)->y, 0)))
            return (-1);
        if (check_neighbors(map, neighbors, stack, visited) == -1)
            return (-1);
        if (!(neighbors = new_point((*stack)->x, (*stack)->y + 1, 0)))
            return (-1);
        if (check_neighbors(map, neighbors, stack, visited) == -1)
            return (-1);
        if (!(neighbors = new_point((*stack)->x, (*stack)->y - 1, 0)))
            return (-1);
        if (check_neighbors(map, neighbors, stack, visited) == -1)
            return (-1);
        popback_point(stack);
    }
    return (0);
}

int         spread_map(char **map, t_point *player)
{
    t_point  *visited;
    t_point  *stack;


    visited = NULL;
    stack = player;
    /*
    while (stack)
    {
    */
        if (add_neighbors(map, &visited, &stack) == -1)
        {
            clear_points(&stack);
            clear_points(&visited);
            ft_putendl_fd("Error\nThe player isn't in a close map.", 1);
            return (-1);
        }

        //addfront_point(&visited, stack);
        //popback_point(stack);
        //lastpoint(stack);
    //}
    //clear_points(&stack);
    //clear_points(&visited);
    return (0);
}