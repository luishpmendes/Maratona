CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf dfs

dfs: dfs.cpp
	$(COMPILER) $(CFLAGS) dfs.cpp -o dfs
