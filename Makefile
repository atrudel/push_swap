# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 16:02:38 by atrudel           #+#    #+#              #
#    Updated: 2017/04/28 13:33:40 by atrudel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIB_PATH = libft

SRC = 	parsing.c \
		stack_building.c \
		stack_manipulation.c \
		stack_info.c \
		stack_iter.c \
		stack_iter2.c \
		display.c \
		instructions_1.c \
		instructions_2.c \
		instructions_3.c \
		lst_moves.c \
		lst_trimming.c \
		general_sort.c \
		bubble_sort.c \
		quicksort.c \
		median.c

OBJ = $(SRC:.c=.o)

INC = 	push_swap.h \
		visualizer.h \
		$(LIB_PATH)/includes/libft.h

FLAGS = -Wall -Wextra -Werror

all: checker push_swap visualizer

checker : checker.o $(OBJ) $(LIB_PATH)/libft.a
	gcc -o checker checker.o $(OBJ) $(FLAGS) -L $(LIB_PATH) -lft

push_swap : push_swap.o $(OBJ) $(LIB_PATH)/libft.a
	gcc -o push_swap push_swap.o $(OBJ) $(FLAGS) -L $(LIB_PATH) -lft

visualizer: visualizer.o visualizer2.o $(OBJ) $(LIB_PATH)/libft.a
	gcc -o visualizer visualizer.o visualizer2.o $(OBJ) $(FLAGS) -lmlx -framework OpenGL \
	-framework AppKit -L $(LIB_PATH) -lft

$(LIB_PATH)/libft.a: $(LIB_PATH)/Makefile $(LIB_PATH)/includes/libft.h
	@make -C $(LIB_PATH)/ fclean && make -C $(LIB_PATH)
	@echo "libft created"

%.o: %.c $(INC)
	gcc -o $@ -c $< $(FLAGS) -I $(LIB_PATH)/includes

clean:
	make -C $(LIB_PATH)/ clean
	rm -f $(OBJ) checker.o push_swap.o visualizer.o visualizer2.o

fclean: clean
	make -C $(LIB_PATH)/ fclean
	rm -f checker push_swap visualizer

re: fclean all

norme:
	@make -C $(LIB_PATH)/ norme
	@echo ======================[Norminette]=[Push_swap]========================
	@norminette $(SRC) checker.c push_swap.c visualizer.c visualizer2.c $(INC)
