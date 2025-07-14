
NAME = BraiiiiiiinnnzzzZ

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =  ./src/main.cpp \
	./src/newZombie.cpp \
	./src/randomChump.cpp \
	./src/Zombie.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
