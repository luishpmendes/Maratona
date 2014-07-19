CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf kruskal

kruskal: kruskal.cpp
	$(COMPILER) $(CFLAGS) kruskal.cpp -o kruskal
