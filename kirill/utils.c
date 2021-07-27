#include "minishell.h"

void output_all(t_all *all)
{
    int i;
    int n;
    t_cmd *tmp;
    t_redirect *tmp_red;

    i = -1;
    n = 0;
    tmp = all->cmd;
    tmp_red = all->cmd->dir;
    while(tmp)
    {
        printf("------------------------------\n");
        printf("list%d:\n\n", n++);
       // printf("way = %s\n\n", tmp->way);
        while (++i < tmp->count)
        {
            printf("argv[%d] = %s\n", i, tmp->argv[i]);
        }
        printf("argv[%d] = %s\n", i, tmp->argv[i]);
        printf("way - %s\n", tmp->way);
        while(tmp_red)
        {
            printf("redirect = %d\n", tmp_red->redirect);
            printf("argv = %s\n", tmp_red->argv);
            tmp_red = tmp_red->next;
		}
		i = -1;
        printf("\n\n");
        //printf("redirect: \n\n<< - %d < - %d > - %d >> - %d\n\n",
        //tmp->dir.d_back, tmp->dir.back, tmp->dir.next, tmp->dir.d_next);
        tmp = tmp->next;
        if (tmp != NULL)
		{
			tmp_red = tmp->dir;
		}
        printf("------------------------------\n\n");
    }

}

int is_equal(char *path, char *env)
{
    int i;

    i = 0;
    while (env[i] != '\0')
    {
        if (env[i] == '=')
        {
            if (!(ft_strncmp(env, path, i)))
                return (1);
        }
        i++;
    }
    return (0);
}

char *try_find(char *path, char **env, t_all **all)
{
    int i;
    int m;
    int n;
    char *str;

    i = -1;
    m = -1;
    n = -1;
    if (!path)
        return (ft_strdup("$"));
    while(env[++n] && !(is_equal(path, env[n])))
        ;
    if (env[n] != NULL)
    {
        while(env[n][++i] != '=')
            ;
        if (ft_strlen(path) == i)
            str = ft_strdup(&(env[n][++i]));
        else
            str = ft_strdup("");
    }
    else
    {
        if (!ft_strncmp(path, "?", ft_strlen(path)))
            str = ft_itoa(g_status);
        else
            str = ft_strdup("");
    }
    free(path);
    return (str);
}

char *ft_strcpy(char *dst, char *src)
{
    int i;

    i = -1;
    while(src[++i])
        dst[i] = src[i];
    dst[i] = '\0';
    return (dst);
}

char *ft_realloc(char *ptr, size_t size)
{
    char *new;

    if (!ptr)
    {
        new = (char*)malloc(size * sizeof(char));
        if (!new)
            return (NULL);
        new[0] = '\0';
    } 
    else 
    {
        if (ft_strlen(ptr) < size)
        {
            new = (char*)malloc(size * sizeof(char));
            if (!new)
                return (NULL);
            new = ft_strcpy(new, ptr);
            free(ptr);
        } 
        else
            new = ptr;
    }
    return (new);
}

char *str_add_to_end(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    str[i] = c;
    str[++i] = '\0';
    return (str);
}

size_t	ft_strlen2(const char *s)
{
	size_t len;

    if (s == NULL)
        return(0);
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

void make_null(char ***argv, int n)
{
    int i = 0;
//    char **tmp;
//    tmp = *argv;
//    while(*tmp) {
//        *tmp = NULL;
//        tmp++;
//    }
    while (i <= n)
    {
        (*argv)[i] = NULL;
        i++;
    }
}

void	clear_arr_2x(char **a)
{
    int i;

    i = -1;
    while (a[++i])
        free(a[i]);
    free(a);
}

char   *find_binary(char *cmnd, char *paths)
{
	char  *path;
	char  **arr;
	char  **tmp;
	struct stat buf;


	path = NULL;
	if (!cmnd || !paths)
		return NULL;
	if (ft_strchr(cmnd, '/'))
		return (ft_strdup(cmnd));
	arr = ft_split(paths, ':');
	tmp = arr;
	cmnd = ft_strjoin("/", cmnd);
	while(*tmp)
	 {
	  path = ft_strjoin(*tmp, cmnd);
	  if (stat(path, &buf) == 0)
	   break;
	  free(path);
	  path = NULL;
	  tmp++;
	 }
	 free(cmnd);
	 clear_arr_2x(arr);
	 return (path);
}

void init(t_all **all)
{
    (*all)->dollar = NULL;
    (*all)->f = 0;
	(*all)->to_red = NULL;
    (*all)->cmd = ft_listnew();
}

void free_cmd(t_cmd *cmd)
{
    int i;

    i = -1;
    free(cmd->way);
    while (++i < cmd->count + 1)
        free(cmd->argv[i]);
    free(cmd->argv);
    free(cmd);
}

void free_all(t_all **all)
{
    t_cmd   *c;
    t_redirect *r;

    // TODO
    if ((*all)->dollar)
        free((*all)->dollar);
    if ((*all)->path)
        free((*all)->path);
    if((*all)->old)
        free((*all)->old);
    if ((*all)->to_red)
        free((*all)->to_red);
    c = (*all)->cmd;
    while (c)
    {
        c = c->next;
        r = (*all)->cmd->dir;
        while(r)
        {
            r = r->next;
            free((*all)->cmd->dir->argv);
            free((*all)->cmd->dir);
            (*all)->cmd->dir = r;
        }
        free_cmd((*all)->cmd);
        (*all)->cmd = c;
    }
    //free(*all);
}

int	ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}

int is_minishell(char *line)
{
    if (line == NULL || *line == '\0')
        return (0);
    if (!ft_strcmp(line, "./minishell"))
        return (1);
    return (0);
}