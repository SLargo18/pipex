NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g3 
INCLUDES = -I./include
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/error.c \
       $(SRC_DIR)/pipex.c \
       $(SRC_DIR)/processes.c \
       $(SRC_DIR)/split.c \
       $(SRC_DIR)/strjoin.c \
       $(SRC_DIR)/utils_pipex.c \
       $(SRC_DIR)/utils.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADERS = $(INC_DIR)/pipex.h

all: $(NAME)
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(CYAN)Creating object directory...$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean $(NAME)
	@echo "$(MAGENTA)Debug version compiled!$(RESET)"

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(RED)Object files removed.$(RESET)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED)$(NAME) removed.$(RESET)"; \
	fi

re: fclean all

help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)              - Build the program"
	@echo "  $(GREEN)clean$(RESET)            - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)           - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)               - Rebuild everything"
	@echo "  $(GREEN)help$(RESET)             - Show this help"

.PHONY: all clean fclean re debug test test-performance test-500 help
.PRECIOUS: $(OBJ_DIR)/%.o