CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = raiinet
OBJECTS = main.o Ability.o board.o Cell.o Download.o Firewall.o GameState.o GraphicalObserver.o Link.o subject.o Player.o position.o XWindow.o TextObserver.o Polarize.o BattleGod.o LinkBoost.o RussianRoulette.o Scan.o UnlimitedVoid.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}