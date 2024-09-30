# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myevou <myevou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 11:49:51 by myevou            #+#    #+#              #
#    Updated: 2024/09/30 20:12:41 by myevou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

NAME			= cub3d

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #
CC			  = cc
RM			  = rm -rf
CFLAGS		  += -Wall -Wextra -Werror
CFLAGS		  += -g3 -MMD -MP

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #

INC_PATH		= includes
OBJ_PATH		= .obj

# **************************************************************************** #
#                                    FLAGS                                     #
# **************************************************************************** #

CFLAGS		  += -I$(INC_PATH)

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

# SYSTEM
SRCS			= $(addsuffix .c, \
				main )

# SRCS / MOVES
SRCS			+= $(addprefix srcs/moves/, $(addsuffix .c, \
				moves\
				keys ))

# SRCS / MAP
SRCS			+= $(addprefix srcs/map/, $(addsuffix .c, \
				map ))

# SRCS / RAYCASTING
SRCS			+= $(addprefix srcs/raycasting/, $(addsuffix .c, \
				draw \
				init \
				raycasting \
				utils ))

# SRCS / PARISING
SRCS			+= $(addprefix srcs/parsing/, $(addsuffix .c, \
				error_handling \
				map_check_utils \
				map_check \
				map_creat \
				map_playable \
				map_playable_utils \
				map_split \
				parsing \
				utils ))

OBJS			= $(SRCS:%.c=$(OBJ_PATH)/%.o)

DEPS			= $(OBJS:.o=.d)

# **************************************************************************** #
#                                     LIBS                                     #
# **************************************************************************** #

LDLIBS			=	-lft -lmlx_Linux -lXext -lX11 -lm -lz

# OS
OS				=	$(shell uname)

ifeq ($(OS), Darwin)
INCL_RDL_LIB    =   -L/usr/local/opt/readline/lib -lncurses
INCL_RDL_HEADER =   -I/usr/local/opt/readline/include
else
INCL_RDL_LIB    =   -L/Users/$(USER)/.linuxbrew/opt/readline/lib -lncurses
INCL_RDL_HEADER =   -I/Users/$(USER)/.linuxbrew/opt/readline/include
endif

# LIBFT
LIBFT_DIR		= libft
LIBFT_INC_PATH	= $(LIBFT_DIR)/includes
LIBFT			= $(LIBFT_DIR)/libft.a

# MINILIBX
MLX_DIR			= minilibx-linux
MLX_INC_PATH	= $(MLX_DIR)
MLX				= $(MLX_DIR)/libmlx_Linux.a

CFLAGS			+= -I$(LIBFT_INC_PATH) -I$(MLX_INC_PATH)

LDLIBS			+= -L$(LIBFT_DIR) -L$(MLX_DIR)

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all:			$(NAME)

$(NAME):		${OBJ_PATH} $(OBJS) $(LIBFT) $(MLX)
				@cd minilibx-linux && $(MAKE)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDLIBS) $(LIBFT)
				@echo "\n${GREEN}> $(NAME) was successfully compiled 🎉${END}"

$(LIBFT):
				@make -C $(LIBFT_DIR)

$(MLX):
				@make -C $(MLX_DIR)

$(OBJ_PATH):
				@mkdir -p ${OBJ_PATH}

$(OBJ_PATH)/%.o: %.c
				@mkdir -p $(dir $@)
				@printf "${BLUE}> Generating minishell objects... %-33.33s\r" $@
				@$(CC) $(CFLAGS) $(INCL_RDL_HEADER) -c $< -o $@

clean:
				@make clean -C $(LIBFT_DIR)
				@$(RM) $(OBJ_PATH)
				@echo "${YELLOW}> All objects files of $(NAME) have been deleted ❌${RESET}${END}"

fclean:		 clean
				@make fclean -C $(LIBFT_DIR)
				@$(RM) $(NAME)
				@echo "${YELLOW}> Cleaning of $(NAME) has been done ❌${RESET}${END}"

re:			 fclean
				make all

run:		$(NAME)
		@valgrind --suppressions=ignore.txt ./$(NAME)

#add -s in LIBFT clean fclean re to silence make[1] type msg
#e.g make -s all

-include $(DEPS)

.PHONY: all clean fclean re run

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

BLACK			=	\033[0;30m
BLUE			=	\033[0;34m
CYAN			=	\033[0;36m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
PURPLE			=	\033[0;35m
RED				=	\033[0;31m
WHITE			=	\033[1;37m
YELLOW			=	\033[1;33m
DARK_GRAY		=	\033[1;30m
LIGHT_GRAY		=	\033[0;37m
LIGHT_BLUE		=	\033[1;34m
LIGHT_RED		=	\033[1;31m
LIGHT_CYAN		=	\033[1;36m
LIGHT_GREEN		=	\033[1;32m
LIGHT_PURPLE	=	\033[1;35m
RESET			= 	\033[0m
