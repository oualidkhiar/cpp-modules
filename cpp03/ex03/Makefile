NAME = DiamondTrap

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	./prev_ex/ClapTrap.cpp \
	./prev_ex/ScavTrap.cpp \
	./prev_ex/FragTrap.cpp \
	DiamondTrap.cpp

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