/*
** my_ftl.c for my_ftl in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Mon Apr 10 10:45:31 2017 AIZPURUA Victor Hugo
** Last update Fri Apr 14 19:01:29 2017 AIZPURUA Victor Hugo
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "ftl.h"

int     main()
{
  t_ship *ship;
  t_matrix *matrix;

  srand (time (NULL));
  my_putstr("\033[H\033[2J");
  spaceship();
  sleep(3);
  matrix = create_matrix();
  ship = create_ship(matrix);
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  sleep(4);
  while ((matrix->ship->hull > 0 && matrix->ship->ftl_drive->energy > 0) ||
	 matrix->ship->navigation_tools->sector < 10 || matrix->quit != 1)
    {
      my_putstr("\033[H\033[2J");
      spaceship();
      system_command(matrix);
      sleep(2);
    }
  the_end();
  return (0);
}
