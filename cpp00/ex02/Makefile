
NAME = Account
CC = c++

CFLAGS = -Wall -Werror -Wextra -g

SRC= tests.cpp Account.cpp

OBJS= $(SRC:.cpp=.o)

%o : %cpp
	$(cc) $(CFLAGS) -c $< -o $@

all: $(NAME)
	$(NAME): $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all