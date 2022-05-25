##
## EPITECH PROJECT, 2021
## B-CCP-400-MPL-4-1-theplazza-paul.comte
## File description:
## Makefile
##

CC		= g++

INCLUDE	= -I includes/

CFLAGS	= -std=c++20 -Wall -Wextra -Werror -pthread -lncurses

SRC		= $(wildcard src/*.cpp)

SRC		+= $(wildcard src/*/*.cpp)

OBJ 	= $(SRC:.cpp=.o)

OUT		= plazza

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $@ $(SRC) $(INCLUDE) $(CFLAGS)

clean:
	$(RM) -rf $(OBJ)

fclean:	clean
	$(RM) $(OUT)

re: fclean all

%.o : %.cpp
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS)
