/*
** game_4.c for game_4 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Apr 14 11:50:47 2017 AIZPURUA Victor Hugo
** Last update Fri Apr 14 14:10:37 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include "ftl.h"
#include <time.h>

void   exit_game(t_matrix *matrix)
{
  my_putstr("Exiting game\n");
  matrix->quit = 1;
}
void   the_end()
{
  my_putstr("Thank you for playing!\n");
}
