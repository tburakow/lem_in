LEM_IN_FILES = initializer.c load_room.c read_input.c \
main.c load_edges.c get_ants.c new_queue.c \
que_traverse.c pathfinder.c router.c sort_router.c count_cost.c \
que_from_path.c gen_output.c cleanup.c printout.c \
reset_ants.c error.c load_edges_two.c

LEM_IN_SRC_DIR = ./srcs/
LEM_IN_SRC := $(addprefix $(LEM_IN_SRC_DIR),$(LEM_IN_FILES))
LEM_IN_OBJ := $(LEM_IN_FILES:.c=.o)
NAME = lem-in
LIB_NAME = ./libft/libft.a
LIB_DIR = ./libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

re : fclean all

$(NAME) : $(LEM_IN_OBJ) $(LIB_NAME)
	gcc $(CFLAGS) -o $(NAME) -L$(LIB_DIR) $(LEM_IN_OBJ) -lft

$(LEM_IN_OBJ) : $(LEM_IN_SRC)
	gcc $(CFLAGS) -c -I. $(LEM_IN_SRC)

$(LIB_NAME) :
	make -C libft

clean :
	rm -f $(LEM_IN_OBJ)
	make clean -C libft/

fclean : clean
	rm -f ./$(NAME)
	make fclean -C libft/