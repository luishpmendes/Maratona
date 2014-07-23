CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf stronglyConnectedComponents

stronglyConnectedComponents: stronglyConnectedComponents.cpp
	$(COMPILER) $(CFLAGS) stronglyConnectedComponents.cpp -o stronglyConnectedComponents
