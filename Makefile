all: avltree

avltree:	main.o avlnode.o avltree.o
	g++ -o avltree main.o avlnode.o avltree.o

main.o:	main.cpp avlnode.h avltree.h
	g++ -c main.cpp

avlnode.o:	avlnode.cpp avlnode.h
	g++ -c avlnode.cpp

avltree.o:	avltree.cpp avltree.h
	g++ -c avltree.cpp

clear:
	rm *.o avltree
