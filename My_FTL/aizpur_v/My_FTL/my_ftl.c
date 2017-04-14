/*
** my_ftl.c for my_ftl in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Mon Apr 10 10:45:31 2017 AIZPURUA Victor Hugo
** Last update Fri Apr 14 09:07:48 2017 AIZPURUA Victor Hugo
*/

#include "ftl.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int     main()
{
  t_ship *ship;
  t_matrix *matrix;

  srand (time (NULL));
  /*
    t_freight *freight;
    t_freight *freight2;
    t_freight *freight3;
    t_freight *freight4;

  
    freight = malloc(sizeof(t_freight));
    freight->item = my_strdup("energy");

  

    freight2 = malloc(sizeof(t_freight));
    freight2->item = my_strdup("attackbonus");

 

    freight3 = malloc(sizeof(t_freight));
    freight3->item = my_strdup("evadebonus");

    freight4 = malloc(sizeof(t_freight));
    freight4->item = my_strdup("energy");
  */
  matrix = create_matrix();
  ship = create_ship(matrix);
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  create_alien(matrix);
  /*  add_freight_to_container(ship, freight);
      add_freight_to_container(ship, freight2);
      add_freight_to_container(ship, freight3);
      add_freight_to_container(ship, freight4);
      del_freight_to_container(ship, freight);
      get_bonus(ship);
      system_control(ship);
      ftl_drive_system_repair(ship);
      navigation_tools_system_repair(ship);
      weapon_system_repair(ship);
      system_repair(ship);*/
  system_command(matrix);
  return (0);
}
