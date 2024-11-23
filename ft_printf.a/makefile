NAME = ft_printf.a

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER = ft_printf.h

CC = cc

SRC = ft_printf.c print_char.c print_digit.c print_hexa.c print_ptr_hexa.c print_str.c print_unsigned.c\

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ) ${HEADER}
	@ar rc $(NAME) $(OBJ)
	@echo "TOUT EST MAKE"

%.o:%.c ${HEADER}
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)
	@echo "TOUT EST CLEAN"

re : fclean $(NAME)
