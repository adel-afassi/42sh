/*
** file.h for 42sh in /home/jeremy/Delivery/PSU_2016_42sh/include/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Jan 17 05:04:06 2017 Jérémy Sid Idris
** Last update Tue Jan 17 05:04:06 2017 Jérémy Sid Idris
*/

#ifndef FILE_H_
# define FILE_H_

int	check_file_exist(char *path);
int	can_exec_file(char *path);
int	can_open_dir(char *path);

#endif /* !FILE_H_ */
