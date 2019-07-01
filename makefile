CXX			= g++
CXXFLAGS = -std=c++14 -Wconversion -Wall -Werror -Wextra -pedantic

entity: entity.cpp enitity.h entity_test.cpp
	$(CXX) $(CXXFLAGS) -c entity.cpp
	$(CXX) $(CXXFLAGS) entity.o entity_test.cpp -o entity
	./entity
