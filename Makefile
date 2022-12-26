CC			= gcc -g
NAME		= snake
SRCS 		= $(shell find src -name "*.c")
OBJS		= $(SRCS:.c=.o)
OS 			= $(shell uname)

ifeq ($(OS),Mac)
	MLXDIR = mlx-mac
	CC += -framework OpenGL -framework AppKit
else
	MLXDIR = mlx-linux
endif

all: MINILIBX $(NAME)

$(NAME) : $(OBJS)
ifeq ($(OS), Linux)
	$(CC) $(OBJS) -o $(NAME) $(MLXDIR)/libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	$(CC) $(OBJS) -o $(NAME) $(MLXDIR)/libmlx.a
endif

MINILIBX:
	make -C $(MLXDIR) --silent
	@echo "MINILIBX compiled !"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	@make clean -C $(MLXDIR)

re: clean all

reall: fclean all
