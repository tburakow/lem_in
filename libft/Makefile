SRCS=$(SRCDIR)ft_atoi.c \
$(SRCDIR)ft_bzero.c \
$(SRCDIR)ft_isalnum.c \
$(SRCDIR)ft_isalpha.c \
$(SRCDIR)ft_isascii.c \
$(SRCDIR)ft_isdigit.c \
$(SRCDIR)ft_isprint.c \
$(SRCDIR)ft_itoa.c \
$(SRCDIR)ft_memalloc.c \
$(SRCDIR)ft_memccpy.c \
$(SRCDIR)ft_memchr.c \
$(SRCDIR)ft_memcmp.c \
$(SRCDIR)ft_memcpy.c \
$(SRCDIR)ft_memdel.c \
$(SRCDIR)ft_memmove.c \
$(SRCDIR)ft_memset.c \
$(SRCDIR)ft_putchar_fd.c \
$(SRCDIR)ft_putchar.c \
$(SRCDIR)ft_putendl_fd.c \
$(SRCDIR)ft_putendl.c \
$(SRCDIR)ft_putnbr_fd.c \
$(SRCDIR)ft_putnbr.c \
$(SRCDIR)ft_putstr_fd.c \
$(SRCDIR)ft_putstr.c \
$(SRCDIR)ft_strcat.c \
$(SRCDIR)ft_strchr.c \
$(SRCDIR)ft_strclr.c \
$(SRCDIR)ft_strcmp.c \
$(SRCDIR)ft_strcpy.c \
$(SRCDIR)ft_strdel.c \
$(SRCDIR)ft_strdup.c \
$(SRCDIR)ft_strequ.c \
$(SRCDIR)ft_striteri.c \
$(SRCDIR)ft_striter.c \
$(SRCDIR)ft_strjoin.c \
$(SRCDIR)ft_strlcat.c \
$(SRCDIR)ft_strlen.c \
$(SRCDIR)ft_strmapi.c \
$(SRCDIR)ft_strmap.c \
$(SRCDIR)ft_strncat.c \
$(SRCDIR)ft_strncmp.c \
$(SRCDIR)ft_strncpy.c \
$(SRCDIR)ft_strnequ.c \
$(SRCDIR)ft_strnew.c \
$(SRCDIR)ft_strnstr.c \
$(SRCDIR)ft_strrchr.c \
$(SRCDIR)ft_strsplit.c \
$(SRCDIR)ft_strstr.c \
$(SRCDIR)ft_strsub.c \
$(SRCDIR)ft_strtrim.c \
$(SRCDIR)ft_tolower.c \
$(SRCDIR)ft_toupper.c \
$(SRCDIR)ft_lstadd.c \
$(SRCDIR)ft_lstdel.c \
$(SRCDIR)ft_lstdelone.c \
$(SRCDIR)ft_lstiter.c \
$(SRCDIR)ft_lstmap.c \
$(SRCDIR)ft_lstnew.c \
$(SRCDIR)ft_strpbrk.c \
$(SRCDIR)ft_strsep.c \
$(SRCDIR)ft_strspn.c \
$(SRCDIR)ft_strcspn.c \
$(SRCDIR)ft_strlcpy.c \
$(SRCDIR)ft_intlen.c \
$(SRCDIR)ft_getchar.c \
$(SRCDIR)ft_getnbrs.c \
$(SRCDIR)get_next_line.c \
$(SRCDIR)ft_uintlen.c \
$(SRCDIR)ft_printf.c \
$(SRCDIR)ft_pf_read_specifiers.c \
$(SRCDIR)ft_pf_stages.c \
$(SRCDIR)ft_pf_handle_char.c \
$(SRCDIR)ft_pf_conv_char.c \
$(SRCDIR)ft_pf_pad_with.c \
$(SRCDIR)ft_pf_read_conversion.c \
$(SRCDIR)ft_pf_print.c \
$(SRCDIR)ft_pf_conv_str.c \
$(SRCDIR)ft_pf_handle_str.c \
$(SRCDIR)ft_pf_convert_hexa.c \
$(SRCDIR)ft_pf_handle_ptr.c \
$(SRCDIR)ft_pf_handle_oux.c \
$(SRCDIR)ft_pf_conv_oux.c \
$(SRCDIR)ft_pf_get_uint_len.c \
$(SRCDIR)ft_pf_get_int_len.c \
$(SRCDIR)ft_pf_read_length.c \
$(SRCDIR)ft_pf_check_zeropadding.c \
$(SRCDIR)ft_pf_conv_di.c \
$(SRCDIR)ft_pf_handle_di.c \
$(SRCDIR)ft_pf_skip_leading_zeroes.c \
$(SRCDIR)ft_pf_handle_f.c \
$(SRCDIR)ft_pf_conv_f.c \
$(SRCDIR)ft_pf_round_f_str.c \
$(SRCDIR)ft_pf_get_double_len.c \
$(SRCDIR)ft_pf_need_to_roundup.c \
$(SRCDIR)ft_pf_initializers.c \
$(SRCDIR)ft_pf_mallocfail.c \
$(SRCDIR)ft_dprintf.c \
$(SRCDIR)ft_sprintf.c \
$(SRCDIR)ft_snprintf.c \
$(SRCDIR)ft_pf_writers.c \
$(SRCDIR)ft_atol.c \
$(SRCDIR)ft_atoll.c \
$(SRCDIR)ft_swap.c \
$(SRCDIR)ft_quicksortint.c \
$(SRCDIR)ft_is_in_range.c \
$(SRCDIR)ft_diff.c \
$(SRCDIR)ft_abs.c \
$(SRCDIR)ft_file_split.c \
$(SRCDIR)ft_line_split.c \
$(SRCDIR)ft_file_rows.c \
$(SRCDIR)ft_is_number.c \
$(SRCDIR)ft_is_int.c \
$(SRCDIR)ft_free_str_arr.c \
$(SRCDIR)ft_hash_search.c \
$(SRCDIR)ft_hash_add.c \
$(SRCDIR)ft_hash_key.c \
$(SRCDIR)ft_hash_remove.c \
$(SRCDIR)ft_hash_map.c

OBJECTS := $(SRCS:.c=.o)
SRCDIR=./
CC=gcc
FLAGS=-Wall -Wextra -Werror -g
NAME=libft.a

all : $(NAME)

$(OBJECTS) : $(SRCS)
	gcc $(FLAGS) -I. -c $(SRCS)
$(NAME) : $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

test : re
	$(CC) -L. -I. main.c -lft

