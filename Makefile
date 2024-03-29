G++						=	g++
###############################################
EX0_PATH 				= 	./Ex0_Fruit
EX0_SRC_PATH			=	./Ex0_Fruit/source
EX0_TST_PATH			=	./Ex0_Fruit/test
EX0_INC_PATH			=	./Ex0_Fruit/include
NAME_EX0				=	Ex0
# EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

EX0_SRC_TEST			=	$(EX0_TST_PATH)/$(NAME_EX0)_test.cpp
TEST_NAME_EX0 			= 	test_$(NAME_EX0)

# #################################################
EX1_PATH 				= 	./Ex1_More
EX1_SRC_PATH			=	./Ex1_More/source
EX1_TST_PATH			=	./Ex1_More/test
EX1_INC_PATH			=	./Ex1_More/include
NAME_EX1				=	Ex1
# EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

EX1_SRC_TEST			=	$(EX1_TST_PATH)/$(NAME_EX1)_test.cpp
TEST_NAME_EX1 			= 	test_$(NAME_EX1)

# #################################################
EX2_PATH 				= 	./Ex2_Eat
EX2_SRC_PATH			=	./Ex2_Eat/source
EX2_TST_PATH			=	./Ex2_Eat/test
EX2_INC_PATH			=	./Ex2_Eat/include
NAME_EX2				=	Ex2
# EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

EX2_SRC_TEST			=	$(EX2_TST_PATH)/$(NAME_EX2)_test.cpp
TEST_NAME_EX2 			= 	test_$(NAME_EX2)

# #################################################
EX3_PATH 				= 	./Ex3_Mix
EX3_SRC_PATH			=	./Ex3_Mix/source
EX3_TST_PATH			=	./Ex3_Mix/test
EX3_INC_PATH			=	./Ex3_Mix/include
NAME_EX3				=	Ex3
# EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

EX3_SRC_TEST			=	$(EX3_TST_PATH)/$(NAME_EX3)_test.cpp
TEST_NAME_EX3 			= 	test_$(NAME_EX3)

# #################################################
EX4_PATH 				= 	./Ex4_Help
EX4_SRC_PATH			=	./Ex4_Help/source
EX4_TST_PATH			=	./Ex4_Help/test
EX4_INC_PATH			=	./Ex4_Help/include
NAME_EX4				=	Ex4
# EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

EX4_SRC_TEST			=	$(EX4_TST_PATH)/$(NAME_EX4)_test.cpp
TEST_NAME_EX4 			= 	test_$(NAME_EX4)

# #################################################
# EX5_PATH 				= 	./Ex5_ICharacter
# EX5_SRC_PATH			=	./Ex5_ICharacter/source
# EX5_TST_PATH			=	./Ex5_ICharacter/test
# EX5_INC_PATH			=	./Ex5_ICharacter/include
# NAME_EX5				=	Ex5
# # EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

# EX5_SRC_TEST			=	$(EX5_TST_PATH)/$(NAME_EX5)_test.cpp
# TEST_NAME_EX5 			= 	test_$(NAME_EX5)

# #################################################
# EX6_PATH 				= 	./Ex6_IPotion
# EX6_SRC_PATH			=	./Ex6_IPotion/source
# EX6_TST_PATH			=	./Ex6_IPotion/test
# EX6_INC_PATH			=	./Ex6_IPotion/include
# NAME_EX6				=	Ex6
# # EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

# EX6_SRC_TEST			=	$(EX6_TST_PATH)/$(NAME_EX6)_test.cpp
# TEST_NAME_EX6 			= 	test_$(NAME_EX6)

# #################################################
# OBJS					=	$(SRCS:.cpp=.o)
CLEAN					=	clean
FCLEAN					=	fclean
RM						=	rm -rf

clean					:	
							$(RM) $(OBJS)
							@$(MAKE) $(CLEAN) -C $(EX0_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(EX1_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(EX2_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(EX3_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(EX4_TST_PATH)

fclean					:	clean
							$(RM) $(NAME) $(TEST_NAME_EX0)
							$(RM) $(NAME) $(TEST_NAME_EX1)
							$(RM) $(NAME) $(TEST_NAME_EX2)
							$(RM) $(NAME) $(TEST_NAME_EX3)
							$(RM) $(NAME) $(TEST_NAME_EX4)
							@$(MAKE) $(FCLEAN) -C $(EX0_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX0_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX1_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX1_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX2_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX2_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX3_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX3_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX4_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX4_PATH)

re						: 	fclean all

Ex0 					: 	fclean
							@$(MAKE) -C $(EX0_PATH)
							$(EX0_PATH)/$(NAME_EX0)

Ex1 					: 	fclean
							@$(MAKE) -C $(EX1_PATH)
							$(EX1_PATH)/$(NAME_EX1)

Ex2 					: 	fclean
							@$(MAKE) -C $(EX2_PATH)
							$(EX2_PATH)/$(NAME_EX2)

Ex3 					: 	fclean
							@$(MAKE) -C $(EX3_PATH)
							$(EX3_PATH)/$(NAME_EX3)

Ex4 					: 	fclean
							@$(MAKE) -C $(EX4_PATH)
							$(EX4_PATH)/$(NAME_EX4)

test_run_Ex0			:	fclean
							@$(MAKE) -C $(EX0_TST_PATH)
							$(EX0_TST_PATH)/$(TEST_NAME_EX0)
							gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --txt --html-details coverage.html

test_run_Ex1			:	fclean
							@$(MAKE) -C $(EX1_TST_PATH)
							$(EX1_TST_PATH)/$(TEST_NAME_EX1)
							gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --txt --html-details coverage.html

test_run_Ex2			:	fclean
							@$(MAKE) -C $(EX2_TST_PATH)
							$(EX2_TST_PATH)/$(TEST_NAME_EX2)
							gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --txt --html-details coverage.html

test_run_Ex3			:	fclean
							@$(MAKE) -C $(EX3_TST_PATH)
							$(EX3_TST_PATH)/$(TEST_NAME_EX3)
							gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --txt --html-details coverage.html

test_run_Ex4			:	fclean
							@$(MAKE) -C $(EX4_TST_PATH)
							$(EX4_TST_PATH)/$(TEST_NAME_EX4)
							gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --txt --html-details coverage.html

tests_run				:	fclean
							@$(MAKE) test_run_Ex0
							@echo "Press Enter to continue to the next test (Ex1)..."
							@read dummy
							@$(MAKE) test_run_Ex1
							@echo "Press Enter to continue to the next test (Ex2)..."
							@read dummy
							@$(MAKE) test_run_Ex2
							@echo "Press Enter to continue to the next test (Ex3)..."
							@read dummy
							@$(MAKE) test_run_Ex3
							@echo "Press Enter to continue to the next test (Ex4)..."
							@read dummy
							@$(MAKE) test_run_Ex4
							@echo "=====END====="
 
.PHONY					: 	all clean fclean re \
							tests_run \
							Ex0 test_run_Ex0 \
							Ex1 test_run_Ex1 \
							Ex2 test_run_Ex2 \
							Ex3 test_run_Ex3 \
							Ex4 test_run_Ex4