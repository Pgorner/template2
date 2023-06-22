# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:30:26 by fsandel           #+#    #+#              #
#    Updated: 2023/06/22 15:25:25 by pgorner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	template
SRC				=	main.c template.c utils.c header.c
OBJ				=	$(SRC:.c=.o)
CC				=	cc

all:	$(NAME)

install:
	@make all
	@make clean
	@cp $(NAME) /Users/${USER}
	@if ! grep -q "template" ~/.zshrc; then \
  		echo "alias template=/Users/${USER}/$(NAME)" >> ~/.zshrc; \
		echo "Added template to /.zshrc"; \
	else \
		echo "Template already in /.zshrc"; \
	fi
	@echo "Successfully installed template"



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