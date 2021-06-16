#include "srcs/minishell.h"

int					main(int argc, char const *argv[])
{
	char			str[2000];
	int				l;

	l = read(0, str, 100);
	write(1, str, l);
	return 0;
}