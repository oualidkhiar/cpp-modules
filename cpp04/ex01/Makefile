NAME = Polymorphism

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =  src/main.cpp\
	previous/src/Animal.cpp\
	previous/src/Dog.cpp\
	previous/src/Cat.cpp\
	previous/src/WrongAnimal.cpp\
	previous/src/WrongCat.cpp\
	src/Brain.cpp

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