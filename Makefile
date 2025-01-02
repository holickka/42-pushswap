NAME = push_swap

# -------------color code-------------- #
GREEN = \033[92m
RESET = \033[0m

# -----------declare paths------------- #
INC_PATH = ./inc/
SRCS_PATH = ./srcs/
PRINTF_PATH = ./libft/ft_printf/
LIBFT_PATH = ./libft/

LIBFT = $(LIBFT_PATH)/libft.a

# -------main compiling commands------- #
CC = cc
#FSAN = -fsanitize=address -g3
# -I is used when header file is not in the same directory
INCS = -I$(INC_PATH) -I$(LIBFT_PATH) -I$(PRINTF_PATH)
FLAGS = -Wall -Wextra -Werror $(FSAN) $(INCS)
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_FILES =	push_swap.c \
				ft_convert_base.c \
				pushswap_utils_sort.c \
				pushswap_utils_radixsort.c \
				pushswap_utils_search.c
#main-test-mergesort.c push_swap.c
OBJS = $(SRCS:%.c=%.o)

# ---------lib making & remove--------- #
AR = ar -rc
RM = rm -f

# -------------main linking-------------#
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re