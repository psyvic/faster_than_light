/*
** container.c for container in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Mon Apr 10 19:40:35 2017 AIZPURUA Victor Hugo
** Last update Fri Apr 14 18:17:45 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include<unistd.h>
#include <time.h>
#include "ftl.h"

int              add_container_to_ship(t_ship *ship)
{
  t_container    *container;

  my_putstr("Adding containers...\n");
  container = malloc(sizeof(t_container));
  if (container == NULL)
    {
      my_putstr("The ship exploded while placing containers!\n");
      return (0);
    }
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  ship->container = container;
  my_putstr("The container was added succesfully!\n");
  return (1);
}

void             add_freight_to_container(t_ship *ship, t_freight *freight)
{
  if ((ship->container->first == NULL) && (ship->container->last == NULL))
    {
      ship->container->first = freight;
      ship->container->last = freight;
      freight->next = NULL;
    }
  else
    {
      freight->next = ship->container->first;
      ship->container->first->prev = freight;
      ship->container->first = freight;
    }
  freight->prev = NULL;
  ship->container->nb_elem = ship->container->nb_elem + 1;
}

void             del_freight_to_container(t_ship *ship, t_freight *freight)
{
  if ((ship->container->first != NULL) && (ship->container->last != NULL))
    {
      del_prob(ship, freight);
      free(freight);
      ship->container->nb_elem = ship->container->nb_elem - 1;
    }
}

void             get_bonus(t_ship *ship)
{
  t_freight      *temp;

  my_putstr("Applying bonuses from remnants\n");
  temp = ship->container->first;
  while (temp != NULL)
    {
      if (my_strcmp(temp->item, "attackbonus") == 0)
	  ship->weapon->damage = ship->weapon->damage + 5;
      else if (my_strcmp(temp->item, "evadebonus") == 0)
	  ship->navigation_tools->evade = ship->navigation_tools->evade + 3;
      else if (my_strcmp(temp->item, "energy") == 0)
	  ship->ftl_drive->energy = ship->ftl_drive->energy + 1;
      del_freight_to_container(ship, temp);
      temp = temp->next;
    }
  my_putstr("Now you have:\nAttack:");
  my_put_nbr(ship->weapon->damage);
  my_putstr("\nEvade:");
  my_put_nbr(ship->navigation_tools->evade);
  my_putstr("\nEnergy:");
  my_put_nbr(ship->ftl_drive->energy);
  my_putstr("\n");
}
