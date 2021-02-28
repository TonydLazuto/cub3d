#include "cub3d.h"

void        print_points(t_point **point)
{
    if (!*point)
        return ;
    while (*point)
    {
        printf("point->x = %zu\npoint->y = %zu\npoint->val = %c\n",
            (*point)->x, (*point)->y, (*point)->val);
        (*point) = (*point)->next;
    }
    printf("\n");
}

static int      check_neighbors(char **map, t_point *neighbor, t_point *stack, t_point **visited)
{
    neighbor->val = map[neighbor->x][neighbor->y];
    if (check_charset(neighbor->val, "012") == -1)
        return (-1);
    if (is_same_point_in(visited, neighbor) == 1)
        return (0);
    if (neighbor->val != '1')
        addfront_point(&stack, neighbor);
    return (0);
}

static int      add_neighbors(char **map, t_point **visited, t_point *stack)
{
    t_point *neighbor;

    neighbor = NULL;
    if (*visited && (is_same_point_in(visited, stack) != 1))
    {
        if (!(neighbor = new_point(stack->x + 1, stack->y, 0)))
            return (-1);
        if (check_neighbors(map, neighbor, stack, visited) == -1)
            return (-1);
        neighbor->x -= 2;
        if (check_neighbors(map, neighbor, stack, visited) == -1)
            return (-1);
        neighbor->x++;
        neighbor->y += 1;
        if (check_neighbors(map, neighbor, stack, visited) == -1)
            return (-1);
        neighbor->y -= 2;
        if (check_neighbors(map, neighbor, stack, visited) == -1)
            return (-1);
        delback_point(neighbor);
    }
    return (0);
}

int         spread_map(char **map, t_point *stack)
{
    t_point  *visited;

    visited = NULL;
    while (stack)
    {
        if (add_neighbors(map, &visited, stack) == -1)
        {
            clear_points(&stack);
            clear_points(&visited);
            return (-1);
        }
        addfront_point(&visited, stack);
        delback_point(stack);
        lastpoint(stack);
    }
    clear_points(&stack);
    clear_points(&visited);
    return (0);
}