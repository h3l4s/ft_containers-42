DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
TESTCOL = \033[1;35m

# NAME =====================================================================================
NAME	=	our_map

# SOURCES ==================================================================================
SRCS = main_map.cpp
SRCS_DIR = ./

# COMPILATION ==============================================================================
FLAGS = -Wall -Wextra -Werror -std=c++98

# OBJECTS ==================================================================================
OBJS_DIR = o_objects/
OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

# EXEC =====================================================================================
$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@echo -n "                                               \r"
	@echo -n "♻  Compiling: $<  ♻"
	@sleep 0.3
	@echo -n "                                               \r"
	@c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@c++ $(FLAGS) -o $(NAME) $(OBJS)
	@echo -n "                                               \r"
	@echo "♻   Compilation Done   ♻"

all: $(NAME)

clean:
	@echo -n "                                               \r"
	@echo -n "♻  Cleaning: $(OBJS_DIR)  ♻"
	@sleep 0.3
	@echo -n "                                               \r"
	@rm -rf $(OBJS_DIR)
	@rm -rf output3
	@echo -n "♻  Cleaned objects  ♻"

fclean: clean
		@echo -n "                                               \r"
		@echo -n "♻  Cleaning: $(NAME)  ♻"
		@sleep 0.3
		@echo -n "                                               \r"
		@rm -f $(NAME)
		@echo -n "♻  Cleaned everything  ♻"

re: fclean all

# TESTING =====================================================================================

check: re
		@echo "======RESULTs======\n"
		@echo "output1 = real vector testing | output2 = our vector testing\n"
		diff output1 output2
		@echo "no difference between bot outputs"

.PHONY: all clean fclean re check