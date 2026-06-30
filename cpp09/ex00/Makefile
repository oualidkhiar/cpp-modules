NAME = btc

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS= src/main.cpp \
	src/BitcoinExchange.cpp

OBJ= $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all