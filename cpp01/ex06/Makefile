NAME = harlFilter
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 --pedantic
RM = rm -rf

GREEN = \033[0;32m
RESET = \033[0m

SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
	@echo "$(GREEN)[Program is ready for use]$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
