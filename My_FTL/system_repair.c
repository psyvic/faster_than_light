/*
** system_repair.c for system_repair in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Tue Apr 11 12:27:12 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 11:29:45 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "ftl.h"

void         ftl_drive_system_repair(t_ship *ship)
{
  my_putstr("\033[33mReparing reactor");
  suspense();
  free(ship->ftl_drive->system_state);
  if ((ship->ftl_drive->system_state = my_strdup("online")))
    my_putstr("\033[34mThe reactor has been repaired!\n");
  else
    my_putstr("\033[31mReactor reparations failed!\n");
}

void         navigation_tools_system_repair(t_ship *ship)
{
  my_putstr("\033[33mReparing navigation tools");
  suspense();
  free(ship->navigation_tools->system_state);
  if ((ship->navigation_tools->system_state = my_strdup("online")))
    my_putstr("\033[34mThe navigation tools have been repaired!\n");
  else
    my_putstr("\033[31mNavigation tools reparations failed!\n");
}

void         weapon_system_repair(t_ship *ship)
{
  my_putstr("\033[33mReparing weapons system");
  suspense();
  free(ship->weapon->system_state);
  if ((ship->weapon->system_state = my_strdup("online")))
    my_putstr("\033[34mThe weapons system has been repaired!\n");
  else
    my_putstr("\033[31mWeapons system reparations failed!\n");
}

static const t_repair_command	g_repair_command[] = {
  {"ftl_drive", &ftl_drive_system_repair},
  {"navigation_tools", &navigation_tools_system_repair},
  {"weapon", &weapon_system_repair},
  {NULL, NULL}
};

void         system_repair(t_ship *ship)
{
  char       *command;
  int        bool;

  bool = 0;
  while (bool == 0)
    {
      my_putstr("Repair_system~> ");
      command = readline();
      if (command == NULL)
	my_putstr("[SYSTEM_FAILURE] Command Reader blocked! \n");
      else if (my_strcmp(command, "exit") == 0)
	bool = 1;
      else
	system_repair_cont(ship, command);
      free(command);
    }
}
/*
void         system_repair_cont(t_ship *ship, char *command)
{
  int        bool;
  int        i;

  i = 0;
  bool = 0;
  while (g_repair_command[i].ordre != NULL)
    {
      if (my_strcmp(command, g_repair_command[i].ordre) == 0)
	{
	  g_repair_command[i].f(ship);
	  bool = 1;
	}
      i = i + 1;
    }
  if (bool == 0)
    my_putstr("[SYSTEM_FAILURE] Unknown command! \n");
    }*/

char         *readline(void)
{
  ssize_t    ret;
  char       *buff;

  if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  free(buff);
  return (NULL);
}
