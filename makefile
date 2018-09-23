CXXFLAGS = -std=c++11
LIBS = -lGL -lglut -lGLU
mloader: main.cpp gameloop.cpp camera.cpp draw.cpp obj.cpp
	$(CXX) $(CXXFLAGS) main.cpp gameloop.cpp camera.cpp draw.cpp obj.cpp -I. -o $@ $(LIBS)
