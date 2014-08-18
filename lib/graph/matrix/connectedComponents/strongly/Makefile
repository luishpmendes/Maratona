CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf stronglyConnectedComponents stronglyConnectedComponents2

stronglyConnectedComponents: stronglyConnectedComponents.cpp
	$(COMPILER) $(CFLAGS) stronglyConnectedComponents.cpp -o stronglyConnectedComponents

stronglyConnectedComponents2: stronglyConnectedComponents2.cpp
	$(COMPILER) $(CFLAGS) stronglyConnectedComponents2.cpp -o stronglyConnectedComponents2
