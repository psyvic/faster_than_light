##
## Makefile for Makefile in /home/vic/Desktop/piscine/C/libmy_01
## 
## Made by AIZPURUA Victor Hugo
## Login   <aizpur_v@etna-alternance.net>
## 
## Started on  Sat Apr  1 07:46:15 2017 AIZPURUA Victor Hugo
## Last update Sat Apr 15 11:30:21 2017 AIZPURUA Victor Hugo
##

CC =            gcc
NAME =          my_ftl
SRC =           air_shed.c \
                my_ftl.c \
		container.c \
		system_control.c \
		system_repair.c \
		game.c  \
		game_2.c \
		game_3.c  \
		game_4.c  \
		game_5.c  \
		game_6.c  \
		game_7.c  \
		game_8.c  \

OBJ =           $(SRC:%.c=%.o)
CFLAGS =        -W -Wall -ansi -ansi -pedantic -Llibmy_01 -I.
LDFLAGS =
RM =            rm -f


$(NAME):        $(OBJ)
		make -C libmy_01
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lmy
debug:          $(OBJ)
		$(CC) -g $(OBJ) -o $(NAME) $(CFLAGS)
all:            $(NAME)
clean:
		$(RM) $(OBJ)
fclean:         clean
		$(RM) $(NAME)
re:             fclean all

.PHONY:         all clean fclear re
