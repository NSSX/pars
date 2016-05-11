#include "libft.h"
#include "get_next_line.h"
 #include <fcntl.h>

char    *file(char *argv)
{
  char    *line;
  char    *yt;
  int             fd;
  int             ret;

  fd = 0;
  ret = 0;
  fd = open(argv, O_RDONLY);
  line = (char *)malloc(sizeof(char) * 2);  
  while ((ret = get_next_line(fd, &yt)) && ret != -1)
    {
      ft_putstr("D");
      line = ft_strjoin(line, yt);
      line = ft_strjoin(line, "\n");
    }
  return (line);
}

char *chaine(char *ch)
{
  int i;

  i = 0;
  while(ch[i] != '\0')
    {
      if(ch[i] == '}')
	{
	  ch = ft_strsub(ch, 0, i);
	  return(ch);
	}
      i++;
    }
  return (NULL);
}

void traitement(char *file)
{
  char *here;
  char *here2;
  char *temp;
  int end;

  end = 0;
  if((here = ft_strstr(file,"sphere{\n")) && here != NULL)
    {
      temp = chaine(here);
      here[0] = 'W';
      if(temp == NULL)
	return;
      if((here2 = ft_strstr(temp,"pos(")) && here2 != NULL)
	  ft_putstr(here2);
      if((here2 = ft_strstr(temp,"color(")) && here2 != NULL)
          ft_putstr(here2);
      if((here2 = ft_strstr(temp,"size(")) && here2 != NULL)
          ft_putstr(here2);
      if((here2 = ft_strstr(temp,"rot(")) && here2 != NULL)
          ft_putstr(here2);
      end++;
    }
  if((here = ft_strstr(file,"plane{\n")) && here != NULL)
    {
      temp = chaine(here);
      here[0] = 'W';
      if(temp == NULL)
        return;
      if((here2 = ft_strstr(temp,"pos(")) && here2 != NULL)
	ft_putstr(here2);
      if((here2 = ft_strstr(temp,"color(")) && here2 != NULL)
	ft_putstr(here2);
      if((here2 = ft_strstr(temp,"size(")) && here2 != NULL)
	ft_putstr(here2);
      if((here2 = ft_strstr(temp,"rot(")) && here2 != NULL)
	ft_putstr(here2);
      end++;
    }
  if(end != 0)
    traitement(file);
}

int main(int argc, char **argv)
{
  int             fd;
  char *yt;
  char *file;
  int ret;

  ret = 0;
  file = (char *)malloc(sizeof(char) * 1);
  if(argc != 2)
    {
      ft_putstr("bad arg\n");
      exit(1);
    }
  fd = 0;
  fd = open(argv[1], O_RDONLY);
  while ((ret = get_next_line(fd, &yt)) && ret != -1)
    {
      file = ft_strjoin(file, yt);
      file = ft_strjoin(file, "\n");
    }
  traitement(file);
  return (0);
}
