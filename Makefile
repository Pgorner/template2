# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgorner <pgorner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:30:26 by fsandel           #+#    #+#              #
#    Updated: 2023/06/22 12:47:15 by pgorner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	template
SRC				=	main.c template.c utils.c header.c
OBJ				=	$(SRC:.c=.o)
CC				=	cc
CFLAGS		=

install:
	@make all
	@make clean
	@cp $(NAME) /Users/${USER}
	@echo "alias template=/Users/${USER}/$(NAME)" >> ~/.zshrc
	@echo "Successfully installed template"

all:	$(NAME)

$(NAME):$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFT)


%.o:%.c
	@$(CC) -o $@ -c $< $(CFLAGS)


clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all


$(LIBFT):
		make -C $(LIBFT_DIR)

libft:	$(LIBFT)

.PHONY: all clean fclean re