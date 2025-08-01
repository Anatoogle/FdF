
CC 					= cc
CFLAGS 				= -Wall -Wextra -Werror 
MINILIBXFLAGS		= -lX11 -lXext -lmlx -lm

NAME 				= fdf
NAME_BONUS 			= fdf_bonus

SRC_DIR 			= src

LIBFT_DIR 			= ./libft
LIBFT 				= $(LIBFT_DIR)/libft.a

############################################################################

SRC 				= $(SRC_DIR)/fdf.c \
						$(SRC_DIR)/get_next_line.c \
						$(SRC_DIR)/get_next_line_utils.c \
						$(SRC_DIR)/draw.c \
						$(SRC_DIR)/event_input.c \
						$(SRC_DIR)/event_updates.c \
						$(SRC_DIR)/parse_input.c \
						$(SRC_DIR)/parse_output.c \
						$(SRC_DIR)/projection.c \
						$(SRC_DIR)/transformation_update.c \
						$(SRC_DIR)/transformation.c \
						$(SRC_DIR)/utils.c

SRC_BONUS			= $(SRC_DIR)/fdf_bonus.c \
						$(SRC_DIR)/get_next_line_bonus.c \
						$(SRC_DIR)/get_next_line_utils_bonus.c \
						$(SRC_DIR)/draw_bonus.c \
						$(SRC_DIR)/event_input_bonus.c \
						$(SRC_DIR)/event_updates_bonus.c \
						$(SRC_DIR)/parse_input_bonus.c \
						$(SRC_DIR)/parse_output_bonus.c \
						$(SRC_DIR)/projection_bonus.c \
						$(SRC_DIR)/transformation_update_bonus.c \
						$(SRC_DIR)/transformation_bonus.c \
						$(SRC_DIR)/utils_bonus.c

############################################################################

# convert from .c to .o
OBJ 				= $(SRC:.c=.o)

OBJ_BONUS 			= $(SRC_BONUS:.c=.o)

############################################################################

# Rule to compile and link only when necessary
$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBXFLAGS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) 
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(MINILIBXFLAGS)

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Rule to compile .c files into .o files (Prevents unnecessary relinking)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

############################################################################

all: $(LIBFT) $(NAME) 

bonus: $(LIBFT) $(NAME_BONUS) 

re: fclean all

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

.PHONY: clean fclean re all bonus

# .PHONY:
# Prevents conflicts – If a file named clean or all exists in your directory, make might think it’s already "built" and skip the rule.
# Ensures execution – make will always run the rule, even if a file with the same name exists.
# Improves clarity – It makes it clear which targets are just commands and not actual files.