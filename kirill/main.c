#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "minishell.h"
#include "term.h"
#include "libft/libft.h"

int move_probels(char *line, int i)
{
    while (line[i] == ' ')
    {
        i++;
    }
    return (i);
}

void wait_signal(int sign)
{
    if (sign == SIGINT)
    {
        write(1, "\n", 1);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}

void ctrl_D()
{
    printf("\033[A");
    printf("bash-3.2$ exit\n");
    exit(0);
}

char **copy_env(char **env)
{
    char **dst;
    int  n;

    dst = NULL;
    n = 0;
    while(env[n])
        n++;
    dst = (char**)malloc(sizeof(char*) * (n + 1));
    n = 0;
    while(env[n])
    {
        dst[n] = ft_strdup(env[n]);
        n++;
    }
    dst[n] = NULL;
    return (dst);
}

void         check_fd()
{
    int     fd;

    fd = dup(0);
    printf("leaked fd - %d\n", fd);
    close(fd);
}


int main(int argc, char const *argv[], char *env[])
{
    char *line;
    struct termios term;
    t_cmd *list;
    t_all *all;

    tcgetattr(0, &term);
    term.c_lflag &= ~(ECHOCTL);
    tcsetattr(0, TCSANOW, &term);
    signal(SIGINT, wait_signal);
    all = malloc(sizeof(t_all));
    all->my_env = copy_env(env);
    //parse_line("cat > 1 vwqc << 123 >", &all);
   // output_all(all);
   // free_all(&all);
    line = readline("bash-3.2$ ");
    if (!line)
        ctrl_D();
    add_history(line);
    all = malloc(sizeof(t_all));
    all->exit_code = 0;
    all->my_env = copy_env(env);

    parse_line(line, &all);
    output_all(all);
    executor(&all);
    free_all(&all);
    while (1) // исправить функцию на свою
    {
        line = readline("bash-3.2$ ");
        if (!line) {
            ctrl_D();
        }
        add_history(line);
        parse_line(line, &all);
        output_all(all);
        executor(&all);
        free_all(&all);
    }
    return (0);
}




















/*#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <term.h>

int putint(int c)
{
    c = (unsigned char)c;
    return (write(1, &c, 1));
}

int main(int argc, char const *argv[])
{
    char str[2000];
    char *term_name = "xterm-256color";
    int l;
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ECHO);
    term.c_lflag &= ~(ICANON);
    tgetent(0, term_name);
    char *ks = tgetstr("ks", NULL);
    tputs(ks, 1, &putint);
    char *ke = tgetstr("ke", NULL);
    tputs(ke, 1, &putint);
    char *up = tgetstr("ku", 0);
    char *down = tgetstr("kd", 0);
    tcsetattr(0, TCSANOW, &term);
    do{
        l = read(0, str, 100);
        if (!strcmp(up, str))
            printf("previous\n");
        else if (!strcmp(down, str))
            printf("next\n");
        else
            write(1, str, l);
    }  while (strcmp(str, "\n"));
    write(1, "\n", 1);

    return (0);
}*/