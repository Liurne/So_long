# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 17:47:33 by jcoquard          #+#    #+#              #
#    Updated: 2024/04/23 16:18:08 by jcoquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $@ : NAME de la regle
# $^ : tous les OBJS
# $< : premiere dependance

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		= so_long

LIBMLX		= libmlx.a

# ---- Directories ---- #

DIR_OBJS		= .objs/

DIR_SRCS		= src/

DIR_UTILS		= ${DIR_SRCS}utils/

DIR_CORE		= ${DIR_SRCS}core/

DIR_RENDERER	= ${DIR_SRCS}renderer/

DIR_EVENT		= ${DIR_SRCS}event/

DIR_PARS		= ${DIR_SRCS}parsing/

DIR_MAP			= ${DIR_SRCS}map/

DIR_ENTITY			= ${DIR_SRCS}entity/

DIR_MLX			= minilibx/

DIR_LST			= ${DIR_UTILS}list/

MLXLIB_A 		= $(DIR_MLX)$(LIBMLX)

# ---- Colors ---- #

GREY		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
ORANGE		= \033[33m
BLUE		= \033[34m
PURPLE		= \033[35m
LIGHTBLUE	= \033[36m
WHITE		= \033[37m
IRED		= \033[41m
IWHITE		= \033[47m
IBLUE		= \033[44m
IPURPLE		= \033[45m
END			= \033[0m

# ---- Files ---- #

HEADER	= incl/

SRCS	=	$(DIR_SRCS)main.c \
			$(DIR_UTILS)ft_bzero.c \
			$(DIR_UTILS)ft_calloc.c \
			$(DIR_UTILS)ft_itoa.c \
			$(DIR_UTILS)ft_putmove_fd.c\
			$(DIR_UTILS)ft_putnbr_fd.c \
			$(DIR_UTILS)ft_putstr_fd.c \
			$(DIR_UTILS)ft_strber.c \
			$(DIR_UTILS)ft_strdup.c \
			$(DIR_UTILS)ft_strjoin.c \
			$(DIR_UTILS)ft_strlen.c \
			$(DIR_UTILS)ft_vec.c \
			$(DIR_UTILS)ft_rect.c \
			$(DIR_CORE)window.c \
			$(DIR_CORE)image.c \
			$(DIR_CORE)load_img.c \
			$(DIR_CORE)load_map_img.c \
			$(DIR_CORE)destroy_img.c \
			$(DIR_PARS)load_map.c \
			$(DIR_PARS)parsing_utils.c \
			$(DIR_PARS)parsing.c \
			$(DIR_RENDERER)display.c \
			$(DIR_RENDERER)display_entity.c \
			$(DIR_RENDERER)display_utils.c \
			$(DIR_EVENT)keyboard.c \
			$(DIR_EVENT)process.c \
			$(DIR_ENTITY)entity.c \
			$(DIR_ENTITY)init_entity.c \
			$(DIR_ENTITY)player.c \
			$(DIR_ENTITY)dog.c \
			$(DIR_ENTITY)bad.c \
			$(DIR_MAP)map.c \
			$(DIR_MAP)map_img.c \
			$(DIR_MAP)map_img_border.c \
			$(DIR_MAP)map_border_utils.c \


OBJS = ${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

DEPS = ${SRCS:%.c=${DIR_OBJS}%.d}

# ---- Compilation ---- #

DEPS_FLAGS	= -MMD -MP

CC			= cc

CFLAGS		= ${DEPS_FLAGS} -Wall -Wextra -Werror -g3 -fsanitize=address #-O2

# ---- Commands ---- #

RM		= rm -rf
MKDIR	= mkdir -p

# ********* RULES ******** #

all		: ${NAME}

$(LIBFT_A):	force
	@ ${MAKE} ${LIBFT} -C -j4

$(MLXLIB_A): force
	@ ${MAKE} ${LIBMLX} -C ${DIR_MLX} -j4

.PHONY:	all clean fclean re fclean_lib fclean_all force sus

# ---- Variables Rules ---- #

${NAME}	:	${OBJS}
			@ ${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_MLX} -lmlx_Linux -L/usr/lib -Iminilibx -lXext -lX11 -lm -lz && echo "${GREEN}\n* ${NAME} compilation completed !!!\n${END}" || ${MAKE} sus

# ---- Compiled Rules ---- #

-include ${DEPS}

${DIR_OBJS}%.o	:	%.c $(MLXLIB_A)
					@ $(MKDIR) $(shell dirname $@)
					@ ${CC} ${CFLAGS}  -c $< -o $@ -I ${DIR_MLX} -Iminilibx -I $(HEADER) && echo "  $@" || ${MAKE} sus

# ---- Usual Commands ---- #

fclean_lib		:
					make clean -C ${DIR_MLX}

clean			:
					@ ${RM} ${DIR_OBJS}  && echo "${RED} * clean: object cleared...${END}"

fclean			:	clean fclean_lib
					@ ${RM} ${NAME} && echo "${RED} * fclean: ${NAME} is cleared...${END}"

bonus			:	all

re				:	fclean
					$(MAKE)

sus:
	@echo "${RED}           ⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀        ${END}"
	@echo "${RED}        ⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀     ${END}"
	@echo "${RED}        ⣼⣿⠋       ${WHITE}⢀⣀⣀${RED}⠈⢻⣿⣿⡄    ${END}"
	@echo "${RED}       ⣸⣿⡏   ${WHITE}⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄   ${END}"
	@echo "${RED}       ⣿⣿⠁  ${WHITE}⢰⣿⣿⣯⠁       ⠈⠙⢿⣷⡄ ${END}"
	@echo "${RED}  ⣀⣤⣴⣶⣶⣿⡟   ${WHITE}⢸⣿⣿⣿⣆          ⣿⣷ ${END}"
	@echo "${RED} ⢰⣿⡟⠋⠉⣹⣿⡇   ${WHITE}⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿ ${END}"
	@echo "${RED} ⢸⣿⡇  ⣿⣿⡇    ${WHITE}⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃ ${END}"
	@echo "${RED} ⣸⣿⡇  ⣿⣿⡇     ${WHITE}⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛${RED}⢻⣿⡇  ${END}"
	@echo "${RED} ⠸⣿⣧⡀ ⣿⣿⡇                ⣿⣿⠃  ${END}"
	@echo "${RED}  ⠛⢿⣿⣿⣿⣿⣇     ⣰⣿⣿⣷⣶⣶⣶⣶⠶ ⢠⣿⣿   ${END}"
	@echo "${RED}       ⣿⣿     ⣿⣿⡇ ⣽⣿⡏⠁  ⢸⣿⡇   ${END}"
	@echo "${RED}       ⣿⣿     ⣿⣿⡇ ⢹⣿⡆   ⣸⣿⠇   ${END}"
	@echo "${RED}       ⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁ ⠈⠻⣿⣿⣿⣿⡿⠏    ${END}"
	@echo "${RED}       ⠈⠛⠻⠿⠿⠿⠿⠋⠁              ${END}"
	@echo "$(IRED)         ░█▀▀░█░█░█▀▀         ${END}"
	@echo "$(IRED)         ░▀▀█░█░█░▀▀█         ${END}"
	@echo "$(IRED)         ░▀▀▀░▀▀▀░▀▀▀         ${END}"

.SILENT:
.PHONY: all clean fclean fclean_lib re sus dir run