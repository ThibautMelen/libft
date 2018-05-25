# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 16:42:14 by jroussel          #+#    #+#              #
#    Updated: 2018/05/25 18:37:06 by jroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
FLAGS   = -Wall -Wextra -Werror

SRCS    = ft_memset.c\
          ft_bzero.c\
          ft_memcpy.c\
          ft_memccpy.c\
          ft_memmove.c\
          ft_memchr.c\
          ft_memcmp.c\
          ft_memalloc.c\
          ft_memdel.c\
          ft_strlen.c\
          ft_strdup.c\
          ft_strcpy.c\
          ft_strncpy.c\
          ft_strcat.c\
          ft_strncat.c\
          ft_strlcat.c\
          ft_strchr.c\
          ft_strrchr.c\
          ft_strstr.c\
          ft_strnstr.c\
          ft_strcmp.c\
          ft_strncmp.c\
          ft_strnew.c\
          ft_strdel.c\
          ft_strclr.c\
          ft_striter.c\
          ft_strsub.c\
          ft_strjoin.c\
          ft_strjoinch.c\
          ft_strtrim.c\
          ft_strsplit.c\
          ft_strupper.c\
          ft_strlower.c\
          ft_strcapitalize.c\
          ft_lstnew.c\
          ft_lstdel.c\
          ft_lstlen.c\
          ft_lstadd.c\
          ft_lstaddi.c\
          ft_lstpush.c\
          ft_lstremove.c\
          ft_lstget.c\
          ft_lstiter.c\
		  ft_printf.c\
          ft_isblank.c\
          ft_islower.c\
          ft_isupper.c\
          ft_isalpha.c\
          ft_isdigit.c\
          ft_isalnum.c\
          ft_isascii.c\
          ft_isprint.c\
		  ft_isnumber.c\
          ft_atol.c\
          ft_ltoa.c\
          ft_ultoa_base.c\
          ft_ultoa.c\
          ft_toupper.c\
          ft_tolower.c\
          ft_gnl.c\
		  buffer.c\
          color.c\
          convert.c\
          format.c\
          output.c\
          parse.c\
          unicode.c\
          util.c\
          vars.c\
          func_s.c\
          func_ss.c\
          func_p.c\
          func_d.c\
          func_dd.c\
          func_i.c\
          func_o.c\
          func_oo.c\
          func_u.c\
          func_uu.c\
          func_x.c\
          func_xx.c\
          func_c.c\
          func_cc.c\
          func_percent.c\
          func_n.c\

SRCS   := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS    = $(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) 2> /dev/null
	gcc $(FLAGS) -I$(INC_DIR) -o $@ -c $<

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@chmod +x $(NAME)

all: $(NAME)
clean:
	@rm -rf $(OBJ_DIR)
fclean: clean
	@rm -f $(NAME)
re: fclean all
build: all clean
check: all fclean
