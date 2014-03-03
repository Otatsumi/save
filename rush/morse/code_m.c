/*
** code_m.c for code_m in /home/bauwen_j/rendu/Rush1
** 
** Made by bauwens
** Login   <bauwen_j@epitech.net>
** 
** Started on  Sun Dec 15 10:00:19 2013 bauwens
** Last update Sun Dec 15 10:07:43 2013 bauwens
*/

#include <stdlib.h>

char	**att_morse2(char **code)
{
  code[23] = "-._._";
  code[24] = "_.-.-._";
  code[25] = "_.-._._";
  code[26] = "_._.-.-";
  code[27] = "-_._._._";
  code[28] = "-.-._._._";
  code[29] = "-.-.-._._";
  code[30] = "-.-.-.-._";
  code[31] = "-.-.-.-.-";
  code[32] = "_.-.-.-.-";
  code[33] = "_._.-.-.-";
  code[34] = "_._._.-.-";
  code[35] = "_._._._.-";
  code[37] = 0;
  return (code);
}

char	**att_morse(char **code)
{
  code[0] = "-._.-._.-._";
  code[1] = "-._";
  code[2] = "_.-.-.-";
  code[3] = "_.-._.-";
  code[4] = "_.-.-";
  code[5] = "-";
  code[6] = "-.-._.-";
  code[7] = "_._.-";
  code[8] = "-.-.-.-";
  code[9] = "-.-";
  code[10] = "-._._._";
  code[11] = "_.-._";
  code[12] = "-._.-.-";
  code[13] = "_._";
  code[14] = "_.-";
  code[15] = "_._._";
  code[16] = "-._._.-";
  code[17] = "_._.-._";
  code[18] = "-._.-";
  code[19] = "-.-.-";
  code[20] = "_";
  code[21] = "-.-._";
  code[22] = "-.-.-._";
  code = att_morse2(code);
  return (code);
}

char	**tab_corres()
{
  char	**code;

  if ((code = malloc(37 * sizeof(char *))) == NULL)
    return (NULL);
  code = att_morse(code);
  return (code);
}
