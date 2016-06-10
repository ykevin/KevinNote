
.PHONY:clean

CXX = g++
CXXFLAGS = -g -Wall -O0 -std=c++11

EXE = time
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(EXE) : $(OBJS)
	$(CXX) -o $(EXE) $(OBJS)  $(CXXFLAGS)
%.o : %.cpp
	$(CXX) -o $@ -c $<

clean:
	rm -rf $(EXE) $(OBJS)
