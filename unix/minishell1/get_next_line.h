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

t_list	the_data(char **env);
void	my_put(char *str);
char	*get_next_line(const int fd);
char    **my_sort_wordtab(char *str, char c);
int     check_builtins(char **com, t_list *data);
void	my_execve(char *chemin, char **com, char **env);
int     my_strlen(char *str);
int     my_match(char *search, char **tab);
char    **add_env(char **com, t_list *data);
void    my_cd(char **com, char *home);
char    **the_path(char **env);
char    *the_home(char **env);

#endif /* !GET_NEXT_LINE_H_ */
