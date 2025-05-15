NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c ft_free_if.c \
ft_freemat.c ft_freemat_if.c \
ft_mat_to_str.c ft_matdup.c ft_matjoin.c ft_matlen.c ft_matrotone.c \
ft_writemat.c ft_str_rem_chr.c ft_strcat.c ft_submat.c ft_strins.c \
ft_matins_str.c ft_mattrim.c ft_matdelstr_idx.c \
ft_realloc.c 

SRC_BONUS = ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c

OBJS = $(SRCS:.c=.o)

#OBJS_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror -c

#		42NORM_MUST_HAVE
.c.o:
	@cc $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -crs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS) 
	@ar -crs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

#		EXTRA
norm: 
	norminette $(SRCS) $(SRC_BONUS) libft.h

.PHONY: all clean fclean re bonus
.SUFFIXES: .c .o
.SILENT: all clean fclean re bonus