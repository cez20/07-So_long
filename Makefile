NAME     = so_long

SRCS     = srcs/main.c srcs/map_validation.c srcs/map_parsing.c srcs/game_images.c \
           srcs/image_to_window.c srcs/game_events.c srcs/utils.c srcs/game_quit.c \
           gnl/get_next_line.c gnl/get_next_line_utils.c

HEADER   = -Iinclude/

LIBFT    = -Linclude/libft -lft

MLX      = -Linclude/minilibx -lmlx -framework OpenGL -framework AppKit

OBJS     = $(SRCS:.c=.o)

CC       = gcc 
CFLAGS   = -Wall -Wextra -Werror -g  
RM       = rm -f 

.c.o:
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ./include/libft
	make -C ./include/minilibx
	$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

clean:
	make clean -C ./include/libft
	make clean -C ./include/minilibx
	$(RM) $(OBJS)

fclean: clean
	make fclean -C ./include/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re