# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:59:50 by cemenjiv          #+#    #+#              #
#    Updated: 2022/06/15 15:34:36 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long  #nom de l'executable que l'on veut creer 

SRCS			= srcs/main.c

HEADER			= -Iinclude/ # I means "include" the file name include. If file was named "dir" than it would be -Idir/
				  	  
OBJS			= $(SRCS:.c=.o) # This line means take the variable {SRCS} which is a string composed of words separated by space. For each words separate suffix .c by .o

CC				= gcc  #name of C compiler
CFLAGS			= -Wall -Wextra -Werror -g  #nom des differents flags a utiliser 
RM				= rm -f  #shortcut Rm fait ce que fait normalement rm -f 

# $< means the first prerequisite.  
.c.o:		
				gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o) 
	
all:			$(NAME)  #commande all cree le target suivant $NAME. Il va creer un fichier qui va creer toutes les instructions qui sont sous ${NAME}

##-L libft means looks in directory "libft" for library files, then "-l" means links with library file that ends with ft (Ex: libft) and create a object file called NAME
# make bonus -C means make the bonus rule of Makefile that can be found in directory called "libft"
$(NAME):		$(OBJS)  #Convertis tous les fichiers sources (.c) and fichier objet (.o)
				$(MAKE) bonus -C ./libft 
				$(CC) ${OBJS} -L libft -l ft -o ${NAME} 

				
clean:		    # This does not create a target as the instructions are below. We only mention the different steps to do 
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS)
				
fclean:			clean #the target is do the instructions under clean and then the instruction below. 
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)
				
re:				fclean all #does the instruction of "fclean", which are to remove everything and then does the instructions of "all"
				

