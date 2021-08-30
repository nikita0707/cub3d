/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:12:00 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 16:50:46 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define EPS 0.00001f
# define FOV 66.0f
# define LIGHT 0
# define MUSIC 1

# ifndef BONUS
#  define BONUS 0
# endif

# ifdef LINUX
#  include "mlxl.h"
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define LARROW 65361
#  define RARROW 65363
#  define SHIFT 65505
#  define P 112
#  define SPACE 32
#  define CTRL 65507
#  define F 102
# else
#  include "mlxm.h"
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define LARROW 123
#  define RARROW 124
#  define SHIFT 57
#  define P 35
#  define SPACE 49
#  define CTRL 256
#  define F 3
# endif

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include <math.h>
# include <pthread.h>
# include <signal.h>

typedef unsigned int	t_uint;

typedef struct		s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				la;
	int				ra;
}					t_keys;

typedef struct		s_point
{
	float			x;
	float			y;
}					t_point;

typedef struct		s_player
{
	float			dir;
	t_point			pos;
}					t_player;

typedef struct		s_texture
{
	int				height;
	int				width;
	char			*data;
	void			*image;
}					t_texture;

typedef struct		s_asprite
{
	int				count;
	int				tf;
	t_texture		*tex;
}					t_asprite;

typedef struct		s_cub
{
	int				e;
	int				mx;
	int				my;
	int				lp;
	int				tp;
	int				pts;
	int				bpp;
	int				sit;
	int				pid;
	int				jump;
	int				focus;
	int				mhide;
	int				action;
	int				vision;
	int				*sides;
	int				s_width;
	int				s_height;
	int				sp_count;
	int				map_size;
	int				config_fd;
	char			**map;
	char			*musicid;
	void			*mlx_ptr;
	void			*win_ptr;
	float			*hits;
	float			speed;
	float			*dists;
	t_keys			keys;
	t_point			*th;
	t_point			*prtls;
	t_point			*sprites;
	t_player		player;
	t_asprite		r_tex;
	t_asprite		a_tex;
	t_texture		hand;
	t_texture		s_tex;
	t_texture		skybox;
	t_texture		screen;
	t_texture		no_tex;
	t_texture		so_tex;
	t_texture		we_tex;
	t_texture		ea_tex;
	t_texture		hp_tex;
	t_texture		fl_tex;
	t_texture		pnt_tex;
	t_texture		lantern;
	t_texture		fireball;
	t_texture		cdoor_tex;
	t_texture		odoor_tex;
	t_texture		*port_tex;
	pthread_t		thr;
	unsigned int	f_color;
	unsigned int	c_color;
}					t_cub;

int					fi(t_cub *cub);
int					fo(t_cub *cub);
int					loop(t_cub *cub);
int					exita(t_cub *cub);
int					draw_all(t_cub *cub);
int					up(int q, t_cub *cub);
int					setup_conf(t_cub *cub);
int					valid_color(char *str);
int					check_map(t_cub *cub);
int					parse_map(t_cub *cub);
int					down(int q, t_cub *cub);
int					scr_sh(t_cub *cub, int cr);
int					check_all_conf(t_cub *cub);
int					contains_all_conf(t_cub *cub);
int					valid_space(t_cub *cub, int i, int j);
int					parse_line(t_cub *cub, int fd, char **line);
int					hit_the_wall(t_cub *cub, t_point pt, int tx);
int					valid_other(t_cub *cub, int i, int j, float dir);
int					parse_tex(t_cub *cub, char *path, t_texture *tex);

char				*sfromc(char c);
char				cfrommap(t_cub *cub, int x, int y);

void				sit(t_cub *cub);
void				jump(t_cub *cub);
void				move(t_cub *cub);
void				set_z(t_cub *cub);
void				clear(t_cub *cub);
void				draw_mm(t_cub *cub);
void				raycast(t_cub *cub);
void				inc_map(t_cub **cub1);
void				draw_hand(t_cub *cub);
void				set_prtls(t_cub *cub);
void				draw_walls(t_cub *cub);
void				open_doors(t_cub *cub);
void				clear_image(t_cub *cub);
void				draw_sprites(t_cub *cub);
void				sort_sprites(t_cub *cub);
void				draw_fireball(t_cub *cub);
void				parse_sprites(t_cub *cub);
void				setup(t_cub *cub, int argc);
void				error_open_file(t_cub *cub);
void				draw_backgroung(t_cub *cub);
void				push(t_cub *cub, int x, int y);
void				add_str(char **line, char *buf);
void				floor_casting(t_cub *cub, int x, int start);
void				draw_floor(t_cub *cub, int x, int mid, int start);
void				draw_ceiling(t_cub *cub, int x, int mid, int end);
void				parse_asprite(t_cub *cub, t_asprite *tex, char *p);
void				my_mlx_pixel_put(t_cub *cub, int x, int y, t_uint color);

float				absf(float f);
float				norm_ray(float ray);

unsigned int		get_color(t_texture tex, int x, int y);
unsigned int		apply_shadow(unsigned int color, float dist);

#endif
