/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:23:13 by ncortigi          #+#    #+#             */
/*   Updated: 2023/07/25 16:23:13 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stddef.h>
# include <signal.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include "Libft/libft.h"

# define EMPTY 0
# define CMD 1
# define ARG 2
# define PIPE 3
# define AND 4
# define OR 5
# define COMMA 6
# define INPUT 7
# define OUTPUT 8
# define IAPPEND 9
# define OAPPEND 10
# define IOFILE 11 
# define REDIR 12
# define OWRITE 13
# define OBRACKETS 14
# define CBRACKETS 15

/* error define */

# define MALL_ERR "\e[1;31mERROR WHILE CREATING MALLOC\n\e[0m"
# define FR_ERR "\e[1;31mERROR WHILE CREATING FORK\n\e[0m"
# define PIPE_ERR "\e[1;31mERROR WHILE CREATING PIPE\n\e[0m"
# define DUP_ERR "\e[1;31mERROR WHILE CREATING DUP\n\e[0m"
# define OPEN_ERR "\e[1;31mERROR WHILE CREATING OPEN\n\e[0m"
# define CMD_ERR "command not found\n"
# define SYNTAX_ERR "syntax error\n"
# define FILE_NOT_EXE "Not executable file\n"
# define NO_FILE "No such file or directory\n"
# define NA_FILE "syntax error near unexpected token `newline'\n"
# define SYNTAX_ERR2 "syntax error near unexpected token '"

extern int				g_status;

typedef struct s_cmnd	t_cmd;

typedef struct s_data
{
	char	**envp;
	char	**export;
	t_cmd	**cmd_ast;
	int		original_std_fd[2];
}	t_data;

typedef struct s_red
{
	int				token;
	char			*out_fd;
	char			*in_fd;
	struct s_red	*next;
}	t_red;

typedef struct s_cmnd
{
	char			*path;
	char			**args;
	t_red			**redir;
	struct s_cmnd	*next;
}	t_cmd;

//main.c
t_data	*ft_init_data(char **envp);
void	ft_run_shell(t_data *data);
t_cmd	**ft_parse_input(char *line, t_data *data);

//prompt_utils.c
t_data	*ft_init_data(char **envp);
char	*ft_return_prompt(void);
void	ft_siginthandler(int sign);

//free.c
void	ft_freecmdast(t_cmd **cmd);
void	ft_freedata(t_data *data);
void	ft_reset_cmdline(t_data *data);
void	ft_freecmd(t_cmd *cmd);

//                       CLEANER
//cleaner/lexer.c
char	**ft_lex_input(char *line, int j);
char	*ft_wdcleaner(char *line, char *token, int *str_pos);
int		ft_wdlen(char *line, char *set);
char	*ft_redcleaner(char *str, int *str_pos);

//cleaner/expacker.c
char	*ft_check_dollar(char *cmd, t_data *data);
int		ft_expacker(char **cmd, t_data *data);
int		ft_syntax_check_redir(char **cmd, int pos);
int		ft_syntax_check_quotes(char **cmd, int pos);
int		ft_syntax_check_special_char(char **cmd, int pos);

//cleaner/here_doc.c
char	*ft_here_doc(char *limit); 

//cleaner/expander.c
char	*ft_expander(char **mat, t_data *data, int s);

//cleaner/parser.c
t_cmd	**ft_parser(char **cmnd_mat, int i, int j, t_data *data);
char	**ft_check_heredoc(char **cmd_mat);
char	**ft_dividetimpera(char **cmnd_mat, int *pos);

//                       EXECUTOR
//executor/exe_external.c
int		ft_executor(t_cmd *cmd, t_data *data, int old_in, int n_piped);
int		ft_exe_builtin(t_cmd *cmnd, t_data *data);
int		ft_exe_external(t_cmd *cmd, t_data *data);

//executor/builtins.c
int		ft_echo(char **args);
int		ft_cd(char **args, t_data *data);
int		ft_unset(char **args, t_data *data);
int		ft_pwd(void);

//executor/builtins2.c
int		ft_exit(char **args);
int		ft_export(char **comm, t_data *data);

//env_utils
void	ft_env_change(t_data *data, char *var, char *full_var);
char	**ft_env_remove(char *var, t_data *data);
char	**ft_env_add(t_data *data, char *var);
void	ft_export_var(char *arg, t_data *data);
int		ft_env(char **args, t_data *data);
char	*ft_getenv(char *var, char **data);
int		ft_env_search(char *var, char **env);
int		ft_env_varname_search(char *var, char **matrix);

char	**ft_getcmd_args(char **tmp, int *pos);
char	*ft_get_cmd_path(char *cmd, t_data *data);

//utils/redir_parser_utils.c
t_red	*ft_redir_new(t_cmd *cmd, char **mat, int *pos);
void	ft_redir_new_grt(char **mat, int pos, t_red *redir, t_cmd *cmd);
void	ft_redir_new_lwr(char **mat, int pos, t_red *redir);
void	ft_redir_add_back(t_red **redir, t_red *node);

//utils/parser_utils.c
t_cmd	*ft_cmd_node_gen(char **cmd_mat, int i, t_data *data);
void	ft_cmd_ast_add_back(t_cmd **cmnd_lst, t_cmd *node);
char	**ft_mat_rm_line(int rm_line, char **mat);

//utils/parser_utils2.c
char	**ft_single_to_double(char **mat);
int		ft_if_free_args(char **args, int j);
char	*ft_trim_if(char **args, int j);
void	ft_parse(t_cmd *node, int j);

// executor_utils.c
void	ft_print_error(int i);
int		ft_redir(t_red **redir, t_data *data);
int		ft_redir_grt(t_red *redir, t_data *data);
int		ft_redir_lwr(t_red *redir, t_data *data);
int		ft_is_builtin(char *cmd);

//  builtin_utils.c
void	ft_pwd_replace(t_data *data, int line);
int		ft_exit_or_continue(t_cmd **cmd);
char	*ft_return_format(char *line);
int		ft_error_exit(t_cmd **cmd, int control);

//utils/lexer_utils.c
int		ft_check_clean(char c);
char	*ft_clean(char *line, int *i);

//  export_utils.c
char	**ft_make_export(t_data *data);
char	*ft_export_format(char *min);
char	*ft_find_next(char *min, char *max, t_data *data);
char	*ft_find_max(t_data *data);
char	*ft_find_min(t_data *data);

//utils/check_export_utils.c
int		ft_check_exportvar_int(char *arg);
char	*ft_join_and_remove(char **args, int i, int what);
int		ft_check_var_content(char **args, int i, int check);

#endif