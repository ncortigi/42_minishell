NAME = minishell

SRCS = 	./src/main.c \
		./src/prompt_utils.c \
		./src/free.c \
		./src/cleaner/lexer.c ./src/cleaner/expacker.c ./src/cleaner/parser.c \
		./src/cleaner/expander.c \
		./src/utils/builtin_utils.c ./src/utils/export_utils.c ./src/utils/parser_utils.c ./src/utils/cmd_utils.c \
		./src/executor/executor.c ./src/executor/redirects.c ./src/executor/builtins.c \
		./src/utils/redir_parser_utils.c \
		./src/executor/builtins2.c \
		./src/utils/parser_utils2.c \
		./src/cleaner/here_doc.c \
		./src/utils/env_utils.c \
		./src/utils/lexer_utils.c \
		./src/utils/check_export_utils.c \
		./src/utils/env_utils2.c \
		./src/utils/exe_builtins_utils.c \
		./src/utils/ft_getenv.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror -c

LIBFT = ./inc/Libft/libft.a

LINKS = -lreadline

#		42NORM_MUST_HAVE
.c.o:
	@cc $(CFLAGS) -I ./inc/ -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\033[0;32m compiling Libft...\n\033[0m"
	@make -C ./inc/Libft
	@printf "\033[0;32m compiling Minishell...\n\033[0m"
	@cc $(CFLGS) $(OBJS) $(LINKS) $(LIBFT) $(MINILIB) -o $(NAME)


clean:
	@printf "\033[0;31m cleaning Libft...\n\033[0m"
	@make clean -C ./inc/Libft
	@printf "\033[0;31m cleaning Minishell...\n\033[0m"
	@rm -f $(OBJS)


fclean: clean
	@printf "\033[0;31m fcleaning Libft...\n\033[0m"
	@make fclean -C ./inc/Libft
	@printf "\033[0;30m fcleaning Minishell...\n\033[0m"
	@rm -f $(NAME)

#		EXTRA
norm:
	@printf "\033[0;32m norminette ./Libft/*.c .h ...\n\033[0m"
	@make norm -C ./inc/Libft
	@printf "\033[0;32m norminette ./src/*.c ...\n\033[0m"
	@norminette $(SRCS)

valgrind: all
	@printf "\033[0;32m exe with valgrind...\n\033[0m"
	@valgrind --show-leak-kinds=all --leak-check=full --suppressions=readline.supp ./minishell

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o
