NAME = libftprintf.a
SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c \

BSRC = 
OBJ = $(SRC:%.c=%.o)
BOBJ = $(BSRC:%.c=%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ) $(BOBJ)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:

	$(RM) $(OBJ) $(BOBJ)

fclean: clean

	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re