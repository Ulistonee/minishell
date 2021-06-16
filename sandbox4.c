#include "srcs/minishell.h"

int					main(int argc, char const *argv[], char const *envp[]) {
	char str[2000];
	int l;
	struct termios term;
	char *term_name = "xterm-256color";

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, term_name);
	char *str_2 = tgetstr("kr", 0);
	do {
		l = read(0, str, 100);
		write(1, str, l);
	} while (strcmp(str, "\n"));
	write(1, "\n", 1);
	return 0;
}