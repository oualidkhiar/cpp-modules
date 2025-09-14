NAME = Polymorphism

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =  src/main.cpp\
	previous2/previous1/src/Animal.cpp\
	previous2/previous1/src/Dog.cpp\
	previous2/previous1/src/Cat.cpp\
	previous2/previous1/src/WrongAnimal.cpp\
	previous2/previous1/src/WrongCat.cpp\
	previous2/src/Brain.cpp

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