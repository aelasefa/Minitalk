NAME := client

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC := client.c minitalk_utils.c

OBJS := $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	make -C ../ft_printf
	$(CC) $(CFLAGS) $(SRC)  ../ft_printf/libftprintf.a -o $(NAME)

clean :
	make -C ../ft_printf clean
	rm -rf $(OBJS) $(OBJS)

fclean : clean
	make -C ../ft_printf fclean
	rm -rf $(NAME)

re : fclean all
