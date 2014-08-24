CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf kosaraju kosaraju2

kosaraju: kosaraju.cpp
	$(COMPILER) $(CFLAGS) kosaraju.cpp -o kosaraju

kosaraju2: kosaraju2.cpp
	$(COMPILER) $(CFLAGS) kosaraju2.cpp -o kosaraju2
