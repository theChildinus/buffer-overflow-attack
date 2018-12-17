make
objdump -s -d stack > stackdump
#scp stack.s kong@10.108.165.178:/home/kong/JavaMemory/volatility-2.6/objfile/
sudo sysctl -w kernel.randomize_va_space=0
scp stackdump kong@10.108.165.178:/home/kong/JavaMemory/volatility-2.6/objfile/
