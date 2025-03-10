NAME_S := server
NAME_C := client
BONUS_C := client_bonus
BONUS_S := server_bonus

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC_S := server.c minitalk_utils.c
SRC_C := client.c minitalk_utils.c
SRC_B_C := client_bonus.c minitalk_utils_bonus.c
SRC_B_S := server_bonus.c minitalk_utils_bonus.c

OBJS_S := $(SRC_S:.c=.o)
OBJS_C := $(SRC_C:.c=.o)
OBJS_B_S := $(SRC_B_S:.c=.o)
OBJS_B_C := $(SRC_B_C:.c=.o)


all : $(NAME_S)  $(NAME_C)
bonus : $(BONUS_C) $(BONUS_S)

$(NAME_S) : $(OBJS_S)
	make -C ft_printf
	$(CC) $(CFLAGS) $(SRC_S)  ft_printf/libftprintf.a -o $(NAME_S)

$(NAME_C) : $(OBJS_C)
	make -C ft_printf
	$(CC) $(CFLAGS) $(SRC_C)  ft_printf/libftprintf.a -o $(NAME_C)


$(BONUS_C) : $(OBJS_B_C)
	make -C ft_printf
	$(CC) $(CFLAGS) $(SRC_B_C)  ft_printf/libftprintf.a -o $(BONUS_C)

$(BONUS_S) : $(OBJS_B_S)
	make -C ft_printf
	$(CC) $(CFLAGS) $(SRC_B_S)  ft_printf/libftprintf.a -o $(BONUS_S)

clean :
	make -C ft_printf clean
	rm -rf $(OBJS_S) $(OBJS_C) $(OBJS_B_S) $(OBJS_B_C)

fclean : clean
	make -C ft_printf fclean
	rm -rf $(NAME_S) $(NAME_C)  $(BONUS_S) $(BONUS_C)

re : fclean all
