NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

HEADER = pipex.h

FILES = pipex.c utils.c utils2.c ft_split.c

OBJECTS = $(FILES:.c=.o)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re