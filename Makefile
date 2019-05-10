
all: $(OUTPUT)
	make -C asm/ all
	make -C corewar/ all

clean: $(OUTPUT)
	make -C asm/ clean
	make -C corewar/ clean

fclean: $(OUTPUT)
	make -C asm/ fclean
	make -C corewar/ fclean

re: $(OUTPUT)
	make -C asm/ re
	make -C corewar/ re

.PHONY: all clean fclean re
