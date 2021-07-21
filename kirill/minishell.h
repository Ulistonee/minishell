#include <stdio.h>
#include <unistd.h>
#include <term.h>
#include <string.h>
#include <curses.h>
#include <termcap.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct          s_fd
{
    int                 std_input;
    int                 std_output;
}                       t_fd;

typedef struct			s_redirect{
	int					redirect;
	char				*argv;
	struct s_redirect	*next;
}						t_redirect;

typedef struct			s_cmd
{
	char				*way;
	char				**argv;
	int					count;
	t_redirect			*dir;
	struct s_cmd		*next;
}						t_cmd;

typedef struct			s_all
{
	char				*dollar;
	char				*path;
	char				**my_env;
	t_cmd				*cmd;
	int					f;
	char				*old;
	char				*to_red;
	int                 exit_code;
	t_fd                fd;
}						t_all;



int						main();
char					*ft_realloc(char *ptr, size_t size);
char					*str_add_to_end(char *str, char c);
size_t					ft_strlen2(const char *s);
void					make_null(char ***argv, int n);
void					ft_listadd_back(t_cmd **lst, t_cmd *new);
t_cmd					*ft_listnew();
t_cmd					*ft_listlast(t_cmd *lst);
void					parse_line(char *line, t_all **all);
char					*try_find(char *path, char **env, t_all **all);
void					output_all(t_all *all);
char					*find_binary(char *cmnd, char *paths);
void					find_path(t_all **all);
void					redirect_back(t_redirect **lst, t_redirect *new);
t_redirect				*new_redirect();
t_redirect				*redirect_last(t_redirect *lst);
void                    redirect2(char *line, int *i, t_all **all);
void                    redirect3(char *line, int *i, t_all **all);
void                    redirect4(char *line, int *i, t_all **all);
void					free_all(t_all **all);

// new below:
int                     my_echo(char **argv);
int			            my_cd(char **argument, char ***envp_cp);
void				    handle_error(char *message, t_all *all);
int                     my_pwd();
int			            my_export(char **argv, char ***envp_cp);
void		            read_envp(t_all *all, char const *envp[]);
void                    my_fork(t_all *all);
void                    print_arr_2x(char **array);
char				    *get_value(char **envp_cp, char *key);
char			        *check_arg(char **envp_cp, char **key);
void                    sort_array_2x(char **array);
int                     count_envp(char **envp_cp);
void				    executor(t_all **all);
void                    execute_binary(char *binary_path, char **argv, char ***envp_cp, int *exit_code);
int                     builtins(t_cmd *tmp, char ***envp, int *exit_code);
int                     fail(char *str, int res);
int                     count_arguments(char **argv);
int                     my_unset(char ***envp_cp, char *argument);
int 				    my_env(char **envp_cp, char **argv);
void                    another_exit(char **argv, int *exit_code);
char		            **copy_arrays_2x(char **src_arr);
void                    clear_arr_2x(char **a);






