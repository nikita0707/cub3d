NAME = cub3D

PARSDIR = parsing/

ENGIDIR = engine/

UTILDIR = utils/

HEADERS = headers/

LIBSDIR = libs/

DRAWDIR = draw/

SOURCES = cub3d.c \
		 $(ENGIDIR)move.c \
		 $(DRAWDIR)draw.c \
		 $(ENGIDIR)loop.c \
		 $(UTILDIR)save.c \
		 $(UTILDIR)utils.c \
		 $(UTILDIR)hooks.c \
		 $(DRAWDIR)walls.c \
		 $(UTILDIR)utils2.c \
		 $(ENGIDIR)sprite.c \
		 $(UTILDIR)errors.c \
		 $(UTILDIR)set_cub.c \
		 $(ENGIDIR)actions.c \
		 $(DRAWDIR)minimap.c \
		 $(UTILDIR)zero_cub.c \
		 $(DRAWDIR)simple_fc.c \
		 $(UTILDIR)clear_cub.c \
		 $(PARSDIR)check_map.c \
		 $(PARSDIR)parse_map.c \
		 $(DRAWDIR)draw_utils.c \
		 $(DRAWDIR)draw_hands.c \
		 $(ENGIDIR)raycasting.c \
		 $(PARSDIR)parse_config.c \
		 $(ENGIDIR)raycasting_hit.c \
		 $(UTILDIR)parse_config_utils.c

OSOURCE= $(SOURCES:.c=.o)

FLAGS = -Wall -Werror -Wextra

LLIBS = -L. $(LIBSDIR)libftl.a $(LIBSDIR)libmlxl.a -lXext -lX11 -lm -lpthread

MLIBS = -L $(LIBSDIR) -lftm -lmlxm -framework OpenGL -framework AppKit -lz -lm

all: $(NAME)
	
ifdef BONUS
%.o: %.c
	gcc -c $< $(FLAGS) -o $@ -I $(HEADERS) -D BONUS=1
else
%.o: %.c
	gcc -c $< $(FLAGS) -o $@ -I $(HEADERS) -D BONUS=0
endif

$(NAME): $(OSOURCE)
	gcc -o $(NAME) $(OSOURCE) $(MLIBS) -I $(HEADERS) -D MAC

bonus:
	@$(MAKE) BONUS=1 all


clean:
	@rm -rf $(OSOURCE)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all