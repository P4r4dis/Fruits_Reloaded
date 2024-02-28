G++           = g++
#############################################
TEST_SRC_PATH = ./source
TEST_INC_PATH = ./include
TEST_BIN_PATH = ./bin
TEST_SRC      = $(TEST_SRC_PATH)/Fruit.cpp \
				$(TEST_SRC_PATH)/Lemon.cpp \
				$(TEST_SRC_PATH)/Banana.cpp
# $(TEST_SRC_PATH)/FruitBox.cpp

NAME          = test_Ex0
#############################################

INCFLAGS     += -I$(TEST_INC_PATH)
CRITFLAGS    +=  --coverage -lcriterion
CPPFLAGS     += -Wall -Wextra -Werror $(INCFLAGS) $(CRITFLAGS) -W -std=c++23 -Wfatal-errors -g

SRCS         = $(TEST_BIN_PATH)/test_main.cpp \
               $(TEST_SRC)

OBJS         = $(SRCS:.cpp=.o)
OBJS_GCDA    = $(SRCS:.cpp=.gcda)
OBJS_GCNO    = $(SRCS:.cpp=.gcno)
COVERAGE	 = ../../coverage.* 

all: $(NAME)

$(NAME): $(OBJS)
	$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM = rm -rf

clean:
	$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO) $(COVERAGE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re