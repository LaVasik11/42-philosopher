NAME			= philo
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
LDFLAGS  	    = -lpthread

SRC				= main.c init.c simulation.c utils1.c utils2.c
OBJ				= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


