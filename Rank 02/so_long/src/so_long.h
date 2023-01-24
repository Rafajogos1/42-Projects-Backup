#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>

/* so_long */
void	so_long(char *map);

/* Map verification */
int		sl_check_map(char *file);
int		sl_extension(char *file);

#endif