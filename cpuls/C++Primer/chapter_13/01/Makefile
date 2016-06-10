
.PHONY:clean

CXX = g++
CXXFLAGS = -g -Wall -O0 -std=c++11
LDFLAGS = 

EXE = test
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(EXE) : $(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS) $(LDFLAGS)
%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean :
	rm -rf $(EXE) $(OBJS)

