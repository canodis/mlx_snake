CC			= gcc -g
MINILIBX	= mlx/libmlx.a
NAME		= snake
SRCS 		= $(shell find src -name "*.c")
OBJS		= $(SRCS:.c=.o)
# LFLAGS		= -framework OpenGL -framework AppKit    # FOR MAC

all: $(NAME)

# $(NAME): $(MINILIBX) $(OBJS)
# 	$(CC) $(LFLAGS) $(OBJS) -o $(NAME) ./mlx/libmlx.a    # FOR MAC

$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) mlx/libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz     # FOR LINUX

$(MINILIBX):
	make -C mlx
	@echo "MINILIBX compiled !"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	@make clean -C mlx

re: clean all

reall: fclean all
