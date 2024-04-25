# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 14:51:41 by ichpakov          #+#    #+#              #
#    Updated: 2024/04/24 04:01:27 by ichpakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norm comp

NAME = libft.a
MAIN = 

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRC_BOOL =	ft_isalnum.c		ft_isalpha.c		ft_isascii.c		ft_isdigit.c		ft_isprint.c	\

SRC_LST =	ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c		ft_lstdelone.c		ft_lstiter.c	\
			ft_lstlast.c		ft_lstmap.c			ft_lstnew.c			ft_lstsize.c

SRC_MEM =	ft_bzero.c			ft_calloc.c			ft_memchr.c			ft_memcmp.c			ft_memcpy.c		\
			ft_memmove.c		ft_memset.c			ft_free.c

SRC_PRINT =	ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c		ft_putchar_fd.c		

SRC_PROJ =	get_next_line.c

SRC_STR =	ft_toupper.c		ft_strchr.c			ft_split.c			ft_tolower.c		ft_substr.c		\
			ft_strdup.c			ft_striteri.c		ft_strjoin.c		ft_strlcat.c		ft_strlcpy.c	\
			ft_strlen.c			ft_strmapi.c		ft_strncmp.c		ft_strtrim.c		ft_strnstr.c	\
			ft_strstr.c			ft_strcmp.c			ft_ischarset.c		ft_int_strchr.c		ft_strnjoin.c

SRC_CONV =	ft_atoi.c			ft_itoa.c

SRC_ERROR =	ft_error.c

SRCS =	${addprefix lib_src/bool/,${SRC_BOOL}}	${addprefix lib_src/lst/,${SRC_LST}}		\
		${addprefix lib_src/mem/,${SRC_MEM}}	${addprefix lib_src/print/,${SRC_PRINT}}	\
		${addprefix lib_src/proj/,${SRC_PROJ}}	${addprefix lib_src/str/,${SRC_STR}}		\
		${addprefix lib_src/conv/,${SRC_CONV}}	${addprefix lib_src/error/,${SRC_ERROR}}	\

#//////////////////////////////////////////////////////////////////////////////
#		OBJ CREATION
#//////////////////////////////////////////////////////////////////////////////

OBJS = ${addprefix ${OBJP},${subst ${SRCP},/,${SRCS:.c=.o}}}

SRCP = lib_src/
OBJP = lib_obj
INCP = ./lib_includes/

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

CC = gcc
CF = -Wall -Wextra -Werror
CS = -g -fsanitize=address
CG = -g3

NCF = norminette -R CheckForbiddenSourceHeader
NCD = norminette -R CheckDefine

AR = ar rcs
RM = rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all: ${NAME}

# Binary creation

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}
	@echo ${NAME} complete

${OBJS}: ${OBJP}

${OBJP}:
	@mkdir ${OBJP}
	@mkdir	${OBJP}/bool/	${OBJP}/lst/	${OBJP}/mem/	\
			${OBJP}/print/	${OBJP}/proj/	${OBJP}/str/	\
			${OBJP}/conv/	${OBJP}/error/
	@echo creating obj directories

${OBJP}/%.o: ${SRCP}%.c ${INCP}libft.h
	${CC} ${CF} -c -o $@ $<

# Additional rules

norm:
	${NCF} ${SRCP}
	${NCD} ${INCP}

comp: ${SRCS} ${MAIN}
	${CC} ${CF} ${CS} $^
	${CC} ${CF} ${CG} $^

# Mandatory rules

clean:
	@${RM} ${OBJS}
	@echo all object files removed

fclean: clean
	@${RM} ${NAME} ${OBJP}
	@echo library removed

re: fclean all