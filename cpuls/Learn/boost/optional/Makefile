.PHONY:clean

CC = g++
CXXFALGS = -g -Wall -O0 -std=c++11
LDFALGS = -lboost_signals -lboost_system -lboost_thread


EXE  = test
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CXXFALGS) $(LDFALGS)
%.o : %.cpp 
	$(CC) -o $@ -c $<  $(CXXFALGS)


clean:
	rm -rf $(EXE) $(OBJS) 

