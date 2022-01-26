NAME:=fillit

# directories
SRC_DIR:=./src
INC_DIR:=./include
OBJ_DIR:=./obj

# src / obj files
SRC:=algorithm.c fillit.c print.c readfile.c shapes.c sqroot.c util_funcs.c
OBJ:=$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC:=gcc
CFLAGS:=-Wall -Wextra -Werror


# rules
.PHONY: all clean fclean re

all:
	mkdir -p $(OBJ_DIR)
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all 