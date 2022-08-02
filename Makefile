CC			= gcc
MINILIBX	= minilibx/libmlx.a
FLAGS		= #-Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit
NAME		= snake
SRCS 		= srcs/*.c
Color_s = \033[92m
Color_e = \033[0m

all: $(NAME)

$(NAME): $(MINILIBX) banner
	$(CC) $(LFLAGS) $(FLAGS) $(SRCS) -o $(NAME) ./minilibx/libmlx.a

$(MINILIBX):
	make -C minilibx
	@echo "MINILIBX compile edildi !"

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)
	@make clean -C minilibx

banner:
	@echo "$(Color_s).------. .------. .------. .------. .------. .------. .------."
	@echo "|\x1B[31mC$(Color_s).--. | |\x1B[33mA$(Color_s).--. | |\x1B[34mN$(Color_s).--. | |\x1B[35mO$(Color_s).--. | |\x1B[36mD$(Color_s).--. | |\x1B[37mI$(Color_s).--. | |\x1b[31mS$(Color_s).--. |"
	@echo "| :/\: | | (\/) | | :(): | | :/\: | | :/\: | | (\/) | | :/\: |"
	@echo "| :\/: | | :\/: | | ()() | | :\/: | | (__) | | :\/: | | :\/: |"
	@echo "| '--'\x1B[31mC$(Color_s)| | '--'\x1B[33mA$(Color_s)| | '--'\x1B[34mN$(Color_s)| | '--'\x1B[35mO$(Color_s)| | '--'\x1B[36mD$(Color_s)| | '--'\x1B[37mI$(Color_s)| | '--'\x1b[31mS$(Color_s)|"
	@echo "\`------' \`------' \`------' \`------' \`------' \`------' \`------'\$(Color_e)"

re: fclean all
