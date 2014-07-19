CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf bfs

bfs: bfs.cpp
	$(COMPILER) $(CFLAGS) bfs.cpp -o bfs
