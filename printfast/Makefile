NAME = printfast.a

CC = gcc

INCLUDES = includes

SRCDIR = srcs

OBJDIR = objects

H = includes/printfast.h

CFLAGS = -Wall -Wextra -Werror

SRC = $(SRCDIR)/fill_buff.c $(SRCDIR)/ft_ltoa.c $(SRCDIR)/get_as.c $(SRCDIR)/get_s.c $(SRCDIR)/get_d.c $(SRCDIR)/get_c.c \
		$(SRCDIR)/get_width.c $(SRCDIR)/init_struct.c $(SRCDIR)/is_type.c $(SRCDIR)/printfast.c $(SRCDIR)/ret_type.c

OBJ= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): build $(OBJ)
	ar rcs libft/libft.a $(OBJ)
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

build:
	mkdir -p objects

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc -c -o $@ $< $(CFLAGS) -I$(INCLUDES)
