NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

GREEN = \033[0;32m
RESET = \033[0m

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)
	@echo "$(GREEN)[Program is ready for use]$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re