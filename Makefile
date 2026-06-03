NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs

LIBFT_DIR	= util/libft
PRINT_DIR	= print_functions
UTILS_DIR	= util

INCLUDES	= -I. -I$(LIBFT_DIR)

# Sorgente principale (root)
PRINTF_SRCS	= ft_printf.c

# Funzioni di stampa
PRINT_SRCS	= $(PRINT_DIR)/ft_dispatch.c \
				$(PRINT_DIR)/ft_print_char.c \
				$(PRINT_DIR)/ft_print_str.c \
				$(PRINT_DIR)/ft_print_nbr.c \
				$(PRINT_DIR)/ft_print_unsigned.c \
				$(PRINT_DIR)/ft_print_hex.c \
				$(PRINT_DIR)/ft_print_ptr.c

# Utility
UTILS_SRCS	= $(UTILS_DIR)/parse_flags.c \
				$(UTILS_DIR)/print_pad.c

# Sorgenti di libft
LIBFT_SRCS	= $(LIBFT_DIR)/ft_isdigit.c \
				$(LIBFT_DIR)/ft_strlen.c \
				$(LIBFT_DIR)/ft_itoa.c \
				$(LIBFT_DIR)/ft_itoa_hex.c \
				$(LIBFT_DIR)/ft_utoa.c \
				$(LIBFT_DIR)/ft_ultoa_hex.c

SRCS		= $(PRINTF_SRCS) $(PRINT_SRCS) $(UTILS_SRCS) $(LIBFT_SRCS)
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
