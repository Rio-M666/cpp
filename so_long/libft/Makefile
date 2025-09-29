NAME = libft.a

LIBFT_SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c \
	ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c \
	ft_toupper.c ft_memcmp.c ft_strlcpy.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_split.c ft_putstr.c

FT_PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/ft_printf_units.c ft_printf/libft.c
GNL_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c

ALL_SRCS = $(LIBFT_SRCS) $(FT_PRINTF_SRCS) $(GNL_SRCS)
OBJS = $(ALL_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -Ift_printf -Ignl -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
