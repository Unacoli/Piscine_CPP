# ----------- EXECUTABLE -----------

NAME		=	hello_brain
DESCRIPTION =	Piscine CPP, Day 01 - ex02

# ----------- COMPILER FLAGS -------

CC			=	c++
CFLAGS		+=	-Wall -Wextra -Werror -g3 -std=c++98

# ----------- FILES ----------------

SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

# ----------- COLORS ---------------

BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
PURPLE		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
BLUE		= \033[0;34m
EOC			= \033[0;0m

# ----------- RULES ----------------

all			: $(NAME)

${NAME}		: $(OBJS)
	@echo "$(BLUE) =========> Compiling object files <========="
	@echo "$(WHITE)"
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 
	@echo "$(BLUE) =====> Build $(DESCRIPTION) DONE √ <====="
	@echo -n "$(EOC)"

.c.o:
	@echo -n "$(PURPLE)"
		$(CC) $(CFLAGS) -c $< -o $@

clean		:
	@echo "$(BLUE) =========> Deleting object files <========="
	@echo "$(PURPLE)"
		$(RM) $(OBJS)

fclean		: clean
	@echo "$(BLUE) =========> Deleting executable <========="
	@echo "$(PURPLE)"
		$(RM) $(NAME)

re			: fclean all bonus

.PHONY: all clean fclean re