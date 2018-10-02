PROG = train 
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o Engine.o Fire.o Flick.o Game.o map.o Space.o validate.o
SRCS = main.cpp Engine.cpp Fire.cpp Flick.cpp Game.cpp map.cpp Space.cpp validate.cpp

HEADERS = Engine.hpp Fire.hpp Flick.hpp Game.hpp map.hpp Space.hpp validate.hpp

${PROG}: ${OBJS}
	${CXX} ${OBJS} -o ${PROG}

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ${PROG}