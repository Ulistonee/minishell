#include "minishell.h"

static void	parse_dollar2(char **dollar, t_all **all, char **old, char **new)
{
	*dollar = try_find(*dollar, (*all)->my_env);
	*old = *new;
	if (!*new)
		*new = ft_strdup("");
	*new = ft_strjoin(*new, *dollar);
	free(*old);
	free(*dollar);
	*dollar = NULL;
	*old = NULL;
}

static void	parse_dollar0(char **dollar, char *line, int *i)
{
	while (ft_isalnum(line[*i]) || line[*i] == '_')
	{
		(*dollar) = ft_realloc(*dollar, ft_strlen2(*dollar) + 2);
		*dollar = str_add_to_end(*dollar, line[*i]);
		(*i)++;
	}
}

static void	dollar_init(int *i, char **dollar, char **new, char **old)
{
	*i = -1;
	*dollar = NULL;
	*old = NULL;
	*new = NULL;
}

char	*parse_dollar(char *line, t_all **all)
{
	char	*dollar;
	char	*new;
	char	*old;
	int		i;

	dollar_init(&i, &dollar, &new, &old);
	while (line[++i])
	{
		if (line[i] == '$')
		{
			i++;
			parse_dollar0(&dollar, line, &i);
			parse_dollar2(&dollar, all, &old, &new);
		}
		else
		{
			new = ft_realloc(new, ft_strlen2(new) + 2);
			new = str_add_to_end(new, line[i]);
		}
	}
	free(line);
	return (new);
}
