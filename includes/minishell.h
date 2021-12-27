#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <termcap.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <../libft/libft.h>
# include <../ft_printf/ft_printf.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define DEFAULT "\033[0m"

typedef struct s_env
{
	char			*id;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_main
{
	char				*save_line;
	int					test;
	int					bottom;
	int					found;
	int					pos;
	int					len;
	int					i;
	char				*line;
	int					ret_funct;
	int					is_pipe;
	char				*path;
	pid_t				pid;
	int					backfd0;
	int					backfd1;
	int					backfd2;
	int					*p;
	int					dquote;
	int					squote;
	int					status;
	int					start;
	char				**cmd;
	struct s_list		*free_lst;
	struct s_env		env;
	struct s_history	*pipe;
	struct s_utils		*utils;
}	t_main;

typedef struct s_int
{
	int					val;
	struct s_int		*next;
}	t_int;

typedef struct s_history
{
	char				*line;
	struct s_history	*next;
	struct s_history	*previous;
}	t_history;

typedef struct s_redirection
{
	char					*line;
	int						quotes;
	int						fd;
	struct s_redirection	*next;
}	t_redirection;

typedef struct s_termcaps
{
	char	*le;
	char	*dc;
	char	*nd;
	char	*im;
	char	*ei;
	char	*ic;
}	t_termcaps;

typedef struct s_utils
{
	size_t	i;
	size_t	wi;
	int		sq;
	int		dq;
	int		start;
	int		end;
}	t_utils;

typedef struct s_threestr
{
	char	*str1;
	char	*str2;
	char	*str3;
}	t_threestr;

/*
---------------------------------------
**	BUILTINS
---------------------------------------
*/
/*
**	BUILTINS
*/
char			*parse_line(char *line, t_env *env, t_main *main);
char			*parse_line2(char **command, char *line, int *i);
int				ft_builtins(t_env *env, t_main *main, char *line);
void			ft_builtins2(t_env *env, char **envp, t_main *main, char *line);

/*
**	CD
*/
void			change_pwd_env(t_env *env, char *id);
int				home_path(t_env *env);
int				cd(char *line, t_env *env);

/*
**	COMMANDS
*/
void			exit_2arg(t_main *main);
void			exit_minishell(t_main *main, char *line);
int				display_env(char *line, t_env env);
void			inc_shell_lv(t_env **env);
void			replace_global_err(t_main *main);
/*
**	ECHO
*/
void			ft_echo_n2(char *line, int *loop, int *i, int *start);
void			ft_echo_n(char *line, int *start, int *loop, int *option);
void			ft_echo2(char *line);
int				ft_echo(t_main *main, char *line);
/*
**	EXPORT
*/
void			only_id(t_env **lst, char *str, int *i, t_env **env);
void			add_arg(t_env **env, char *str, int *i);
int				ft_export2(t_env **env, char **split, int *i);
int				ft_export(char *line, t_env **env);
/*
**	EXPORT2
*/
void			parse_arg2(char *str, int *error, char **tmp, int *i);
void			join_id_val(char *str, char *tmp, int *i, t_env **env);
void			without_equal(char *str, t_env **env, t_env **lst);
int				parse_arg(char *str, t_env *lst, t_env **env);
/*
**	OPEN_FILE
*/
void			open_fd(t_redirection *chevron, int *fd);
int				fd_error(t_redirection *chevron, t_main *main,
					t_int *beginfd, int fd);
int				open_file(t_redirection *chevron, t_main *main);
void			create_copy_fd(int chevron_fd, int fd);
void			get_back_fd(t_main *main);
/*
**	PWD
*/
int				pwd(char *line);
/*
**	UNSET
*/
int				unset(char *line, t_env *env);
/*
---------------------------------------
**	HEREDOC
---------------------------------------
*/
/*
**	HEREDOC
*/
int				init_heredoc(char *eof);
char			*input_heredoc(char *eof);
int				heredoc(char **cmd);
char			*ft_strnew(size_t size);
char			*ft_strjoinf(char const *s1, char const *s2, int i);
/*
---------------------------------------
**	INITIALISATION
---------------------------------------
*/
/*
**	INITIALISATION
*/
t_env			init_envir(char **env);
t_main			*init_main(t_env *env);
t_termcaps		*init_termcaps(void);
void			init_signal(void);
int				ft_signal(int *status);
/*
**	INITIALISATION2
*/
void			set_history(t_history **history, t_history **lst,
					int ac, char **av);
int				ms_init(char const *s, t_utils	**split_s,
					int *nb_word, char ***split);
t_utils			*init_utils(void);
t_threestr		*init_struct_threestr(void);
void			set_zero_utils(t_utils **utils);
/*
---------------------------------------
**	LST_FUNCTIONS
---------------------------------------
*/
/*
**	LSTFCT
*/
t_env			*ft_lstnew(char *id, char *value);
t_int			*ft_lstnewint(int value);
void			ft_lstadd_back_int(t_int **alst, t_int *new);
t_int			*ft_lstlast_int(t_int *lst);
t_env			*ft_lstlast(t_env *lst);
/*
**	LSTFCT2
*/
void			swap_lst_env(t_env **lst1, t_env **lst2, t_env **lst3);
int				reset_var_lstsort(t_env **begin, t_env **lst,
					t_env **prev, t_env **next);
void			ft_lstsort(t_env **begin);
t_env			*list_copy(t_env *env);
/*
**	LSTFCT3
*/
void			ft_lstadd_back(t_env **alst, t_env *new);
void			ft_lstdelone(t_env *lst);
void			ft_lstremoveif(t_env **begin, char *id);
void			ft_2dstrdel(char ***as);
void			ft_strdel(char **ap);
/*
**	LSTFCT4
*/
t_redirection	*ft_lstnew_chevron(char *file, int quotes, int fd);
void			ft_lstadd_back_redirection(t_redirection **alst,
					t_redirection *new);
t_redirection	*ft_lstlast_redirection(t_redirection *lst);

/*
---------------------------------------
**	PARSING
---------------------------------------
*/
/*
**	DOLLAR
*/
char			*new_str_dollar_replace(char *str, t_env *env,
					int start, size_t *end);
char			*substitute_dollar(char *str, size_t *index, t_env *env);
void			replace_dollar2(char **split, size_t *i, size_t *j);
void			replace_dollar(char **split, t_env *env);
/*
**	MS_COUNT_WORD
*/
char			*ms_malloc_word(char const *s);
char			*ms_malloc_word_sub(char const *s, int *qst,
					int *sqst, size_t *size);
/*
**	MS_SPLIT_SUB
*/
void			ms_split_sub1(char const *s, t_utils *sp,
					char **split, int chevron);
char			*ms_split_sub2(char const *s, t_utils *sp,
					char **split, int chevron);
char			*ms_split_sub3(char const *s, t_utils *sp,
					char **split, int chevron);
/*
**	MS_SPLIT
*/
char			**ms_split(char const *s);
void			ms_split_1(char const *s, t_utils *sp,
					char **split, int redir);
void			ms_split_2(char const *s, t_utils *sp,
					char **split, char *str);
/*
**	MS_SPLIT2
*/
void			count_word2(char const *s, size_t *count, size_t *index,
					char redir);
void			count_word_digit(char const *s, size_t *count, size_t *index,
					char redir);
void			ft_count_word(char const *s, size_t *count, size_t *index);
int				ms_count_word2(char const *s, size_t *i, int *redir,
					size_t *count);
int				ms_count_word(char const *s);
/*
**	MS_SPLIT3
*/
void			remove_quotes_dq(t_threestr **str, t_utils **iq,
					int i, char **line);
void			remove_quotes_sq(t_threestr **str, t_utils **iq,
					int i, char **line);
void			remove_quotes(char **line);
/*
**	PARSING
*/
void			parse_env(char *str, char **id, char **value);
char			**ft_new_array(char **new_array, char *line);
char			**ft_addto_array(char **array, char *line);
t_redirection	*parse_redirection(char ***split);
/*
**	REDIRECTIONS
*/
void			ft_redir_digit(t_utils *utils, char ***split,
					t_redirection **chevron, int q);
void			ft_redir_1(t_utils *utils, char ***split,
					t_redirection **chevron, int q);
void			ft_redir_0(t_utils *utils, char ***split,
					t_redirection **chevron, int q);
void			multi_digit_redir(t_utils *utils, char ***split,
					t_redirection **chevron, char ***new_split);
void			ft_redir(t_utils *utils, char ***split,
					t_redirection **chevron,
					char ***new_split);

/*
---------------------------------------
**	PIPE
---------------------------------------
*/
/*
**	PIPE
*/
void			child_pipe2(char **command, char **cmd);
void			child_pipe(char **envp, t_main *main, char **command,
					t_int *fd_in);
void			parent_pipe(t_main *main, t_int **fd_in, t_int **begin_fdin);
void			exec_pipe2(t_main *main, char **envp, t_int **begin_fdin);
int				exec_pipe(char **envp, t_main *main);
/*
**	PIPE2
*/
int				init_pipe(int **pfd, int *pid);
void			create_pipe(t_main *main, char **command, char **envp);
void			cmd_pipe2(t_main *main, size_t *i, t_history **begin,
					t_history **current);
t_history		*find_cmd_piped(t_main *main);

/*
---------------------------------------
**	TERMCAPS
---------------------------------------
*/
/*
**	HISTORY
*/
t_history		*ft_lstnew_history(t_main *main);
t_history		*ft_lstnew_history2(char *str);
t_history		*ft_lstlast_history(t_history *lst);
void			ft_lstadd_back_history(t_history **history, t_history *new);
void			init_history(t_main *main, t_history **history);
/*
**	PRESS_ARROW
*/
void			press_up(t_main *main, t_history **lst);
void			press_bottom(t_main *main, t_history **lst);
void			press_enter2(t_main *main);
void			press_enter3(t_main *main, char **envp, t_env *env);
void			press_enter(t_main *main, t_history **history,
					char **envp, t_env *env);
/*
**	PRESS_ARROW2
*/
void			ft_delete_line(t_main *main);
void			press_delete(t_main *main);
char			*modify_line(char *buf, t_main *main);
void			bottom_without_next(t_main *main);
int				arrow_del(char *buf, t_main *main, t_history **lst);

/*
---------------------------------------
**	
---------------------------------------
*/
/*
**	CTRL
*/
void			ctrl_c(int sig);
void			init_ctrl_c(int sig);
void			init_back_slash(int sig);
void			ctrl_d_disable(void);
void			ctrl_d_able(void);
/*
**	EXEC
*/
void			check_exec(char **command, char **envp,
					int *status, char *path);
int				ft_execve(char **envp, char *path, char *line);
/*
**	EXIT
*/
void			ft_exit(char *msg, char *pb, int ex, int error);
/*
**	MAIN
*/
void			init_sig_term(void);
int				main(int ac, char **av, char **envp);
/*
**	PATH
*/
char			*good_path(t_main *main, char **split_path);
char			*get_current_path(t_main *main);
void			missing_path(t_main *main, t_env *env);
char			*find_path(t_env *env, t_main *main);
char			*good_path_cmd(char *cmd, char **split_path);
/*
**	STATIC_STRUCT
*/
t_main			*set_main(t_main *tmp);
t_main			*get_main(void);
/*
**	UTILS
*/
int				skip_space(char *str);
void			display(t_env *env);
void			display_export(t_env *env);
int				find_char(char *str, char c);
int				putchar_int(int ch);
/*
**	UTILS2
*/
int				check_id(char *str, char *tmp, t_env *env);
char			*find_path_cmd(char **envp, char *cmd);
void			init_terminal_data(void);
int				sep(char sep);
void			close_fd(t_int *begin_fdin);
/*
**	UTILS3
*/
void			put_termcaps(char *buf);
int				ft_isdollar_break(char c);
int				ft_isquote(char c);
void			change_quotes_state(char c, int *dbquote,
					int *squote, size_t *size);
void			ft_arrow(char *buf, t_main *main, t_history **lst);

#endif
