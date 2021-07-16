#include "minishell.h"

void output_all(t_all *all)
{
    int i;
    int n;

    i = -1;
    n = 0;
    while(all->cmd)
    {
        printf("------------------------------\n");
        printf("list%d:\n\n", n++);
       // printf("way = %s\n\n", all->cmd->way);
        while (++i < all->cmd->count)
            printf("argv[%d] = %s\n", i, all->cmd->argv[i]);
        while(all->cmd->dir)
        {
            printf("redirect = %d\n", all->cmd->dir->redirect);
            printf("argv = %s\n", all->cmd->dir->argv);
            all->cmd->dir = all->cmd->dir->next;
        }
        i = -1;
        printf("\n\n");
        //printf("redirect: \n\n<< - %d < - %d > - %d >> - %d\n\n",
        //all->cmd->dir.d_back, all->cmd->dir.back, all->cmd->dir.next, all->cmd->dir.d_next);
        all->cmd = all->cmd->next;
        printf("------------------------------\n\n");
    }
}

char *try_find(char *path, char **env)
{
    int i;
    int m;
    int n;
    char *str;

    i = -1;
    m = -1;
    n = -1;
    if (!path)
        return (ft_strdup(""));
    while(env[++n] && (ft_strncmp(path, env[n], ft_strlen(path))))
        ;
    if (env[n] != NULL)
    {
        while(env[n][++i] != '=')
            ;
        if (ft_strlen(path) == i)
            str = ft_strdup(&env[n][++i]);
        else
            str = ft_strdup("");
    }
    else
        str = ft_strdup("");
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
    while (i <= n)
    {
        (*argv)[i] = NULL;
        i++;
    }
}

void clear_arr_2x(char **a)
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

void find_path(t_all **all)
{

}