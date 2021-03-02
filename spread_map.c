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

t_point         *get_neighbor(size_t compass, t_point *neighbor)
{
    if (compass == 0)
        neighbor->x += 1;
    else if (compass == 1)
        neighbor->y -= 1;
    else if (compass == 2)
        neighbor->x -= 1;
    else if (compass == 3)
        neighbor->x -= 1;
    else if (compass == 4)
        neighbor->y += 1;
    else if (compass == 5)
        neighbor->y += 1;
    else if (compass == 6)
        neighbor->x += 1;
    else if (compass == 7)
        neighbor->x += 1;
    return (neighbor);
}

static int      check_point(char **map, t_point *neighbor, t_point **stack, t_point **visited)
{
    t_point     *tmp;
    t_point     *top_of_stack;

    neighbor->val = map[neighbor->x][neighbor->y];
    if (!(tmp = new_point(neighbor->x, neighbor->y, neighbor->val)))
        return (-1);
    if (check_charset(tmp->val, "012NSWE") == -1)
        return (-1);
    if (!is_point_in_list(*stack, tmp))
    {
        if (!(top_of_stack = new_point(tmp->x,tmp->y,tmp->val)))
            return (-1);
        push_back_point(stack, top_of_stack);
        return (0);
    }
    if (tmp->val != '1')
        push_back_point(stack, tmp);
    return (0);
}

static int      fill_stack(char **map, t_point **visited, t_point **stack)
{
    t_point     *cur_point;
    size_t      compass;

    cur_point = NULL;
    compass = 0;
    if (!is_point_in_list(*visited, *stack))
    {
        if (!(cur_point = new_point((*stack)->x, (*stack)->y, 0)))
            return (-1);
        while (compass <= 7)
        {
//    printf("| STACK IN NEIGHBOR |\n");
//    print_points(*stack);
            cur_point = get_neighbor(compass, cur_point);
            if (check_point(map, cur_point, stack, visited) == -1)
                return (-1);
            compass++;
        }
        free(cur_point);
        cur_point = NULL;
    }
    return (0);
}

int         spread_map(char **map, t_point *player)
{
    t_point     *visited;
    t_point     *stack;
    t_point     *top_of_stack;


    visited = NULL;
    top_of_stack = NULL;
    stack = player;
    
/*
    while (stack)
    {
        */
        if (fill_stack(map, &visited, &stack) == -1)
        {
            clear_points(&stack);
            clear_points(&visited);
            ft_putendl_fd("Error\nThe player isn't in a close map.", 1);
            return (-1);
        }
        //printf("|---Stack Before---|\n");
        //print_points(stack);
        if (!(top_of_stack = new_point(stack->x,stack->y,stack->val)))
            return (-1);
        //printf("|---Top Stack---|\n");
        //print_points(top_of_stack);
        if (!is_point_in_list(visited, top_of_stack))
            push_back_point(&visited, top_of_stack);
        pop_front_point(&stack);
        //printf("|---Stack After---|\n");
        //print_points(stack);
    //}
    print_points(visited);
    clear_points(&stack);
    clear_points(&visited);
    return (0);
}