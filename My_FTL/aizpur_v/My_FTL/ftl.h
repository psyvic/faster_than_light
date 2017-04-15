/*
** ftl.h for ftl in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Mon Apr 10 09:50:30 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 11:01:03 2017 AIZPURUA Victor Hugo
*/

#ifndef                _FTL_H_
#define                _FTL_H_

struct                 s_weapon
{
  char                 *system_state;
  int                  damage;
};
typedef struct         s_weapon t_weapon;

struct                 s_ftl_drive
{
  char                 *system_state;
  int                  energy;
};
typedef struct         s_ftl_drive t_ftl_drive;

struct                 s_navigation_tools
{
  char                 *system_state;
  int                  evade;
  int                  sector;
};
typedef struct         s_navigation_tools t_navigation_tools;

struct                 s_freight
{
  char                 *item;
  struct s_freight     *next;
  struct s_freight     *prev;
};
typedef struct         s_freight t_freight;

struct                 s_container
{
  t_freight            *first;
  t_freight            *last;
  int                  nb_elem;
};
typedef struct         s_container t_container;

struct		       s_ship
{
  int		       hull;
  t_weapon	       *weapon;
  t_ftl_drive          *ftl_drive;
  t_navigation_tools   *navigation_tools;
  t_container          *container;
};
typedef struct	       s_ship t_ship;

struct                 s_repair_command
{
  char                 *ordre;
  void                 (*f)(t_ship *ship);
};
typedef struct         s_repair_command t_repair_command;

struct                 s_alien
{
  int                  life;
  int                  damage;
};
typedef struct         s_alien t_alien;

struct                 s_matrix
{
  t_ship               *ship;
  t_alien              *alien;
  int                  bonus;
  int                  nb_alien;
  int                  temp_life;
  int                  temp_damage;
  int                  quit;
};
typedef struct         s_matrix t_matrix;

struct                 s_demand
{
  char                 *ordre;
  void                 (*f)(t_matrix *matrix);
};
typedef struct         s_demand t_demand;

struct                 s_main
{
  char                 *ordre;
  void                 (*f)(t_ship *ship);
};
typedef struct	       s_main t_main;

void                   my_putchar(char c);
void                   my_putstr(char *str);
void                   my_putstr_color(const char *color, const char *str);
int                    my_strcmp(char *s1, char *s2);
void                   my_put_nbr(int n);
char                   *my_strdup(const char *str);
char                   *readline(void);
t_ship                 *create_ship(t_matrix *matrix);
int                    add_weapon_to_ship(t_ship *ship);
int                    add_navigation_tools_to_ship(t_ship *ship);
int                    add_ftl_drive_to_ship(t_ship *ship);
int                    add_container_to_ship(t_ship *ship);
void                   add_freight_to_container(t_ship *ship,
						t_freight *freight);
void                   del_freight_to_container(t_ship *ship,
						t_freight *freight);
void                   del_prob(t_ship *ship, t_freight *freight);
void                   get_bonus(t_ship *ship);
void                   ftl_drive_system_check(t_ship *ship);
void                   navigation_tools_system_check(t_ship *ship);
void                   weapon_system_check(t_ship *ship);
void                   system_control(t_ship *ship);
void                   ftl_drive_system_repair(t_ship *t_ship);
void                   navigation_tools_system_repair(t_ship *t_ship);
void                   weapon_system_repair(t_ship *t_ship);
void                   system_repair(t_ship *t_ship);
t_matrix               *create_matrix();
t_freight              *create_freight();
t_alien                *create_alien(t_matrix *matrix);
void                   check_stats(t_matrix *matrix);
void                   system_command(t_matrix *matrix);
void                   check_systems(t_matrix *matrix);
void                   system_repair_main(t_matrix *matrix);
void                   get_bonus_main(t_matrix *matrix);
void                   jump(t_matrix *matrix);
void                   detect(t_matrix *matrix);
void                   attack(t_matrix *matrix);
int                    random_number();
int                    random_number_three();
void                   delete_alien(t_matrix *matrix);
void                   system_break(t_matrix *matrix);
void                   endgame(t_matrix *matrix);
void                   the_end();
void                   finish(t_matrix *matrix);
void                   spaceship();
void                   help();
void                   interface(t_matrix *matrix);
void                   monsterface(t_matrix *matrix);
void                   monster_stats(t_matrix *matrix);
void                   stats(t_matrix *matrix);
void                   stats_two(t_matrix *matrix);
void                   sector(t_matrix *matrix);
void                   hyperspace();
int                    hyper(int i);
int                    space(int i);
void                   del_prob(t_ship *ship, t_freight *freight);
void	               prob_alien(t_matrix *matrix, t_alien *alien);
void                   random_break(t_matrix *matrix);
void                   bonus_prob(t_ship *ship, t_freight *temp);
void                   suspense();
void                   matrix_var(t_matrix *matrix);
void                   attack_cont(t_matrix *matrix);
#endif
