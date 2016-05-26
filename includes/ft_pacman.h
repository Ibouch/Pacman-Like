/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pacman.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:56:09 by ibouchla          #+#    #+#             */
/*   Updated: 2016/05/26 21:51:11 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PACMAN_H
# define FT_PACMAN_H
# include <libft.h>
# include <term.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>

# define TIMEOUT 1
# define LOST_HP 1
# define LEVEL_UP 2
# define GAME_OVER 3
# define NB_GHOSTS 4
# define IS_LEVEL ((buf[0] > '0' && buf[0] <= max_level) && buf[1] == '\0')
# define ESC (buf[0] == 27 && buf[1] == '\0')

typedef struct termios	t_termios;

struct					s_key_event
{
	char				name[5];
	int					new_x;
	int					new_y;
};

struct					s_ghost_pos
{
	int					x[NB_GHOSTS];
	int					y[NB_GHOSTS];
	int					init_x[NB_GHOSTS];
	int					init_y[NB_GHOSTS];
	char				old_char[NB_GHOSTS];
};
struct					s_pacman_pos
{
	int					x;
	int					y;
	int					p1_pos;
};

typedef struct			s_map
{
	char				*file;
	char				*content;
	char				**map;
	struct s_key_event	ev;
	struct s_ghost_pos	ghost;
	struct s_pacman_pos	pacman;
	int					nb_char;
	int					nb_line;
	int					total_piece;
	int					piece;
	int					hp;
	int					score;
	int					level;
	struct s_map		*next;
}						t_map;

typedef struct			s_env
{
	t_termios			term_update;
	t_termios			term_default;
	t_map				*m;
	t_bool				solid;
	t_bool				fast;
	int					nb_files;
}						t_env;

int						myputc(int c);
void					map_lstdel(t_map **alst);
void					get_terminfo(t_env *e);
void					error_call_system(char *s);
void					restore_term_default(t_termios *term_default);
void					storage_map(t_env *e, char *path);
void					get_dir_elem(t_env *e, DIR *directory, char *path);
void					map_add(t_map **alst, char *map, char *file_name);
void					run_pacman(t_env *e);
int						select_level(t_env *e);
int						verify_map(char *map);
int						create_map(t_env *e, t_map *m);
int						play_game(t_map *m, t_bool fast, int *i_time);
int						check_time(int *i_time);
void					print_map(t_map *m, t_bool s_opt);
int						move_pacman(t_map *m, int x, int y);
int						ghosts_ai(t_map *m);
int						move_ghosts(t_map *m, int x, int y, int i);
void					update_score(t_map *m, char c);
int						get_map_size(char *map, int type);
int						calcul_pos(int nb_line, int obj);
void					update_struct(struct termios *term, int vmin);
void					storage_position(t_map *m);

#endif
