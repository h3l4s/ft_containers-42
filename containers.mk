all:
	@echo -n "building our vector\r"
	@make -f our_vector.mk
	@sleep 0.2
	@echo -n "building real vector\r"
	@make -f real_vector.mk
	@sleep 0.2
	@echo -n "building our map\r"
	@make -f our_map.mk
	@sleep 0.2
	@echo -n "building real map\r"
	@make -f real_map.mk
	@sleep 0.2
	@echo -n "building our stack\r"
	@make -f our_stack.mk
	@sleep 0.2
	@echo -n "building real stack\r"
	@make -f real_stack.mk

clean:
	@echo -n "                                               \r"
	@echo -n "♻  Cleaning: our vector objects  ♻"
	@make clean -f our_vector.mk
	@sleep 0.3
	@echo -n "                                               \r"
	@echo -n "♻  Cleaning: real vector objects  ♻"
	@make clean -f real_vector.mk
	@echo -n "                                               \r"
	@echo -n "♻  Cleaned objects  ♻"
	@sleep 0.3
	@echo -n "                                               \r"
	@echo -n "♻  Cleaning: our map objects  ♻"
	@make clean -f our_map.mk
	@echo -n "                                               \r"
	@echo -n "♻  Cleaned objects  ♻"
	@sleep 0.3
	@echo -n "                                               \r"
	@echo -n "♻  Cleaning: real map objects  ♻"
	@make clean -f real_map.mk
	@echo -n "                                               \r"
	@echo -n "♻  Cleaned objects  ♻"
	@sleep 0.3
	@echo -n "                                               \r"
	@echo -n "♻  Cleaning: our stack objects  ♻"
	@make clean -f our_stack.mk
	@echo -n "                                               \r"
	@echo -n "♻  Cleaned objects  ♻"
	@sleep 0.3
	@echo -n "                                               \r"
	@echo -n "♻  Cleaning: real stack objects  ♻"
	@make clean -f real_stack.mk
	@echo -n "                                               \r"
	@echo -n "♻  Cleaned objects  ♻"

fclean: clean
		@echo -n "                                               \r"
		@echo -n "♻  Cleaning: our vector  ♻"
		@make fclean -f our_vector.mk
		@sleep 0.3
		@echo -n "                                               \r"
		@echo -n "♻  Cleaning: real vector  ♻"
		@make fclean -f real_vector.mk
		@echo -n "                                               \r"
		@echo -n "♻  Cleaned everything  ♻"
		@sleep 0.3
		@echo -n "                                               \r"
		@echo -n "♻  Cleaning: our map  ♻"
		@make fclean -f our_map.mk
		@echo -n "                                               \r"
		@echo -n "♻  Cleaned everything  ♻"
		@sleep 0.3
		@echo -n "                                               \r"
		@echo -n "♻  Cleaning: real map  ♻"
		@make fclean -f real_map.mk
		@echo -n "                                               \r"
		@echo -n "♻  Cleaned everything  ♻"
		@sleep 0.3
		@echo -n "                                               \r"
		@echo -n "♻  Cleaning: our stack  ♻"
		@make fclean -f our_stack.mk
		@echo -n "                                               \r"
		@echo -n "♻  Cleaned everything  ♻"
		@sleep 0.3
		@echo -n "                                               \r"
		@echo -n "♻  Cleaning: real stack  ♻"
		@make fclean -f real_stack.mk
		@echo -n "                                               \r"
		@echo -n "♻  Cleaned everything  ♻"

re: fclean all

test: re
	@echo "=========TESTING REAL VECTOR========="
	@echo "execution duration: "
	@time ./real_vector
	@echo "results in output1 file"
	@echo "=========TESTING OUR VECTOR=========\n"
	@echo "execution duration: "
	@time ./our_vector
	@echo "results in output2 file"
	@echo "=========DIFF=========\n"
	diff output1 output2
	@echo ""
	@echo "=========TESTING REAL MAP========="
	@echo "execution duration: "
	@time ./real_map
	@echo "results in output3 file"
	@echo "=========TESTING OUR MAP=========\n"
	@echo "execution duration: "
	@time ./our_map
	@echo "results in output4 file"
	@echo "=========DIFF=========\n"
	diff output3 output4
	@echo ""
	@echo "=========TESTING REAL STACK========="
	@echo "execution duration: "
	@time ./real_stack
	@echo "results in output3 file"
	@echo "=========TESTING OUR STACK=========\n"
	@echo "execution duration: "
	@time ./our_stack
	@echo "results in output4 file"
	@echo "=========DIFF=========\n"
	diff output5 output6

.PHONY: all clean fclean re test