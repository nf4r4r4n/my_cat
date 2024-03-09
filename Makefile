NAME=my_cat
CFLAGS=-Wall -Wextra -Werror
SRC=my_cat.c

all: $(NAME)

$(NAME): $(SRC)
	cc $(CFLAGS) $? -o $(NAME)

fclean:
	rm -f $(NAME)

.PHONY: all fclean
