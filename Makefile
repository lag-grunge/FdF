NAME = fdf

SRCS = main.c input.c model.c \
		proj_utils.c projection.c \
		params.c \
		render.c  primitives.c color.c \
		free_map.c destroy.c \
		dot_cross.c plus_minus_inplace.c max_size.c \
		iter.c init.c copy_reset.c \
		key_button.c \
		change_camera.c rotation.c zoom.c translate.c

HEADER = fdf.h

OBJS = ${SRCS:.c=.o}

OS = $(shell uname -s)

SCREEN_WIDTH = 2048
SCREEN_HEIGHT = 1152

MLX_DIR = .
LIBFT = libft.a
LIBFT_DIR = ./libft

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
TEST_LINKS = https://projects.intra.42.fr/uploads/document/document/4909/maps.zip

ifeq ($(OS), Darwin)
MLX = libmlx.a
LIBRARIES = ${MLX_DIR}/${MLX} ${LIBFT_DIR}/${LIBFT}
FRAMEWORK = -framework OpenGl -framework Appkit
INCLUDE = -I/opt/X11/inlcude/X11 -I${LIBFT_DIR} -I../minilibx
CFLAGS += -DMACOS
endif
ifeq ($(OS), Linux)
MLX = libmlx_Linux.a
LIBRARIES = ${MLX_DIR}/${MLX} ${LIBFT_DIR}/${LIBFT} -L/usr/lib -lXext -lX11 -lm -lz 
INCLUDE = -I${LIBFT_DIR} -I/usr/include
CFLAGS += -DLINUX
endif

all : ${LIBFT} ${NAME}

${LIBFT} : ${LIBFT_DIR}
	make -C $^

${NAME} : ${OBJS}
	${CC} ${CFLAGS} $^ ${LIBRARIES} ${FRAMEWORK} -o $@

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -DSCREEN_WIDTH=${SCREEN_WIDTH} -DSCREEN_HEIGHT=${SCREEN_HEIGHT} -o $@

launch_tests : ${NAME}
	curl -L ${TEST_LINKS} --output maps.zip
	unzip -j maps.zip  -x __MACOSX/*/* -d maps
	for i in $(addprefix maps/,$(shell ls maps)); do echo $$i; ./${NAME} $$i; done
	rm -rf maps maps.zip

clean :
	make clean -C ${LIBFT_DIR}
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${LIBFT}
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re launch_tests
