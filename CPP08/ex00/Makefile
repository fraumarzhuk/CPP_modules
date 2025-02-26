NAME = ./array
CXX = c++ -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

SRC = main.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re