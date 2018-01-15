NAME = ft_retro

CC = clang++

CCFLAGS =   -Wall -Werror -Wextra -lncurses -o $(NAME)

SRC = main.cpp src/*.cpp

RM = -rm -fr

$(NAME):
		$(CC) $(CCFLAGS) $(SRC) -I ./incl

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)
