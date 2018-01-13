NAME = ft_retro

CC = clang++

CCFLAGS = -Wall -Werror -Wextra -lncurses -o $(NAME)

SRC = main.cpp src/GameObj.class.cpp src/Game.class.cpp src/Player.class.cpp src/Bullet.class.cpp

RM = -rm -fr

$(NAME):
		$(CC) $(CCFLAGS) $(SRC)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)
