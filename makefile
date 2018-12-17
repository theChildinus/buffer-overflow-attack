all:
	gcc -o stack -z execstack -fno-stack-protector stack.c
	gcc -o exploit exploit.c
	gcc -o setuid set_uid_root.c
