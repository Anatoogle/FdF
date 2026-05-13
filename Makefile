
CC 					= cc
CFLAGS 				= -Wall -Wextra -Werror 
MINILIBXFLAGS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES			= -I$(MLX_DIR)

MLX_DIR				= ../mlx

NAME 				= fdf
NAME_BONUS 			= fdf_bonus
NAME_PLUS 			= fdf_plus

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

SRC_PLUS			= $(SRC_DIR)/fdf_plus.c \
						$(SRC_DIR)/get_next_line_plus.c \
						$(SRC_DIR)/get_next_line_utils_plus.c \
						$(SRC_DIR)/draw_plus.c \
						$(SRC_DIR)/event_input_plus.c \
						$(SRC_DIR)/event_updates_plus.c \
						$(SRC_DIR)/parse_input_plus.c \
						$(SRC_DIR)/parse_output_plus.c \
						$(SRC_DIR)/projection_plus.c \
						$(SRC_DIR)/transformation_update_plus.c \
						$(SRC_DIR)/transformation_plus.c \
						$(SRC_DIR)/utils_plus.c

############################################################################

# convert from .c to .o
OBJ 				= $(SRC:.c=.o)

OBJ_BONUS 			= $(SRC_BONUS:.c=.o)

OBJ_PLUS 			= $(SRC_PLUS:.c=.o)

############################################################################

# Rule to compile and link only when necessary
$(NAME): $(OBJ) $(LIBFT) 
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBXFLAGS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) 
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(MINILIBXFLAGS)

$(NAME_PLUS): $(OBJ_PLUS) $(LIBFT) 
	$(CC) $(CFLAGS) -o $(NAME_PLUS) $(OBJ_PLUS) $(LIBFT) $(MINILIBXFLAGS)

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Rule to compile .c files into .o files (Prevents unnecessary relinking)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

############################################################################

all: $(LIBFT) $(NAME) 

bonus: $(LIBFT) $(NAME_BONUS) 

plus: $(LIBFT) $(NAME_PLUS)

re: fclean all

clean:
	rm -f $(OBJ) $(OBJ_BONUS) $(OBJ_PLUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(NAME_PLUS)

.PHONY: clean fclean re all bonus plus

# .PHONY:
# Prevents conflicts – If a file named clean or all exists in your directory, make might think it’s already "built" and skip the rule.
# Ensures execution – make will always run the rule, even if a file with the same name exists.
# Improves clarity – It makes it clear which targets are just commands and not actual files.