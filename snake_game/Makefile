CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o snake.o

snake_game: $(OBJS)
	$(CXX) $(CXXFLAGS) -o snake_game $(OBJS)

main.o: main.cpp snake.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

snake.o: snake.cpp snake.hpp
	$(CXX) $(CXXFLAGS) -c snake.cpp

clean:
	rm -f *.o snake_game
