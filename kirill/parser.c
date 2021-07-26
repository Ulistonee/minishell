#include "minishell.h"

static void count_argv2(char *line, int *i, int *k, int *c)
{        
    if (line[*i] == '\"')
    {
        while (line[++(*i)] && line[*i] != '\"')
            *k = 1;
        if (line[*i] == '\"')
                (*i)++;
    }
    while (ft_isalnum(line[*i]) || line[*i] == '_')
    {
        (*i)++;
        if (line[*i] == '\'')
        {
            while (line[++(*i)] && line[*i] != '\'')
                ;
            if (line[*i] == '\'')
                (*i)++;
        }
        if (line[*i] == '\"')
        {
            while (line[++(*i)] && line[*i] != '\"')
            ;
             if (line[*i] == '\"')
                (*i)++;
        }
        *k = 1;
    }
    if (line[*i] == '>' || line[*i] == '<')
    {
            if (line[*i] == '>')
            {
                (*i)++;
                if (line[*i - 1] == '>' && line[*i] == '>')
                {
                    (*i)++;
                }
                (*c)++;
            }
            if (line[*i] == '<')
            {
                (*i)++;
                if (line[*i - 1] == '<' && line[*i] == '<')
                {
                    (*i)++;
                }
                (*c)++;
            }
    }
}

static int count_argv(char *line, int i)
{
    int n;
    int k;
    int c;

    n = 0;
    k = 0;
    c = 0;
    while (line[i] && line[i] != '|')
    {
        while (line[i] == ' ')
            i++;
        if (line[i] == '\'')
        {
            while (line[++i] && line[i] != '\'')
                k = 1;
            if (line[i] == '\'')
                i++;
        }
        count_argv2(line, &i, &k, &c);
        if (k)
            n++;
        k = 0;
    }
    n = n - c;
    if (n < 0)
        n = 0;
    return (n);
}

void parse_line2(char *line, int *i, int *m, t_all **all)
{
        while (line[*i] == ' ')
        {
            (*i)++;
            (*all)->f = 0;
        }
        if ((*all)->f == 0 && (*all)->cmd->argv[*m] != NULL)
        {
            (*m)++;
            (*all)->f = 1;
        }
        if (line[*i] == '\'')
        {
            while (line[++(*i)] != '\'' && line[*i])
            {
                (*all)->cmd->argv[*m] = ft_realloc((*all)->cmd->argv[*m], ft_strlen2( (*all)->cmd->argv[*m]) + 2);
                (*all)->cmd->argv[*m] = str_add_to_end((*all)->cmd->argv[*m], line[*i]);
                (*all)->f = 1;  
            }
            if (line[*i] == '\'')
                (*i)++;
            //(*m)++;
        }
}


void parse_line3_1(char *line, int *i, int *m, t_all **all)
{
    if (line[*i] == '$')
                {
                    (*i)++;
                    while (ft_isalnum(line[*i]) || line[*i] == '_')
                    {
                        (*all)->dollar = ft_realloc( (*all)->dollar, ft_strlen2((*all)->dollar) + 2);
                         (*all)->dollar = str_add_to_end((*all)->dollar, line[*i]); 
                        (*i)++;
                    }
                     (*all)->dollar = try_find( (*all)->dollar, (*all)->my_env, all);
                     (*all)->old = (*all)->cmd->argv[*m];
                    if (!(*all)->cmd->argv[*m])
                        (*all)->cmd->argv[*m] = ft_strdup("");
                     (*all)->cmd->argv[*m] = ft_strjoin( (*all)->cmd->argv[*m], (*all)->dollar);
                    free( (*all)->old);
                    free( (*all)->dollar);
                     (*all)->dollar = NULL;
                    (*all)->old = NULL;
                }
                else
                {
                     (*all)->cmd->argv[*m] = ft_realloc( (*all)->cmd->argv[*m], ft_strlen2( (*all)->cmd->argv[*m]) + 2);
                     (*all)->cmd->argv[*m] = str_add_to_end( (*all)->cmd->argv[*m], line[(*i)++]);
                }
                 (*all)->f = 1;
}

void parse_line3(char *line, int *i, int *m, t_all **all)
{
    if (line[*i] == '\"')
        {
            (*i)++;
            while (line[*i] != '\"' && line[(*i)])
                parse_line3_1(line, i, m, all);
            if (line[*i] == '\"')
                (*i)++;
            //(*m)++;
        }
}

