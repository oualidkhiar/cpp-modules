
NAME = megaphone
CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =  megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
