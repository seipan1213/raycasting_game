/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:58:29 by sehattor          #+#    #+#             */
/*   Updated: 2021/03/02 14:58:29 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <float.h>
# include "../minilibx-linux/mlx.h"

# define ABS(x) (0 < (x) ? (x) : -(x))
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) < (b) ? (b) : (a))
# define FALSE 0
# define TRUE 1
# define SPACE " \t\n\v\f\r"
# define MAPCHAR " 012NSWE"

# define BMP_FILEHEADER_SIZE 14
# define BMP_INFHEADER_SIZE 40
# define BMP_BPP 4
# define BMP_PLANES 1

# define MOVESPEED 0.04
# define ROTSPEED  0.02
# define WALLDIST  0.2

# define KEY_CODE_W     119
# define KEY_CODE_A      97
# define KEY_CODE_S     115
# define KEY_CODE_D     100
# define KEY_CODE_LA  65361
# define KEY_CODE_RA  65363
# define KEY_CODE_DA  65364
# define KEY_CODE_UA  65362
# define KEY_CODE_ESC 65307

# define X_E_P 2
# define X_E_R 3
# define X_E_E 33
# define X_M_P 0x1
# define X_M_R 0x2
# define X_M_E 0x20000

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		llen;
	int		endian;
}				t_img;

typedef struct	s_player
{
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	movespeed_fb;
	double	movespeed_rl;
	double	rotspeed;
}				t_player;

typedef struct	s_dpair
{
	double	first;
	double	second;
}				t_dpair;

typedef struct	s_ipair
{
	int	first;
	int	second;
}				t_ipair;

typedef struct	s_drawline
{
	t_dpair	transform;
	int		spritescreenx;
	int		spriteheight;
	int		drawstarty;
	int		drawendy;
}				t_drawline;

typedef struct	s_god
{
	char		*cub_name;
	int			window_width;
	int			window_height;
	char		**map;
	int			map_w;
	int			map_h;
	t_list		*map_list;
	size_t		floor_color;
	size_t		ceil_color;
	t_img		*ch_img;
	t_img		w_img;
	t_img		no_img;
	t_img		so_img;
	t_img		ea_img;
	t_img		we_img;
	t_img		s_img;
	char		*err_msg;
	void		*mlx;
	void		*win;
	t_player	pl;
	int			scr_w;
	int			scr_h;
	double		planex;
	double		planey;
	double		raydirx;
	double		raydiry;
	int			side;
	double		perpwalldist;
	t_ipair		mapxy;
	t_dpair		ddist;
	t_ipair		stepxy;
	t_dpair		sdist;
	double		wallx;
	int			exit;
	int			bmp;
	size_t		i_zero_color;
}				t_god;

void			my_mlx_pixel_put(t_god *g, int x, int y, int color);
size_t			create_color(int t, int r, int g, int b);
size_t			pic_color(t_img img, int i, int j);
t_ipair			*make_ipair(int i, int j);

void			paint_cf(t_god *g);
void			wall_verline(t_god *g, int x);
t_img			*choice_tex(t_god *g);
t_dpair			convert_trans(t_god *g, int i, int j);

void			put_sprite(t_god *g, int x, int *ymask, t_drawline dl);
void			make_sprite(t_god *g, int x, int *ymask, t_ipair *s_pos);
void			sprite_verline(t_god *g, int x, int *mx);

void			ray_hitsp(t_god *g, int *mx);
void			ray_dist_step(t_god *g);
void			ray_calc(t_god *g, int x);
void			raycast(t_god *g);

void			set_pl(t_god *g, int i, int j);
void			playermove(t_god *g);
int				update(t_god *g);

void			set_err(t_god *g, char *str);
void			destory_g(t_god *g);
void			exit_g(t_god *g);

void			littleendian(unsigned char *s, unsigned int n, int size);
void			write_header(t_god *g, int fd);
void			write_body(t_god *g, int fd);
void			write_bmp(t_god *g);

void			get_img(void *mlx, char *path, t_img *img);
int				read_num(int *i, char **str);
void			read_r(t_god *g, char *str);
void			read_cf(t_god *g, char *str);
void			read_img(t_god *g, t_img *img, char *str);

void			bfs_clear(t_god *g, int **map, t_list **lst, int error);
void			map_bfs(t_god *g, int **map, t_ipair p);
void			map_isclose(t_god *g, t_ipair p);
void			check_map(t_god *g);
void			make_map(t_god *g);

void			analyze_line(t_god *g, char *line);
void			analyze_map(t_god *g, char *line);
int				is_map(char *str);
void			check_file(t_god *g, int fd);
void			load_file(t_god *g, int argc, char **argv);

void			init_god(t_god *g);
int				keypress_hook(int keycode, t_god *g);
int				exit_hook(t_god *g);
int				keyrelease_hook(int keycode, t_god *g);
int				main(int argc, char **argv);

#endif