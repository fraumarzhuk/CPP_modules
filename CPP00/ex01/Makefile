NAME = phonebook
CXX = c++ -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -g

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

RED 	:= \033[1;31m
GREEN 	:= \033[1;32m
BLUE 	:= \033[1;34m
PURPLE	:= \033[35;1m

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re