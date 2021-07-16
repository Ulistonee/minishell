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
}						t_all;



int						main();
void					my_echo(t_all *all);
void					my_cd(int argc, t_all *all, char const *envp[]);
void					handle_error(char *message, t_all *all);
char					*ft_realloc(char *ptr, size_t size);
char					*str_add_to_end(char *str, char c);
size_t					ft_strlen2(const char *s);
void					make_null(char ***argv, int n);
void					ft_listadd_back(t_cmd **lst, t_cmd *new);
t_cmd					*ft_listnew();
t_cmd					*ft_listlast(t_cmd *lst);
void					parse_line(char *line, t_all **all);
char					*try_find(char *path, char **env);
void					output_all(t_all *all);
char					*find_binary(char *cmnd, char *paths);
void					find_path(t_all **all);
void					redirect_back(t_redirect **lst, t_redirect *new);
t_redirect				*new_redirect();
t_redirect				*redirect_last(t_redirect *lst);
void redirect2(char *line, int *i, t_all **all);
void redirect3(char *line, int *i, t_all **all);
void redirect4(char *line, int *i, t_all **all);
