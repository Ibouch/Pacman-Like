# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 12:21:30 by ibouchla          #+#    #+#              #
#    Updated: 2016/05/13 17:33:42 by ibouchla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_pacman

INC_PATH = -I includes

SRC_PATH = srcs

SRC_NAME =	ft_pacman.c \
			error_call_system.c \
			map_lstdel.c \
			storage_map.c\
			get_dir_elem.c \
			map_add.c \
			run_pacman.c \
			verify_map.c \
			get_map_size.c \
			create_map.c \
			check_time.c \
			play_game.c \
			print_map.c \
			get_terminfo.c \
			myputc.c \
			restore_term_default.c \
			move_pacman.c \
			move_ghosts.c \
			ghosts_ai.c \
			select_level.c \
			update_score.c \
			calcul_pos.c \
			storage_position.c \

CC_FLAGS = clang -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJET = $(SRC:.c=.o)

LD_PATH = -L libft

LD_LIB = -lft

RED = \033[1;31m

BLUE = \033[1;34m

GREEN = \033[0;32m

YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJET)
	@echo "$(BLUE)Compilation of object files in project directory is complete.\n"
	@echo "$(YELLOW)Recompilation of the library in progress.."
	#@make -C libft/ re > /dev/null
	@echo "$(BLUE)Compilation of the library is complete.\n"
	@echo "$(YELLOW)Linkage of object files with the library is in progress.."
	@$(CC_FLAGS) $(OBJET) $(LD_PATH) $(LD_LIB) -ltermcap -o $(NAME)
	@echo "$(BLUE)Linkage is complete."
	#@make -C libft/ fclean
	@echo "$(GREEN)Done."

%.o: %.c
	@$(CC_FLAGS) -c $< $(INC_PATH) -o $@
	@echo "\033[1;32mCompilation of object file from the project source file : $(GREEN)Success"
clean:
	@echo "\n$(RED)Deleting object files of the project"
	@$(RM) $(OBJET)

fclean: clean
	@echo "$(RED)Remove the executable\n"
	@$(RM) $(NAME)

re: fclean all
