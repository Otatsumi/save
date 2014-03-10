/*
** get_next_line.h for  in /home/bauwen_j/rendu/psu/PSU_2013_minishell1
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Sun Jan 26 14:15:06 2014 bauwen_j
** Last update Sun Jan 26 14:15:06 2014 bauwen_j
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define        SIZE_READ       (1000)

typedef struct s_list
{
  char  **path;
  char  **envp;
  char  *home;
  char  *pwd;
}               t_list;

typedef struct	s_multi
{
  char **data;

  struct s_multi *next;
  struct s_multi *prev;
}		t_multi;

void	my_put(char *str);
void	my_execve(char *chemin, char **com, char **env);
void    my_cd(char **com, char *home);
void    my_putenv(char **env);
void	my_gere_dir(char *str, t_list *data);

int     check_builtins(char **com, t_list *data);
int     my_strlen(char *str);
int     my_match(char *search, char **tab);
int	check_adv_fct(char *com, t_list *data);

char   	*my_access(char **com, char **path);
char	*get_next_line(const int fd);
char    *the_home(char **env);
char    **sous_env(char **com, t_list *data);
char    **my_sort_wordtab(char *str, char c);
char    **add_env(char **com, t_list *data);
char    **the_path(char **env);

t_list	the_data(char **env);
t_multi	*double_list(char **tab);

#endif /* !GET_NEXT_LINE_H_ */
