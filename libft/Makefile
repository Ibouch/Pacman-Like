# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 12:21:30 by ibouchla          #+#    #+#              #
#    Updated: 2016/04/14 22:29:55 by ibouchla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC_PATH = -I includes

SRC_PATH = srcs

SRC_NAME =	ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_endl.c \
		ft_putnbr_long.c \
		ft_putnbr_fd.c \
		ft_putnbr_long_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_nbrlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_atoi.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstnew.c \
		ft_lstmap.c \
		ft_memswap.c \
		ft_strrev.c \
		ft_biggest_str.c \
		ft_isspace.c \
		ft_strswap.c \
		ft_strsort.c \
		ft_lst_sort.c \
		ft_lstadd_back.c \
		ft_lst_at.c \
		ft_lst_size.c \
		ft_print_lst.c \
		ft_readlink.c \
		ft_error_system.c \
		ft_strcolor_fd.c \
		ft_size_tab.c \
		ft_print_tab.c \
		ft_tabdel.c \
		get_next_line.c

CREATE_LIB = ar rc $(NAME) $(OBJET)

ID_LIB = ranlib $(NAME)

CC_FLAGS = clang -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJET = $(SRC:.c=.o)

RED = \033[1;31m

BLUE = \033[1;34m

GREEN = \033[0;32m

YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJET)
	@echo "$(BLUE)Compilation of object files in libft directory is complete.\n"
	@echo "$(YELLOW)Creation of the library in progress.."
	@$(CREATE_LIB)
	@echo "$(BLUE)Creation of the library is complete.\n"
	@echo "$(YELLOW)Indexing of the library in process.."
	@$(ID_LIB)
	@echo "$(BLUE)Indexing of the library is complete.\n"

%.o: %.c
	@$(CC_FLAGS) -c $< $(INC_PATH) -o $@
	@echo "\033[1;32mCompilation of object file from the library source file : $(GREEN)Success"
clean:
	@echo "\n$(RED)Deleting object files of the library"
	@$(RM) $(OBJET)

fclean: clean
	@echo "$(RED)Remove the library\n"
	@$(RM) $(NAME)

re: fclean all
