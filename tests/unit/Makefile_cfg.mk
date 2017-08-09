NAME = test.out
RENDU_PATH = ../..
FRAMEWORK_PATH = ../../../moulitest/testframework/v3
CC_LIBS = -lncurses -lft -L $(RENDU_PATH)/libft -I $(RENDU_PATH)/libft/incs -L $(RENDU_PATH)
CONFIG_EXTRA_H = -I $(RENDU_PATH)/libft/incs
RENDU_SOURCE = $(shell find $(RENDU_PATH)/srcs -name '*.c' -type f)
RENDU_MAKE_ARG = -lncurses
