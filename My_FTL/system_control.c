/*
** system_control.c for system_control in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Tue Apr 11 11:27:05 2017 AIZPURUA Victor Hugo
** Last update Fri Apr 14 09:32:14 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include "ftl.h"
#include <time.h>

void ftl_drive_system_check(t_ship *ship)
{
  my_putstr("Veryfying reactor...\n");
  if (ship->ftl_drive->system_state != NULL)
    my_putstr("Reactor OK BI ATCH...\n");
  else
    my_putstr("The reactor is fucked up...\n");
}

void navigation_tools_system_check(t_ship *ship)
{
  my_putstr("Veryfying navigation tools...\n");
  if (ship->navigation_tools->system_state != NULL)
    my_putstr("Navigation tools OK BI ATCH...\n");
  else
    my_putstr("The navigation system is fucked up...\n");  
}

void weapon_system_check(t_ship *ship)
{
  my_putstr("Veryfying weapons system...\n");
  if (ship->weapon->system_state != NULL)
    my_putstr("Weapons system OK BI ATCH...\n");
  else
    my_putstr("The weapons system is fucked up...\n");
}


void system_control(t_ship *ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
}