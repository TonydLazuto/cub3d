.PHONY		= all clean fclean re bonus

NAME		= cub3D

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -O3

RM			= /bin/rm -f

MLXLIB		= -lft -lm -Lmlx -lmlx -framework OpenGL -framework AppKit

LIB_DIR		= libft

MLX_DIR		= mlx

SRCS		=	cub3d.c \
				utils.c  \
				check_valid_cub.c \
				./gnl/get_next_line.c \
				./gnl/get_next_line_utils.c \
				parse_utils.c  \
				check_valid_cub.c \
				check_line.c  \
				check_rfcs.c \
				check_txt.c \
				#draws.c \
				parse.c

OBJS		= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
			@make -C libft
			@make -C mlx
			$(CC) $(CFLAGS) $(MLXLIB) -L libft $(MLX_DIR)/libmlx.a $(LIB_DIR)/libft.a -o $(NAME) $(OBJS)

$(%.o):		$(%.c)
			$(CC) -Ilibft -Imlx -c $< -o $@

clean:
			@make clean -C libft
			@make clean -C mlx
			$(RM) $(OBJS)

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