void parse_line4_1(char *line, int *i, int *m, t_all **all)
{
    if (line[*i] == '$')
    {
                    while (ft_isalnum(line[*i]) || line[*i] == '_')
                    {
                        (*all)->dollar = ft_realloc((*all)->dollar, ft_strlen2((*all)->dollar) + 2);
                        (*all)->dollar = str_add_to_end((*all)->dollar, line[*i]);
						(*i)++;
                    }
                    (*all)->dollar = try_find((*all)->dollar, (*all)->my_env, all);
                    (*all)->old = (*all)->cmd->argv[*m];
                    if (!(*all)->cmd->argv[*m])
                        (*all)->cmd->argv[*m] = ft_strdup("");
                   (*all)->cmd->argv[*m] = ft_strjoin((*all)->cmd->argv[*m], (*all)->dollar);
                    free((*all)->old);
                    free((*all)->dollar);
                    (*all)->dollar = NULL;
                    (*all)->old = NULL;
    }
                else
                {
                    (*all)->cmd->argv[*m] = ft_realloc((*all)->cmd->argv[*m], ft_strlen2((*all)->cmd->argv[*m]) + 2);
                    (*all)->cmd->argv[*m] = str_add_to_end((*all)->cmd->argv[*m], line[*i]);
                    (*i)++;
                }
}
void parse_line4(char *line, int *i, int *m, t_all **all)
{
           while (ft_isalnum(line[*i]) || line[*i] == '_')
        {
            (*all)->f = 0;
            if (line[*i] == '\'')
            {
                while (line[++(*i)] && line[*i] != '\'')
                {
                   (*all)->cmd->argv[*m] = ft_realloc((*all)->cmd->argv[*m], ft_strlen2((*all)->cmd->argv[*m]) + 2);
                   (*all)->cmd->argv[*m] = str_add_to_end((*all)->cmd->argv[*m], line[*i]);
                }
                 if (line[*i] == '\'')
                    (*i)++;
            }
            else if (line[*i] == '\"')
            {
                while (line[++(*i)] && line[*i] != '\"')
                {
                    (*all)->cmd->argv[*m] = ft_realloc((*all)->cmd->argv[*m], ft_strlen2((*all)->cmd->argv[*m]) + 2);
                    (*all)->cmd->argv[*m] = str_add_to_end((*all)->cmd->argv[*m], line[*i]);
                }
                if (line[*i] == '\"')
                    (*i)++;
            }
            else
                parse_line4_1(line, i, m, all);
        }
}

void parse_line5_1(char *line, int *i, int *m, t_all **all)
{
    if (line[*i] == '|')
    {
                *m = 0;
                (*all)->cmd->way = find_binary((*all)->cmd->argv[0], (*all)->path);
                ft_listadd_back(&(*all)->cmd, ft_listnew());
                (*all)->cmd = ft_listlast((*all)->cmd);
                (*i)++;
                (*all)->f = 0;
                (*all)->cmd->count = count_argv(line, *i);
                (*all)->cmd->argv = (char**)malloc(sizeof(char*) * ((*all)->cmd->count + 1));
                make_null(&(*all)->cmd->argv, (*all)->cmd->count);
                (*all)->to_red = NULL;
                (*all)->old = NULL;
				(*all)->cmd->way = NULL;
    }
}

void parse_line5(char *line, int *i, int *m, t_all **all)
{
    t_redirect *p;
        if (line[*i] == '>' || line[*i] == '<')
        {
            redirect_back(&(*all)->cmd->dir, new_redirect());
            p = (*all)->cmd->dir;
            (*all)->cmd->dir = redirect_last((*all)->cmd->dir);
            if (line[*i] == '>')
            {
                (*all)->cmd->dir->redirect = 1;
                (*i)++;
                if (line[*i - 1] == '>' && line[*i] == '>')
                {
                    (*all)->cmd->dir->redirect = 2;
                    (*i)++;
                }
            }
            if (line[*i] == '<')
            {
                (*all)->cmd->dir->redirect = 3;
                (*i)++;
                if (line[*i - 1] == '<' && line[*i] == '<')
                {
                    (*all)->cmd->dir->redirect = 4;
                    (*i)++;
                }
            }
            redirect2(line, i, all);
            redirect3(line, i, all);
            redirect4(line, i, all);\
            if (!(*all)->to_red)
                (*all)->to_red = ft_strdup("");
            (*all)->cmd->dir->argv = ft_strdup((*all)->to_red);
            free((*all)->to_red);
            (*all)->cmd->dir = p;
            (*all)->to_red = NULL;
        }
        parse_line5_1(line, i, m, all);
}

void parse_line(char *line, t_all **all)
{
    t_cmd *first;
    int i;
    int m;

    (*all)->dollar = NULL;
    i = 0;
    m = 0;
    (*all)->f = 0;
	(*all)->to_red = NULL;
    (*all)->cmd = ft_listnew();
    first = (*all)->cmd;
    (*all)->old = NULL;
    (*all)->cmd->count = count_argv(line, i);
    (*all)->cmd->argv = (char**)malloc(sizeof(char*) * ((*all)->cmd->count + 1));
    (*all)->cmd->way = NULL;
    make_null(&(*all)->cmd->argv, (*all)->cmd->count);
    (*all)->path = try_find("PATH", (*all)->my_env, all);
    while (line[i])
    {
        parse_line2(line, &i, &m, all);
        parse_line3(line, &i, &m, all);
        parse_line4(line, &i, &m, all);
        parse_line5(line, &i, &m, all);
    }
    if(!(*all)->cmd->way)
        (*all)->cmd->way = find_binary((*all)->cmd->argv[0], (*all)->path);
    (*all)->cmd = first;
   // free(path);
}

