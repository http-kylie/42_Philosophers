# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 12:15:52 by kytan             #+#    #+#              #
#    Updated: 2024/10/11 12:27:04 by kytan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = philo

# COLORS & TEXT FORMATTING
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
BLINK = \033[5m
INVERT = \033[7m
LIGHT_BLUE = \033[94m
YELLOW = \033[93m

# SOURCE AND OBJECT FILES
SRC_DIR = src
SRC = main.c
vpath %.c $(SRC_DIR)

OBJ_DIR = obj
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
vpath %.o $(OBJ_DIR)

# HEADERS
HEADER_DIR = include
INCLUDE = -I$(HEADER_DIR)

# FLAGS
WARNINGS = -Wall -Wextra -Werror
DEBUG = -ggdb
DSYM = -g3
FSANT = -fsanitize=thread $(DSYM)
FSANA = -fsanitize=address $(DSYM)
CFLAGS = $(DEBUG) $(WARNINGS) $(INCLUDE) -pthread $(FSANT)

# COMMANDS
CC = cc
RM = rm -rf
COMPILE = $(CC) $(CFLAGS)

all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "$(BOLD)$(LIGHT_BLUE)Generating philo executable...$(RESET)"
	@$(COMPILE) $(OBJ) -o $(EXEC)
	@clear
	@echo "$(BOLD)$(LIGHT_BLUE)$(EXEC) created successfully!$(RESET)"
	@echo "$(BOLD)Compile Completed!$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(BOLD)$(YELLOW)Compiling $<...$(RESET)"
	@$(COMPILE) -c $< -o $@

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning object files...$(RESET)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning executable...$(RESET)"
	@$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re