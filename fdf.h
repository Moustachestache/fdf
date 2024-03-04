/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:21:43 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/08 17:31:31 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "srcs/mlx/mlx.h"
# include "srcs/mlx/mlx_int.h"
# include "srcs/lib/libft.h"
# include <math.h>

# define WIN_WIDTH 2000
# define WIN_HEIGHT 1200
# define WIN_TITLE "FDF:  "
# define PADDING 5

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_keyhooks {
	int		keycode;
	void	*action;
}					t_keyhooks;

typedef struct s_points {
	int		x0;
	int		y0;
	int		z0;
	int		x1;
	int		y1;
	int		z1;
	int		color;
}					t_points;

typedef struct s_node {
	int		z;
	int		argb;
}					t_node;

typedef struct s_params {
	int		colour;
	int		valw;
	int		valz;
	int		xoffset;
	int		yoffset;
	int		*hex;
	float	valiso;
	char	*title;
}					t_params;

typedef struct s_map {
	int		fd;
	int		height;
	int		width;
	char	*mapname;
	t_node	**coord;
}					t_map;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_image		img;
	t_map		*map;
	t_params	*params;
}					t_vars;

int			key_hook(int keycode, t_vars *vars);
int			ft_isspace(char c);
int			window_button(t_vars *vars);
int			ft_lentochar(char *str, char c);
int			ft_filext(char *str, char *ext);
int			ft_countnodes(char *str, char nodeid);
int			mouse_hook(int button, int x, int y, t_vars *vars);
int			ft_hextoint(char *str, t_vars *vars);
int			ft_ishexa(char *str);
int			ft_exit(int exit_value, t_vars *vars);
char		*ft_nextnode(char *buffer, char nodeid);
char		*ft_buffer(int fd, char c);
void		ft_getmap(t_map *map, t_vars *vars);
void		ft_free_all(t_vars *vars, int code);
void		ft_display(t_vars *vars);
void		ft_centered(t_vars *vars, int x, int y, char *text);
void		ft_drawline(t_points points, t_vars *vars);
void		ft_init_m(t_vars *vars);
void		ft_meluche(t_vars *vars);
void		ft_putstars(t_vars *vars, int density);
void		ft_pipou(t_vars *vars);
void		ft_konami(int keycode, t_vars *vars);
void		ft_drawfdf(t_vars *vars);
void		ft_gethex(char *buffer, int hexnode);
void		ft_create_image(t_vars *vars);
void		img_pix_put(t_image img, int x, int y, int color);
t_node		*ft_createline(char *newline, t_map *map);
t_map		*ft_init_map(char *av[], t_vars *vars);
t_points	ft_setpts(int x0, int y0, int x1, int y1);
t_params	*ft_init_params(char *av[], t_vars *vars);
#endif
