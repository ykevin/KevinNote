
.PHONY:clean

CC = g++ -std=c++11
CFLAGS = -ljsoncpp

EXE = json
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(EXE):$(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)
%.o:%.cpp
	$(CC) -o $@ -c $^ 

clean:
	rm -rf $(OBJS) $(EXE)


