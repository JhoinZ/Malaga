NAME = 
SRC = 
OBJ = $(SRC:%.c=%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:

	$(RM) $(OBJ)

fclean: clean

	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re