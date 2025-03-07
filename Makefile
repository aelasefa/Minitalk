NAME := client

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC := client.c minitalk_utils.c

#SRCB := bonus/main_bonus.c bonus/check_input_bonus.c \
		#bonus/libft/ft_strjoin_bonus.c bonus/get_next_line/get_next_line.c \
		#bonus/get_next_line/get_next_line_utils.c bonus/pipex_utils_bonus.c \
		#bonus/libft/ft_strcmp.c bonus/free_array.c

OBJS := $(SRC:.c=.o)

#OBJSB := $(SRCB:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(SRC)  ft_printf/libftprintf.a -o $(NAME)

#bonus : $(NAME)
#	rm -rf $(NAME)
#	make -C ft_printf
#	$(CC) $(CFLAGS) $(SRCB) ft_printf/libftprintf.a -o $(NAME)

clean :
	make -C ft_printf clean
	rm -rf $(OBJS) $(OBJS)

fclean : clean
	make -C ft_printf fclean
	rm -rf $(NAME)

re : fclean all
