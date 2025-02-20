NAME = ./casts
CXX = c++ -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC = Aclass.cpp Bclass.cpp Cclass.cpp Base.cpp main.cpp 
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