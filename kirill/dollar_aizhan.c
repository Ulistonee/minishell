#include "minishell.h"

char *parse_dollar(char *line, t_all **all)
{
	char *dollar;
	char *new;
	char *old;
	int i;

	i = -1;
	dollar = NULL;
	old = NULL;
	new = NULL;
	while(line[++i])
	{
		if (line[i] == '$') {
		    i++;
			while (ft_isalnum(line[i]) || line[i] == '_') {
				dollar = ft_realloc(dollar, ft_strlen2(dollar) + 2);
				dollar = str_add_to_end(dollar, line[i]);
				i++;
			}
			dollar = try_find(dollar, (*all)->my_env);
			old = new;
			if (!new)
				new = ft_strdup("");
			new = ft_strjoin(new, dollar);
			free(old);
			free(dollar);
			dollar = NULL;
			old = NULL;
		} else {
			new = ft_realloc(new, ft_strlen2(new) + 2);
			new = str_add_to_end(new, line[i]);
		}
	}
	free(line);
	return (new);
}