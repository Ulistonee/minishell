#include "minishell.h"

int main() {
	char *term_type = "xterm-256color";

	printf("Hello, World!\n");
	tgetent(0, term_type);
	printf("%s\n", term_type);
	return 0;
}
