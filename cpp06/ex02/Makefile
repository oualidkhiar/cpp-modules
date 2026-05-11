NAME = Identifier

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =  src/main.cpp \
	src/Functions.cpp \
	src/Base.cpp \
	src/A.cpp \
	src/B.cpp \
	src/C.cpp

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
