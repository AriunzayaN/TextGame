CXX			= g++
CXXFLAGS = -std=c++14

.PHONY : clean

clean:
	rm -f *.exe
	
place: place.h place.cpp place_test.cpp clean
	$(CXX) $(CXXFLAGS) place.cpp place_test.cpp -o place.exe
	./place.exe

entity: place.h place.cpp entity.cpp entity.h entity_test.cpp clean
	$(CXX) $(CXXFLAGS) place.cpp entity.cpp entity_test.cpp -o entity.exe
	./entity.exe

entities: entity.cpp entity.h entities.cpp entities_test.cpp manager.h manager.cpp \
		 place.h place.cpp clean
	$(CXX) $(CXXFLAGS) entity.cpp entities.cpp manager.cpp place.cpp entities_test.cpp -o entities.exe
	./entities.exe

manager: manager.h manager.cpp entity.cpp entity.h entities.cpp \
		place.h place.cpp manager_test.cpp clean
	$(CXX) $(CXXFLAGS) entity.cpp entities.cpp place.cpp manager.cpp manager_test.cpp -o manager.exe
	./manager.exe
