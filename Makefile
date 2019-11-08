test: test_bowling.h bowling.cpp
	clear
	cxxtestgen --error-printer -o runner.cpp test_bowling.h
	g++ -o runner -I$CXXTEST runner.cpp	bowling.cpp
	./runner
