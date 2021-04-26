.PHONY		= all clean fclean re bonus

NAME		= cub3D

CC			= clang

FLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address

RM			= /bin/rm -f

MLXFLAG		= -lft -Lmlx -lmlx -lm -lbsd -lXext -lX11

INC			= cub3d.h

LIB_DIR		= libft

MLX_DIR		= mlx

OBJ_DIR		= obj

SRCS		=	cub3d.c \
				get_next_line.c \
				get_next_line_utils.c \
				utils.c  \
				lst_point.c \
				lst_point2.c \
				check_valid_cub.c \
				parse.c \
				parse_params.c \
				parse_map.c \
				get_params.c \
				spread_map.c \
				raycasting_init.c \
				raycasting.c \
				raycasting_move.c \
				raycasting_utils.c \
				sprite_init.c \
				sprite.c \
				draw_text.c \
				handle_key.c \
				errors.c \
				save.c

OBJS		= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

_YELLOW		= \e[38;5;184m
_GREEN		= \e[38;5;46m
_CLEAR		= \033[2K\c

all: 		init $(NAME)

init:
			@ $(shell mkdir -p $(OBJ_DIR))
			@ make --silent -C $(LIB_DIR)
			@ echo "\t$(_YELLOW)-->Minilibx loading..."
			@ make --silent -C $(MLX_DIR)
			@ echo "\t$(_GREEN)-->SUCCESS minilibx!"

$(NAME): 		$(OBJS) $(INC)
				@ echo "$(_YELLOW)--> (NAME)..."
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L $(LIB_DIR) -L $(MLX_DIR) $(MLXFLAG)

$(OBJ_DIR)/%.o:	%.c
				@ echo "$(_YELLOW)-->Cub3d compiling..."
				$(CC) $(FLAGS) -c $< -o $@
				@ echo "$(_CLEAR)"

clean:
			@ make clean -C libft
			@ make clean -C mlx
			rm -rf $(OBJ_DIR)

fclean:		clean
			$(RM) $(MLX_DIR)/libmlx.a
			$(RM) $(LIB_DIR)/libft.a
			$(RM) $(NAME)

re:			fclean all

help:
	@echo "Usage :"
	@echo "\tmake all : Rule NAME"
	@echo "\tmake (NAME) : Construction of libftprintf.a."
	@echo "\tmake .c.o : Define the stdersion from .c to .o."
	@echo "\tmake clean: Delete all objects files."
	@echo "\tmake fclean: Rule clean + delete also the library file."
@echo "\tmake re: Rule fclean + all."
