# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 20:46:19 by tlegrand          #+#    #+#              #
#    Updated: 2023/09/19 22:24:17 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	PROJECT VARIABLES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#

#	==============================	NAMES	==============================	#
NAME		=	fixed

#	==============================	SOURCES	==============================	#
DIR_SRCS	=	srcs/
LST_SRCS	=	main.c
SRCS		=	${addprefix ${DIR_SRCS}, ${LST_SRCS}}



#	==============================	OBJECTS	==============================	#
DIR_OBJS	=	.objs/
LST_OBJS	=	${LST_SRCS:.c=.o}
OBJS		=	${addprefix ${DIR_OBJS}, ${LST_OBJS}} 


#	==============================	HEADERS	==============================	#
DIR_HEADER	=	include/
LST_HDR		=	${NAME}.h
HEADER		=	${addprefix ${DIR_HEADER}, ${LST_HDR}}


#	==============================	COMMANDS	==============================	#
CC 			=	cc 
MKDIR 		=	mkdir -p
RM			=	rm -rf
MAKE		=	make -s


#	==============================	FLAGS	==============================	#
CFLAGS		=	-Wall -Wextra #-Werror
DFLAGS		=	-g3 -fsanitize=address -fsanitize=leak -fsanitize=pointer-subtract -fsanitize=pointer-compare -fsanitize=undefined 



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	RULES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#
.PHONY : all clean fclean re  nn

#	==============================	BASIC	==============================	#
all		:	${NAME}

clean	:
		@${RM} ${DIR_OBJS}

fclean	:	clean
		@${RM} ${NAME} ${NAME_B}
		@printf "$(GREEN)All clean !\n$(END)"

re		:	fclean
		@${MAKE} all


#	==============================	COMPILATION	==============================	#
${NAME}			:	${DIR_OBJS} ${OBJS}
				@${CC} -I${DIR_HEADER} ${CFLAGS} ${OBJS} libft.a -o ${NAME} 
				@printf "$(GREEN_LIGHT)$@ created !\n$(END)"


${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADER}
				@printf "$(YELLOW)Making $@...\n$(END)"
				@${CC} ${CFLAGS} -c $< -o $@



#	==============================	UTILS/LIB	==============================	#
debug		:	clean_p
			@${MAKE} DEBUG=base ${NAME}


nn			:
			@norminette $(sort  ${HEADER} ${DIR_SRCS} )
		
${DIR_OBJS}	:
			@${MKDIR} ${DIR_OBJS}srcs



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	OPERATING VARIABLES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#

#	==============================	COLORS	==============================	#
BLACK		=	\033[0;30m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
PURPLE		=	\033[0;35m
CYAN		=	\033[0;36m
GRAY_LIGHT	=	\033[0;37m
GRAY_DARK	=	\033[1;30m
RED_LIGHT	=	\033[1;31m
GREEN_LIGHT	=	\033[1;32m
YELLOW 		=	\033[1;33m
BLUE_LIGHT	=	\033[1;34m
VIOLET		=	\033[1;35m
CYAN		=	\033[1;36m
WHITE		=	\033[1;37m
END			=	\033[0m
BOLD		=	\033[1m
FAINT		=	\033[2m
ITALIC		=	\033[3m
UNDERLINE	=	\033[4m
BLINK_SLOW	=	\033[5m
BLINK_FAST	=	\033[6m
BLINK_OFF	=	\033[25m
REV_V		=	\033[7m
CONCEAL		=	\033[8m
CONCEAL_OFF	=	\033[28m
CROSS_OUT	=	\033[9m
CROSS_OUT_O	=	\033[29m
ERASE		=	\033[2K
RERASE		=	\r\033[2K
