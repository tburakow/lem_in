/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:58:27 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 13:27:15 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define FILE_BUFFER 10000000
# define EDGE_BUFF 40
# define ROOM_BUFFER 100000
# define MAX_WIDTH 100000
# include "./libft/libft.h"

typedef struct s_file
{
	char	*buf;
	char	*free_ptr;
}	t_file;

typedef struct s_pathcomp
{
	size_t	i;
	size_t	j;
}				t_pathcomp;

typedef struct s_edge
{
	struct s_node	*room;
	uint8_t			capacity;
}	t_edge;

typedef struct s_edges
{
	struct s_edge	*edges;
	size_t			slots;
	size_t			used;
}	t_edges;

typedef struct s_node
{
	char	*name;
	uint8_t	type;
	uint8_t	visited;
	t_edges	edges;
}	t_node;

typedef struct s_visit
{
	t_edge			*to_child;
	t_node			*parent;
	t_node			*child;
	struct s_visit	*parent_visit;
}	t_visit;

typedef struct s_que
{
	struct s_visit	*visits;
	size_t			i;
	size_t			amount;
}	t_que;

typedef struct s_map_data
{
	t_node	*nodes;
	size_t	start;
	size_t	end;
	size_t	room_count;
}	t_map_data;

typedef struct s_ant
{
	ssize_t	number;
	t_node	*position;
	ssize_t	progress;
}			t_ant;

typedef struct s_path2
{
	t_node	**nodes;
	size_t	ants;
	t_ant	*ant_dudes;
	size_t	dudecount;
	size_t	used;
	size_t	slots;
}	t_path2;

typedef struct s_router
{
	t_path2	*paths;
	size_t	used;
	size_t	slots;
	size_t	moves;
}	t_router;

typedef struct s_data
{
	ssize_t		ants;
	ssize_t		start;
	ssize_t		end;
	t_file		file;
	t_map_data	map;
	t_router	router;
	size_t		route_count;
	size_t		valid_count;
}t_data;

void		get_ants(char **buf, t_data *data);
void		load_rooms(t_data *data);
void		go_to_next_line(char **buf);
void		load_edges(t_data *data);
ssize_t		read_input(char **buf);
void		initialize_data(t_data *data);
void		initialize_que(t_que *queue);
int			initialize_node(t_node *node);
t_que		get_visits_until_end(t_data *data, int reverse);
int			traverse_que(t_que *que, t_node *start_out);
void		clear_que_visited(t_que *que);
int			find_path(t_node *node_in, t_path2 *path, t_node *end);
void		initialize_path(t_path2 *path);
t_node		*find_closed_edge(t_edges *edges);
t_router	get_router(t_node *start, t_node *end);
void		count_cost_in_moves(t_router *router, ssize_t ants);
void		sort_router(t_router *router);
t_visit		set_start_visit(t_node *node);
t_visit		get_visit(t_edge *to_child, t_node *parent, t_visit *current);
t_que		generate_visits_from_path(t_data *data, t_path2 *path);
void		reroute_paths(t_router *router, t_data *data, int reverse);
void		clear_que(t_que *que);
void		distribute_ants(t_data *data);
void		make_moves(t_router *router);
void		free_router(t_router *router);
void		free_data(t_data *data);
void		free_ants(t_router *router);
void		reset_ants(t_router *router);
void		pathcomp_set(t_pathcomp *comp, size_t i, size_t j, ssize_t max);
void		special_printout(t_data *data);
int			is_end_next_to_start(t_data *data);
void		error_and_exit(char *str, int status);
int			add_node_to_edges(t_edges *from, t_node *to, uint8_t capacity);
int			reallocate_links(t_edges *from);
#endif