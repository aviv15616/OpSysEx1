# Build all executables , add -ggdb for debug flags
all: div_by_zero ndef_mem_acc stack_overflow


div_by_zero: div_by_zero.c 
	gcc -o $@ $< -ggdb

ndef_mem_acc: ndef_mem_acc.c
	gcc -o $@ $< -ggdb

stack_overflow: stack_overflow.c
	gcc -o $@ $< -ggdb


# Remove compiled executables 
clean:
	rm -f div_by_zero ndef_mem_acc stack_overflow 

.PHONY: all clean
