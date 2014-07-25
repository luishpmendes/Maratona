CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf bellmanFord

bellmanFord: bellmanFord.cpp
	$(COMPILER) $(CFLAGS) bellmanFord.cpp -o bellmanFord
