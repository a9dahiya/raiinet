CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = raiinet
OBJECTS = main.o Ability.o board.o cell.o observer.o Download.o Firewall.o GameState.o GraphicalObserver.o Link.o subject.o player.o position.o XWindow.o TextObserver.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}