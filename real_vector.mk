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
NAME	=	real_vector

# SOURCES ==================================================================================
SRCS = main2.cpp
SRCS_DIR = ./

# COMPILATION ==============================================================================
FLAGS = -Wall -Wextra -Werror -std=c++98

# OBJECTS ==================================================================================
OBJS_DIR = r_objects/
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
	@rm -rf numbers
	@rm -rf output1
	@echo -n "♻  Cleaned objects  ♻"

fclean: clean
		@echo -n "                                               \r"
		@echo -n "♻  Cleaning: $(NAME)  ♻"
		@sleep 0.3
		@echo -n "                                               \r"
		@rm -f $(NAME)
		@echo -n "♻  Cleaned everything  ♻"

re: fclean all
