PWD = $(shell pwd)

all: libwideC.so

libwideC.so: libwideC.so.1.0.1
	ln -s libwideC.so.1.0.1 libwideC.so

libwideC.so.1.0.1: w_list.o w_node.o w_queue.o w_stack.o w_tree.o w_vector.o
	gcc -shared -Wl,-soname,libwideC.so.1 -o libwideC.so.1.0.1 w_list.o w_node.o w_queue.o w_stack.o w_tree.o w_vector.o -lc

w_vector.o: src/w_vector.c
	gcc -c -g -fPIC src/w_vector.c -o w_vector.o

w_tree.o: src/w_tree.c
	gcc -c -g -fPIC src/w_tree.c -o w_tree.o

w_stack.o: src/w_stack.c
	gcc -c -g -fPIC src/w_stack.c -o w_stack.o

w_queue.o: src/w_queue.c
	gcc -c -g -fPIC src/w_queue.c -o w_queue.o

w_node.o: src/w_node.c
	gcc -c -g -fPIC src/w_node.c -o w_node.o

w_list.o: src/w_list.c
	gcc -c -g -fPIC src/w_list.c -o w_list.o
	
clean:
	rm -rf *.o
	
install:
 	LD_LIBRARY_PATH = $LD_LIBRARY_PATH:$PWD
	#cp libjC.so /lib/
	#cp include/*.h /usr/include/