/*void parse_line(char *line, t_all **all)
{
    t_cmd *list;
    t_cmd *first;
    int i;
    int m;
    int k;
    int f;
    char *path;
    char *old;

    path = NULL;
    i = 0;
    m = -1;
    f = 0;
    list = ft_listnew();
    first = list;
    list->count = count_argv(line, i);
    list->argv = (char**)malloc(sizeof(char*) * list->count);
    make_null(&list->argv, list->count);
    while (line[i])
    {
        while (line[i] == ' ')
            i++;
        if (f == 0)
        {
            m++;
            f = 1;
        }
        if (line[i] == '\'')
        {
            while (line[++i] != '\'' && line[i])
            {
                list->argv[m] = (char*)realloc(list->argv[m], ft_strlen2(list->argv[m]) + 1);
                list->argv[m] = str_add_to_end(list->argv[m], line[i]);
                f = 1;  
            }
            if (line[i] == '\'')
                i++;
            m++;
        }
        if (line[i] == '\"')
        {
            i++;
            while (line[i] != '\"' && line[(i)])
            {
                if (line[i] == '$')
                {
                    i++;
                    while (line[i] != ' ' && line[i] != '\'' && line[i] != '\"'
                        && line[i] != '|' && line[i] != '>' && line[i] != '<' && line[i])
                    {
                        path = (char*)realloc(path, ft_strlen2(path) + 1);
                        path = str_add_to_end(path, line[i]); 
                        i++;
                    }
                    path = try_find(path, (*all)->my_env);
                    old = list->argv[m];
                    if (!list->argv[m])
                        list->argv[m] = ft_strdup("");
                    list->argv[m] = ft_strjoin(list->argv[m], path);
                    free(old);
                    free(path);
                    path = NULL;
                }
                else
                {
                    list->argv[m] = (char*)realloc(list->argv[m], ft_strlen2(list->argv[m]) + 1);
                    list->argv[m] = str_add_to_end(list->argv[m], line[i++]);
                }
                f = 1;
            }
            if (line[i] == '\"')
                i++;
            m++;
        }
        while (line[i] != ' ' && line[i] && line[i] != '>' &&
                line[i] != '<' && line[i] != '|')
        {
            f = 0;
            if (line[i] == '\'')
            {
                while (line[++(i)] && line[i] != '\'')
                {
                    list->argv[m] = (char*)realloc(list->argv[m], ft_strlen2(list->argv[m]) + 1);
                    list->argv[m] = str_add_to_end(list->argv[m], line[i]);
                }
            }
            else if (line[i] == '\"')
            {
                while (line[++(i)] && line[i] != '\"')
                {
                    list->argv[m] = (char*)realloc(list->argv[m], ft_strlen2(list->argv[m]) + 1);
                    list->argv[m] = str_add_to_end(list->argv[m], line[i]);
                }
            }
            else
            {
                if (line[i] == '$')
                {
                    while (line[++i] != ' ' && line[i] != '\'' && line[i] != '\"'
                        && line[i] != '|' && line[i] != '>' && line[i] != '<' && line[i])
                    {
                        path = (char*)realloc(path, ft_strlen2(path) + 1);
                        path = str_add_to_end(path, line[i]); 
                    }
                    path = try_find(path, (*all)->my_env);
                    old = list->argv[m];
                    if (!list->argv[m])
                        list->argv[m] = ft_strdup("");
                    list->argv[m] = ft_strjoin(list->argv[m], path);
                    free(old);
                    free(path);
                    path = NULL;
                }
                else
                {
                    list->argv[m] = (char*)realloc(list->argv[m], ft_strlen2(list->argv[m]) + 1);
                    list->argv[m] = str_add_to_end(list->argv[m], line[i]);
                    i++;
                }
            }
        }
        if (line[i] == '>' || line[i] == '<' || line[i] == '|')
        {
            if (line[i] == '>')
            {
                list->dir.next = 1;
                i++;
                if (line[i - 1] == '>' && line[i] == '>')
                {
                    list->dir.next = 0;
                    list->dir.d_next = 1;
                    i++;
                }
            }
            if (line[i] == '<')
            {
                list->dir.back = 1;
                i++;
                if (line[i - 1] == '<' && line[i] == '<')
                {
                    list->dir.back = 0;
                    list->dir.d_back = 1;
                    i++;
                }
            }
            if (line[i] == '|')
            {
                m = -1;
                ft_listadd_back(&list, ft_listnew());
                list = ft_listlast(list);
                i++;
                f = 0;
                list->count = count_argv(line, i);
                list->argv = (char**)malloc(sizeof(char*) * list->count);
                make_null(&list->argv, list->count);
            }
            if (line[i] == '>' || line[i] == '<')
            {
                printf("error, too much signs");
                exit (0);
            }
        }
    }
    (*all)->cmd = first;
}*/